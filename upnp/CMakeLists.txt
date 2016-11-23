cmake_minimum_required(VERSION ${MIN_CMAKE_VERSION})
project(upnp)

set(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/src/include)
set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../prebuild)
set(ARHCIVE_OUTPUT_PATH ${LIBRARY_OUTPUT_PATH})

set(SOURCE_FILES
    ../include/UpnpGlobal.h
    ../include/upnp.h
    ../include/upnpconfig.h
    ../include/upnpdebug.h
    ../include/UpnpInet.h
    ../include/UpnpIntTypes.h
    ../include/UpnpStdInt.h
    ../include/UpnpString.h
    ../include/upnptools.h
    ../include/UpnpUniStd.h
    src/api/upnpapi.c
    src/api/upnpdebug.c
    src/api/UpnpString.c
    src/api/upnptools.c
    src/gena/gena_callback2.c
    src/gena/gena_ctrlpt.c
    src/gena/gena_device.c
    src/genlib/client_table/client_table.c
    src/genlib/miniserver/miniserver.c
    src/genlib/net/http/httpparser.c
    src/genlib/net/http/httpreadwrite.c
    src/genlib/net/http/parsetools.c
    src/genlib/net/http/statcodes.c
    src/genlib/net/http/webserver.c
    src/genlib/net/uri/uri.c
    src/genlib/net/sock.c
    src/genlib/service_table/service_table.c
    src/genlib/util/membuffer.c
    src/genlib/util/strintmap.c
    src/genlib/util/upnp_timeout.c
    src/genlib/util/util.c
    src/include/client_table.h
    src/include/config.h
    src/include/gena.h
    src/include/gena_ctrlpt.h
    src/include/gena_device.h
    src/include/global.h
    src/include/gmtdate.h
    src/include/httpparser.h
    src/include/httpreadwrite.h
    src/include/inet_pton.h
    src/include/md5.h
    src/include/membuffer.h
    src/include/miniserver.h
    src/include/netall.h
    src/include/parsetools.h
    src/include/server.h
    src/include/service_table.h
    src/include/soaplib.h
    src/include/sock.h
    src/include/ssdplib.h
    src/include/statcodes.h
    src/include/statuscodes.h
    src/include/strintmap.h
    src/include/sysdep.h
    src/include/unixutil.h
    src/include/upnp_timeout.h
    src/include/upnpapi.h
    src/include/upnputil.h
    src/include/uri.h
    src/include/urlconfig.h
    src/include/uuid.h
    src/include/VirtualDir.h
    src/include/webserver.h
    src/soap/soap_common.c
    src/soap/soap_ctrlpt.c
    src/soap/soap_device.c
    src/ssdp/ssdp_ctrlpt.c
    src/ssdp/ssdp_device.c
    src/ssdp/ssdp_ResultData.h
    src/ssdp/ssdp_server.c
    src/urlconfig/urlconfig.c
    src/uuid/md5.c
    src/uuid/sysdep.c
    src/uuid/uuid.c
    src/inet_pton.c
    src/win_dll.c
    )

set(CMAKE_VERBOSE_MAKEFILE ON)

add_library(upnp ${LIB_BUILD_TYPE} ${SOURCE_FILES})
target_include_directories(${PROJECT_NAME} PUBLIC src/include)
if (WIN32)
	target_link_libraries(upnp wsock32 ws2_32)
	target_link_libraries(upnp iphlpapi)
endif (WIN32)
add_dependencies(${PROJECT_NAME} ixml threadutil)
target_link_libraries(${PROJECT_NAME} ixml)
target_link_libraries(${PROJECT_NAME} threadutil)


install(TARGETS upnp
        RUNTIME DESTINATION lib
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        PUBLIC_HEADER DESTINATION usr/local/include/upnp
        CONFIGURATIONS Debug
        )

install(DIRECTORY ../include/ DESTINATION include/upnp)

add_custom_target(install_${PROJECT_NAME}
                  $(MAKE) install
                  DEPENDS ${PROJECT_NAME}
                  COMMENT "Installing ${PROJECT_NAME}")
