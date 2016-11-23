cmake_minimum_required(VERSION ${MIN_CMAKE_VERSION})
project(threadutil)



set(SOURCE_FILES
    ../include/UpnpGlobal.h
    ../include/FreeList.h
    ../include/ithread.h
    ../include/LinkedList.h
    ../include/ThreadPool.h
    ../include/TimerThread.h
    src/FreeList.c
    src/LinkedList.c
    src/ThreadPool.c
    src/TimerThread.c
    )

include_directories("${PROJECT_BINARY_DIR}")
include_directories("${PROJECT_INCLUDE_DIR}")

set(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/src/include)
set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../prebuild/${CMAKE_SYSTEM_NAME})
set(ARHCIVE_OUTPUT_PATH ${LIBRARY_OUTPUT_PATH}/${CMAKE_SYSTEM_NAME})

add_library(${PROJECT_NAME} ${LIB_BUILD_TYPE} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} pthread)

install(TARGETS threadutil
        RUNTIME DESTINATION lib
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        CONFIGURATIONS Debug
        )

add_custom_target(install_${PROJECT_NAME}
                  $(MAKE) install
                  DEPENDS ${PROJECT_NAME}
                  COMMENT "Installing ${PROJECT_NAME}")


