/*******************************************************************************
 *
 * Copyright (c) 2006 Rémi Turboult <r3mi@users.sourceforge.net>
 * All rights reserved. 
 *
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted provided that the following conditions are met: 
 *
 * * Redistributions of source code must retain the above copyright notice, 
 * this list of conditions and the following disclaimer. 
 * * Redistributions in binary form must reproduce the above copyright notice, 
 * this list of conditions and the following disclaimer in the documentation 
 * and/or other materials provided with the distribution. 
 * * Neither name of Intel Corporation nor the names of its contributors 
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

#ifndef UPNP_CONFIG_H
#define UPNP_CONFIG_H


/***************************************************************************
 * Library version 
 ***************************************************************************/

/** The library version (string) e.g. "1.3.0" */
#define UPNP_VERSION_STRING "1.6.21"

/** Major version of the library */
#define UPNP_VERSION_MAJOR 1

/** Minor version of the library */
#define UPNP_VERSION_MINOR 6

/** Patch version of the library */
#define UPNP_VERSION_PATCH 21

/** The library version (numeric) e.g. 10300 means version 1.3.0 */
#define UPNP_VERSION    \
  ((UPNP_VERSION_MAJOR * 100 + UPNP_VERSION_MINOR) * 100 + UPNP_VERSION_PATCH)


/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT "mroberto@users.sourceforge.net"

/* Define to the full name of this package. */
#define PACKAGE_NAME "libupnp"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "libupnp 1.6.21"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "libupnp"

/* Define to the home page for this package. */
#define PACKAGE_URL ""

/* Define to the version of this package. */
#define PACKAGE_VERSION "1.6.21"

/***************************************************************************
 * Large file support
 ***************************************************************************/

/** File Offset size */
#define _FILE_OFFSET_BITS 64

/** Define to 1 to make fseeko visible on some hosts (e.g. glibc 2.2). */
#define _LARGEFILE_SOURCE 1

/** Large files support */
#define _LARGE_FILE_SOURCE /**/

/***************************************************************************
 * Library optional features
 ***************************************************************************/


#endif /* UPNP_CONFIG_H */

