cmake_minimum_required(VERSION 2.8.12)

project (tinylib)

set(VERSION_MAJOR    0)
set(VERSION_MINOR    1)
set(REVISION_NUMBER  0)
set(BUILD_NUMBER     0)

option(BUILD_SHARED "Build tinylib shared library" OFF)
option(BUILD_UNITTESTS "Build tinylib unit tests programs" ON)

#-------------------------------------------------
# compiler flags 
#-------------------------------------------------
set(COMMON_FLAGS "-Wall -Werror -fsigned-char")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${COMMON_FLAGS} -std=gnu99 -Wstrict-prototypes -fPIC")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMMON_FLAGS}")
message(STATUS "Build Type: " ${CMAKE_BUILD_TYPE})
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS} -O0 -g -ggdb -DT_ENABLE_ASSERT")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -O0 -g -ggdb -DT_ENABLE_ASSERT")
    message(STATUS "C Flags:" ${CMAKE_C_FLAGS_DEBUG})
    message(STATUS "CXX Flags:" ${CMAKE_CXX_FLAGS_DEBUG})
else (CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS} -O3 -DNDEBUG")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O3 -DNDEBUG")
    message(STATUS "C Flags:" ${CMAKE_C_FLAGS_RELEASE})
    message(STATUS "CXX Flags:" ${CMAKE_CXX_FLAGS_RELEASE})
endif (CMAKE_BUILD_TYPE STREQUAL "Debug")

#-------------------------------------------------
# build tinylib
#-------------------------------------------------
include_directories(./include)

set(SRC_LIST
    platform/linux/tsysdeps.c
    common/tassert.c)

if (BUILD_SHARED)
    add_library(tinylib SHARED ${SRC_LIST})
    set_target_properties(tinylib PROPERTIES VERSION 
        ${VERSION_MAJOR}.${VERSION_MINOR}.${REVISION_NUMBER}.${BUILD_NUMBER} SOVERSION ${VERSION_MAJOR})
    install(TARGETS tinylib 
        LIBRARY DESTINATION "lib")
else (BUILD_SHARED)
    add_library(tinylib STATIC ${SRC_LIST})
    install(TARGETS tinylib 
        ARCHIVE DESTINATION "lib")
endif (BUILD_SHARED)

#-------------------------------------------------
# generate and install pc
#-------------------------------------------------
configure_file(
    cmake/tinylib.pc.in
    "${CMAKE_BINARY_DIR}/tinylib.pc"
    @ONLY)

#-------------------------------------------------
# install tinylib
#-------------------------------------------------
install(FILES "${CMAKE_BINARY_DIR}/tinylib.pc" DESTINATION "/usr/lib/pkgconfig")
#install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/tinylib
#DESTINATION "include")


#-------------------------------------------------
# add subdiectories
#-------------------------------------------------
if (BUILD_UNITTESTS)
    add_subdirectory(unit_tests)   
endif()    


