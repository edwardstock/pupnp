#ifndef UPNP_AUTOCONFIG_H
#define UPNP_AUTOCONFIG_H

/* Define to 1 if you have the <stddef.h> header file. */
#cmakedefine HAVE_STDDEF_H 1

/* Define to 1 if you have the <arpa/inet.h> header file. */
#cmakedefine HAVE_ARPA_INET_H 1

/* Define to 1 if you have the <dlfcn.h> header file. */
#cmakedefine HAVE_DLFCN_H 1

/* Define to 1 if you don't have `vprintf' but do have `_doprnt.' */
#cmakedefine HAVE_DOPRNT 1

/* Define to 1 if you have the <fcntl.h> header file. */
#cmakedefine HAVE_FCNTL_H 1

/* Define to 1 if fseeko (and presumably ftello) exists and is declared. */
#cmakedefine HAVE_FSEEKO 1

/* Define to 1 if you have the <inttypes.h> header file. */
#cmakedefine HAVE_INTTYPES_H 1

/* Define to 1 if you have the <limits.h> header file. */
#cmakedefine HAVE_LIMITS_H 1

/* Define to 1 if you have the <memory.h> header file. */
#cmakedefine HAVE_MEMORY_H 1

/* Define to 1 if you have the <netdb.h> header file. */
#cmakedefine HAVE_NETDB_H 1

/* Define to 1 if you have the <netinet/in.h> header file. */
#cmakedefine HAVE_NETINET_IN_H 1

/* Define if you have POSIX threads libraries and header files. */
#cmakedefine HAVE_PTHREAD 1

/* Define to 1 if you have the <stdint.h> header file. */
#cmakedefine HAVE_STDINT_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#cmakedefine HAVE_STDLIB_H 1

/* Define to 1 if you have the <strings.h> header file. */
#cmakedefine HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#cmakedefine HAVE_STRING_H 1

/* Defines if strndup is available on your system */
#cmakedefine HAVE_STRNDUP 1

/* Defines if strnlen is available on your system */
#cmakedefine HAVE_STRNLEN 1

/* Define to 1 if you have the <syslog.h> header file. */
#cmakedefine HAVE_SYSLOG_H 1

/* Define to 1 if you have the <sys/ioctl.h> header file. */
#cmakedefine HAVE_SYS_IOCTL_H 1

/* Define to 1 if you have the <sys/socket.h> header file. */
#cmakedefine HAVE_SYS_SOCKET_H 1

/* Define to 1 if you have the <w32api/winsock2.h> header file. */
#cmakedefine HAVE_WIN_SOCKET_H 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#cmakedefine HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/time.h> header file. */
#cmakedefine HAVE_SYS_TIME_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#cmakedefine HAVE_SYS_TYPES_H 1

/* Define to 1 if you have the <unistd.h> header file. */
#cmakedefine HAVE_UNISTD_H 1

/* Define to 1 if you have the `vprintf' function. */
#cmakedefine HAVE_VPRINTF 1

/* Define to 1 if you have the <ws2tcpip.h> header file. */
#cmakedefine HAVE_WS2TCPIP_H 1

#cmakedefine ENABLE_STATIC 1
#ifndef ENABLE_STATIC
	#define LIBUPNP_EXPORTS 1 // shared lib export
#else
	#define UPNP_STATIC_LIB 1 // static lib
#endif

#cmakedefine ENABLE_DEBUG 1
#ifdef ENABLE_DEBUG
	#define UPNP_HAVE_DEBUG ENABLE_DEBUG
#endif

#cmakedefine ENABLE_OPENSSL 1
#ifdef ENABLE_OPENSSL
	#define UPNP_ENABLE_OPEN_SSL ENABLE_OPENSSL
#endif

#cmakedefine ENABLE_BLOCKING_TCP 1
#ifdef ENABLE_BLOCKING_TCP
#define UPNP_ENABLE_BLOCKING_TCP_CONNECTIONS ENABLE_BLOCKING_TCP
#endif

// default false
#cmakedefine ENABLE_IPV6
#ifdef ENABLE_IPV6
#define UPNP_ENABLE_IPV6 ENABLE_IPV6
#endif

// default false
#cmakedefine ENABLE_POST_WRITE
#ifdef ENABLE_POST_WRITE
#define UPNP_ENABLE_POST_WRITE ENABLE_POST_WRITE
#endif

#cmakedefine ENABLE_UNSPECIFIED_SERVER 1
#ifdef ENABLE_UNSPECIFIED_SERVER
	#define UPNP_ENABLE_UNSPECIFIED_SERVER ENABLE_UNSPECIFIED_SERVER
#endif

#cmakedefine ENABLE_CLIENT 1
#ifdef ENABLE_CLIENT
#define UPNP_HAVE_CLIENT 1
#endif

#cmakedefine ENABLE_DEVICE 1
#ifdef ENABLE_DEVICE
#define UPNP_HAVE_DEVICE ENABLE_DEVICE
#endif

#cmakedefine ENABLE_GENA 1
#ifdef ENABLE_GENA
#define UPNP_HAVE_GENA ENABLE_GENA
#endif

#cmakedefine ENABLE_OPT_SSDP 1
#ifdef ENABLE_OPT_SSDP
#define UPNP_HAVE_OPTSSDP 1
#endif

#cmakedefine ENABLE_SOAP 1
#ifdef ENABLE_SOAP
#define UPNP_HAVE_SOAP ENABLE_SOAP
#endif

#cmakedefine ENABLE_SSDP 1
#ifdef ENABLE_SSDP
#define UPNP_HAVE_SSDP ENABLE_SSDP
#endif

#cmakedefine ENABLE_TOOLS 1
#ifdef ENABLE_TOOLS
#define UPNP_HAVE_TOOLS 1
#endif

#cmakedefine ENABLE_WEBSERVER
#ifdef ENABLE_WEBSERVER
#define UPNP_HAVE_WEBSERVER ENABLE_WEBSERVER
#endif


/* Do not use pthread_rwlock_t */
#define UPNP_USE_RWLOCK 1

#endif // UPNP_AUTOCONFIG_H

