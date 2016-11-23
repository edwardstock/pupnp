#ifndef UPNPUNISTD_H
#define UPNPUNISTD_H

#if defined(_MSC_VER)
/* Do not #include <unistd.h> on WIN32. */
#else /* WIN32 */
	#include <unistd.h> /* for close() */
#endif /* WIN32 */

#endif /* UPNPUNISTD_H */
