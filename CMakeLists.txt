cmake_minimum_required(VERSION 2.8)

project(brigand)

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
    brigand/append.hpp
    brigand/apply.hpp
    brigand/at.hpp
    brigand/back.hpp
    brigand/complement.hpp
    brigand/count.hpp
    brigand/front.hpp
    brigand/list.hpp
    brigand/minus.hpp
    brigand/modulo.hpp
    brigand/next.hpp
    brigand/not.hpp
    brigand/plus.hpp
    brigand/prev.hpp
    brigand/size.hpp
    brigand/times.hpp

    brigand/nothing.cpp
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(qdb_mpl_test
    test/list_test.cpp
    test/integral_test.cpp

    test/mpl_test.cpp)
