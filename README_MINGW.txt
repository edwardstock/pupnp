
Building pupnp with MinGW on Windows.

With vanilla MinGW:
PTHREAD_CFLAGS=-Ic:/recolldeps/pthreads-w32/Pre-built.2/include/ \
PTHREAD_LIBS=c:/recolldeps/pthreads-w32/Pre-built.2/lib/x86/pthreadGC2.a \
CFLAGS="-DUPNP_STATIC_LIB -D_MBCS" \
./configure --disable-shared --disable-samples --disable-debug \
            --enable-client --enable-device --enable-webserver

With QT MinGW (includes the pthreads lib):
CFLAGS="-DUPNP_STATIC_LIB -D_MBCS" \
./configure --disable-shared --disable-samples --enable-debug \
            --enable-client --enable-device --enable-webserver

# Check the contents of upnp/inc/upnpconfig.h It seems to happen that the
# defines are not updated (check HAVE_CLIENT for example), if
# upnpconfig.h.in has wrong line endings (should have LF). In this case,
# fix the endings and retry.

make

