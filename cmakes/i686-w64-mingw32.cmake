# the name of the target operating system
set(CMAKE_SYSTEM_NAME Windows)
set(CMAKE_SYSTEM_PROCESSOR i686)

if (NOT MINGW_PREFIX)
	set(MINGW_PREFIX "/usr")
endif ()

# which compilers to use for C and C++ and ASM-ATT
set(CMAKE_C_COMPILER i686-w64-mingw32-gcc)
set(CMAKE_CXX_COMPILER i686-w64-mingw32-g++)
set(CMAKE_ASM-ATT_COMPILER i686-w64-mingw32-as)
set(CMAKE_RC_COMPILER i686-mingw32-windres)

# here is the target environment located
set(CMAKE_FIND_ROOT_PATH
    ${MINGW_PREFIX}/i686-w64-mingw32
    ${MINGW_PREFIX}/sys-root/i686-w64-mingw32
    )

# adjust the default behaviour of the FIND_XXX() commands:
# search headers and libraries in the target environment, search
# programs in the host environment
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)