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

find_package(Boost COMPONENTS variant)

set(CMAKE_DEBUG_POSTFIX "d")

add_library(brigand
    brigand/and.hpp
    brigand/append.hpp
    brigand/apply.hpp
    brigand/at.hpp
    brigand/back.hpp
    brigand/bool.hpp
    brigand/complement.hpp
    brigand/comparisons.hpp
    brigand/count.hpp
    brigand/front.hpp
    brigand/less.hpp
    brigand/less_equal.hpp
    brigand/greater.hpp
    brigand/greater_equal.hpp
    brigand/identity.hpp
    brigand/list.hpp
    brigand/logical.hpp
    brigand/max.hpp
    brigand/variant/make_variant.hpp
    brigand/min.hpp
    brigand/minus.hpp
    brigand/modulo.hpp
    brigand/next.hpp
    brigand/not.hpp
    brigand/or.hpp
    brigand/plus.hpp
    brigand/prev.hpp
    brigand/size.hpp
    brigand/times.hpp
    brigand/xor.hpp
    brigand/nothing.cpp
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(test_files

    test/list_test.cpp
    test/integral_test.cpp
    test/identity.cpp
    test/logical_test.cpp
    test/comparison_test.cpp
    test/for_each.cpp
    test/mpl_test.cpp
    )

if (${Boost_INCLUDE_DIR})
    set(test_files ${test_files} test/variant_test.cpp)
endif()

add_executable(brigand_test ${test_files})
