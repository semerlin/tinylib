set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

find_package (GTEST)
find_package(Threads REQUIRED)

if (GTEST_FOUND)
    include_directories(../include)
    include_directories(${GTEST_INCLUDE_DIR})

    set(LIB_LIST
        ${GTEST_LIBRARY}
        pthread)

    set(COMMON_SRC_LIST
        ../common/tassert.c
        ../platform/linux/tsysdeps.c)


    #test tassert
    add_executable(test_tassert test_tassert.cpp 
                               ${COMMON_SRC_LIST})
    target_link_libraries(test_tassert ${LIB_LIST})

endif (GTEST_FOUND)



