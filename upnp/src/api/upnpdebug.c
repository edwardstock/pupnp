/*******************************************************************************
 *
 * Copyright (c) 2000-2003 Intel Corporation 
 * All rights reserved. 
 *
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted provided that the following conditions are met: 
 *
 * - Redistributions of source code must retain the above copyright notice, 
 * this list of conditions and the following disclaimer. 
 * - Redistributions in binary form must reproduce the above copyright notice, 
 * this list of conditions and the following disclaimer in the documentation 
 * and/or other materials provided with the distribution. 
 * - Neither name of Intel Corporation nor the names of its contributors 
 * may be used to endorse or promote products derived from this software 
 * without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR 
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL INTEL OR 
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, 
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, 
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR 
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY 
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS 
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ******************************************************************************/

/*!
 * \file
 */

#include "config.h"

#include "ithread.h"
#include "ixml.h"
#include "upnp.h"
#include "upnpdebug.h"

#include <libgen.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifdef DEBUG

/*! Mutex to synchronize all the log file opeartions in the debug mode */
static ithread_mutex_t GlobalDebugMutex;

/*! Global log level */
static Upnp_LogLevel g_log_level = UPNP_DEFAULT_LOG_LEVEL;

/*! File handle for the error log file */
static FILE *ErrFileHnd = NULL;

/*! File handle for the information log file */
static FILE *InfoFileHnd = NULL;

/*! Name of the error file */
static const char *errFileName = NULL;

/*! Name of the info file */
static const char *infoFileName = NULL;

int UpnpInitLog(void)
{
	ithread_mutex_init(&GlobalDebugMutex, NULL);
	if (DEBUG_TARGET == 1) {
		if ( errFileName && *errFileName && (ErrFileHnd = fopen(errFileName, "a")) == NULL) {
			return -1;
		}
		if (infoFileName && *infoFileName && (InfoFileHnd = fopen(infoFileName, "a")) == NULL) {
			return -1;
		}
	}
	return UPNP_E_SUCCESS;
}

void UpnpSetLogLevel(Upnp_LogLevel log_level)
{
	g_log_level = log_level;
}

void UpnpCloseLog(void)
{
	if (DEBUG_TARGET == 1) {
		if (ErrFileHnd) {
			fflush(ErrFileHnd);
			fclose(ErrFileHnd);
		}
		if (InfoFileHnd) {
			fflush(InfoFileHnd);
			fclose(InfoFileHnd);
		}
	}
	ithread_mutex_destroy(&GlobalDebugMutex);
}

void UpnpSetLogFileNames(const char *ErrFileName, const char *InfoFileName)
{
	if (errFileName) {
		free((void*)errFileName);
		errFileName = NULL;
	}
	if (ErrFileName) {
		errFileName = strdup(ErrFileName);
	}
	if (infoFileName) {
		free((void*)infoFileName);
		infoFileName = NULL;
	}
	if (InfoFileName) {
		infoFileName = strdup(InfoFileName);
	}
}

int DebugAtThisLevel(Upnp_LogLevel DLevel, Dbg_Module Module)
{
	int ret = DLevel <= g_log_level;
	ret &=
	    DEBUG_ALL ||
	    (Module == SSDP && DEBUG_SSDP) ||
	    (Module == SOAP && DEBUG_SOAP) ||
	    (Module == GENA && DEBUG_GENA) ||
	    (Module == TPOOL && DEBUG_TPOOL) ||
	    (Module == MSERV && DEBUG_MSERV) ||
	    (Module == DOM && DEBUG_DOM) || (Module == HTTP && DEBUG_HTTP);

	return ret;
	Module = Module; /* VC complains about this being unreferenced */
}

void UpnpPrintf(Upnp_LogLevel DLevel,
		Dbg_Module Module,
		const char *DbgFileName, int DbgLineNo, const char *FmtStr, ...)
{
	va_list ArgList;

	if (!DebugAtThisLevel(DLevel, Module))
		return;
	ithread_mutex_lock(&GlobalDebugMutex);
	va_start(ArgList, FmtStr);
	if (!DEBUG_TARGET) {
		if (DbgFileName)
			UpnpDisplayFileAndLine(stdout, DbgFileName, DbgLineNo);
		vfprintf(stdout, FmtStr, ArgList);
		fflush(stdout);
	} else {
		if (ErrFileHnd && DLevel == UPNP_CRITICAL) {
			if (DbgFileName) {
				UpnpDisplayFileAndLine(ErrFileHnd, DbgFileName,
						       DbgLineNo);
			}
			vfprintf(ErrFileHnd, FmtStr, ArgList);
			fflush(ErrFileHnd);
		}
		if (InfoFileHnd) {
			if (DbgFileName) {
				UpnpDisplayFileAndLine(InfoFileHnd, DbgFileName,
						       DbgLineNo);
			}
			vfprintf(InfoFileHnd, FmtStr, ArgList);
			fflush(InfoFileHnd);
 		}
	}
	va_end(ArgList);
	ithread_mutex_unlock(&GlobalDebugMutex);
}

FILE *UpnpGetDebugFile(Upnp_LogLevel DLevel, Dbg_Module Module)
{
	FILE *ret;

	if (!DebugAtThisLevel(DLevel, Module))
		ret = NULL;
	if (!DEBUG_TARGET)
		ret = stdout;
	else if (DLevel == UPNP_CRITICAL)
		ret = ErrFileHnd;
	else
		ret = InfoFileHnd;

	return ret;
}

void UpnpDisplayFileAndLine(FILE *fd, const char *DbgFileName, int DbgLineNo)
{
	time_t timenow = time(NULL);
	struct tm localtimenow;
	char timeprint[20];	/* "YYYY-MM-DD HH:MM:SS" */

	localtime_r(&timenow, &localtimenow);
	strftime(timeprint, sizeof(timeprint), "%F %T", &localtimenow);
	fprintf(fd, "%s 0x%lX ", timeprint,
#ifdef WIN32
		(unsigned long int)ithread_self().p
#else
		(unsigned long int)ithread_self()
#endif
	    );
	if (DbgFileName) {
 		char *filepath = strdup(DbgFileName);
 		fprintf(fd, "%s:%d ", basename(filepath), DbgLineNo);
 		free(filepath);
	}
	fflush(fd);
}


#endif /* DEBUG */
