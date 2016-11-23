set(MIN_CMAKE_VERSION 2.8.10)
project(PUPNP)
cmake_minimum_required(VERSION ${MIN_CMAKE_VERSION})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_LEGACY_CYGWIN_WIN32 1)

option(CROSS_COMPILE_WIN32 "Whether to cross-compile win32 lib" OFF)

if (CROSS_COMPILE_WIN32)
	if (NOT MINGW_PREFIX)
		set(MINGW_PREFIX "")
	endif ()
	set(CMAKE_TOOLCHAIN_FILE ${PROJECT_SOURCE_DIR}/cmakes/i686-w64-mingw32.cmake)
	set(CMAKE_PREFIX_PATH ${MINGW_PREFIX}/)
endif ()

set(CMAKE_SYSTEM_PREFIX_PATH ${CMAKE_PREFIX_PATH})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -Wfatal-errors -Wno-long-long -pedantic")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Werror -Wfatal-errors -Wno-long-long -pedantic")

if (UPNP_USE_MSVCPP)
	add_definitions(-DUPNP_USE_MSVCPP)
endif ()

set(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/prebuild)

include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${CMAKE_PREFIX_PATH}/include)
include_directories("${PROJECT_INCLUDE_DIR}")
include_directories("${PROJECT_SOURCE_DIR}")

if (ENABLE_STATIC)
	set(LIB_BUILD_TYPE STATIC)
else ()
	set(LIB_BUILD_TYPE SHARED)
endif ()

include(cmakes/autoconfig.cmake)
include(cmakes/options.cmake)

set(PARENT_VAR "Parent")

add_subdirectory(ixml EXCLUDE_FROM_ALL)
add_subdirectory(threadutil EXCLUDE_FROM_ALL)
add_subdirectory(upnp)



