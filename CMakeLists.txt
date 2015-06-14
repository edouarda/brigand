cmake_minimum_required(VERSION 2.8)

project(brigand)

if((CMAKE_CXX_COMPILER_ID MATCHES "Clang") OR CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif()

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fcxx-exceptions")
ENDIF()

find_package(Boost COMPONENTS variant)

set(CMAKE_DEBUG_POSTFIX "d")

set(BRIGAND_GROUP
    brigand/and.hpp
    brigand/append.hpp
    brigand/apply.hpp
    brigand/arithmetic.hpp
    brigand/at.hpp
    brigand/back.hpp
    brigand/bool.hpp
    brigand/brigand.hpp
    brigand/comparisons.hpp
    brigand/complement.hpp
    brigand/count.hpp
    brigand/divides.hpp
    brigand/equal_to.hpp
    brigand/find.hpp
    brigand/for_each.hpp
    brigand/for_each_args.hpp
    brigand/front.hpp
    brigand/greater.hpp
    brigand/greater_equal.hpp
    brigand/identity.hpp
    brigand/less.hpp
    brigand/less_equal.hpp
    brigand/list.hpp
    brigand/logical.hpp
    brigand/map.hpp
    brigand/max.hpp
    brigand/min.hpp
    brigand/minus.hpp
    brigand/modulo.hpp
    brigand/negate.hpp
    brigand/next.hpp
    brigand/not.hpp
    brigand/not_equal_to.hpp
    brigand/no_such_type.hpp
    brigand/or.hpp
    brigand/pair.hpp
    brigand/plus.hpp
    brigand/prev.hpp
    brigand/size.hpp
    brigand/times.hpp
    brigand/transform.hpp
    brigand/xor.hpp)

set(DETAIL_GROUP
    brigand/detail/last_element.hpp
 )

set(ADAPTED_GROUP brigand/adapted/pair.hpp
    brigand/adapted/tuple.hpp
    brigand/adapted/variant.hpp)

set(PLACEHOLDER_GROUP brigand/nothing.cpp)

source_group(brigand FILES ${BRIGAND_GROUP})
source_group(brigand\\detail FILES ${DETAIL_GROUP})
source_group(brigand\\adapted FILES ${ADAPTED_GROUP})
source_group(placeholder FILES ${PLACEHOLDER_GROUP})

add_library(brigand
    ${BRIGAND_GROUP}
    ${DETAIL_GROUP}
    ${ADAPTED_GROUP}
    ${PLACEHOLDER_GROUP})

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(test_files

    test/list_test.cpp
    test/integral_list_test.cpp
    test/integral_test.cpp
    test/identity.cpp
    test/logical_test.cpp
    test/comparison_test.cpp
    test/for_each.cpp
    test/find.cpp
    test/transform.cpp
    test/tuple_test.cpp
    test/map_test.cpp
    test/mpl_test.cpp
    test/pair_test.cpp

    )

if (${Boost_INCLUDE_DIR})
    set(test_files ${test_files} test/variant_test.cpp)
endif()

source_group(tests FILES ${test_files})

add_executable(brigand_test ${test_files})

install ( DIRECTORY ${PROJECT_SOURCE_DIR}/brigand
          DESTINATION .
        )
