cmake_minimum_required(VERSION 2.8)

project(qdb-mpl)

if(CLANG OR CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

    add_compile_options(-fPIC)
endif()

IF(CLANG)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++") # tbb will not work under clang with libstdc++
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fcxx-exceptions")
ENDIF()

set(CMAKE_DEBUG_POSTFIX "d")

add_library(mpl 
    qdb/mpl/append.hpp
    qdb/mpl/apply.hpp 
     qdb/mpl/at.hpp
    qdb/mpl/back.hpp   
    qdb/mpl/count.hpp
    qdb/mpl/front.hpp
    qdb/mpl/list.hpp
    qdb/mpl/minus.hpp
    qdb/mpl/not.hpp
    qdb/mpl/plus.hpp
    qdb/mpl/size.hpp

    qdb/mpl/nothing.cpp
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(qdb_mpl_test
    test/list_test.cpp
    test/integral_test.cpp

    test/mpl_test.cpp)