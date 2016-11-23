cmake_minimum_required(VERSION ${MIN_CMAKE_VERSION})
project(ixml)


set(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/inc)
set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../prebuild)

set(SOURCE_FILES
    src/ixmlmembuf.h
    src/ixmlparser.h
    src/attr.c
    src/document.c
    src/element.c
    src/ixml.c
    src/ixmldebug.c
    src/ixmlmembuf.c
    src/ixmlparser.c
    src/namedNodeMap.c
    src/node.c
    src/nodeList.c
    test/test_document.c
    )

add_library(${PROJECT_NAME} ${LIB_BUILD_TYPE} ${SOURCE_FILES})

install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION lib
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        CONFIGURATIONS Debug
        )

add_custom_target(install_${PROJECT_NAME}
                  $(MAKE) install
                  DEPENDS ${PROJECT_NAME}
                  COMMENT "Installing ${PROJECT_NAME}")