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

    #test tlist
    add_executable(test_tlist test_tlist.cpp 
                              ../container/list/tlist.c
                               ${COMMON_SRC_LIST})
    target_link_libraries(test_tlist ${LIB_LIST})

    #test tslist
    add_executable(test_tslist test_tslist.cpp 
                              ../container/list/tslist.c
                               ${COMMON_SRC_LIST})
    target_link_libraries(test_tslist ${LIB_LIST})

    #test thlist
    add_executable(test_thlist test_thlist.cpp 
                              ../container/hash/thlist.c
                               ${COMMON_SRC_LIST})
    target_link_libraries(test_thlist ${LIB_LIST})

    #test thash_string
    add_executable(test_thash_string test_thash_string.cpp 
                              ../container/hash/thlist.c
                              ../container/hash/thash_string.c
                               ${COMMON_SRC_LIST})
    target_link_libraries(test_thash_string ${LIB_LIST})

    #test tqsort
    add_executable(test_tqsort test_tqsort.cpp 
                              ../algorithm/sort/tqsort.c
                               ${COMMON_SRC_LIST})
    target_link_libraries(test_tqsort ${LIB_LIST})

    #test tstring
    add_executable(test_tstring test_tstring.cpp 
                              ../string/tstring.c
                               ${COMMON_SRC_LIST})
    target_link_libraries(test_tstring ${LIB_LIST})


    #test tkeyfile
    add_executable(test_tkeyfile test_tkeyfile.cpp 
                                ../container/hash/thlist.c
                                ../container/list/tlist.c
                                ../string/tstring.c
                                ../container/hash/thash_string.c
                                ../serialization/tkeyfile.c
                                ${COMMON_SRC_LIST})
    target_link_libraries(test_tkeyfile ${LIB_LIST})

    #test tqueue
    add_executable(test_tqueue test_tqueue.cpp 
                              ../container/list/tlist.c
                              ../container/queue/tqueue.c
                               ${COMMON_SRC_LIST})
    target_link_libraries(test_tqueue ${LIB_LIST})


endif (GTEST_FOUND)



