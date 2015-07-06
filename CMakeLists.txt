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
    brigand/arithmetic.hpp
    brigand/brigand.hpp
    brigand/comparisons.hpp
    brigand/logical.hpp)

set(ADAPTED_GROUP
    brigand/adapted/pair.hpp
    brigand/adapted/tuple.hpp
    brigand/adapted/variant.hpp)

set(ALGORITHMS_GROUP
    brigand/algorithms/apply.hpp
    brigand/algorithms/count.hpp
    brigand/algorithms/find.hpp
    brigand/algorithms/fold.hpp
    brigand/algorithms/for_each.hpp
    brigand/algorithms/for_each_args.hpp
    brigand/algorithms/is_set.hpp
    brigand/algorithms/reverse.hpp
    brigand/algorithms/transform.hpp)

set(ALGORITHMS_DETAIL_GROUP
    brigand/algorithms/detail/find.hpp)

set(FUNCTIONS_GROUPS
    brigand/functions/and.hpp
    brigand/functions/complement.hpp
    brigand/functions/divides.hpp
    brigand/functions/equal_to.hpp
    brigand/functions/greater.hpp
    brigand/functions/greater_equal.hpp
    brigand/functions/identity.hpp
    brigand/functions/less.hpp
    brigand/functions/less_equal.hpp
    brigand/functions/max.hpp
    brigand/functions/min.hpp
    brigand/functions/minus.hpp
    brigand/functions/modulo.hpp
    brigand/functions/negate.hpp
    brigand/functions/next.hpp
    brigand/functions/not.hpp
    brigand/functions/not_equal_to.hpp
    brigand/functions/or.hpp
    brigand/functions/prev.hpp
    brigand/functions/plus.hpp
    brigand/functions/times.hpp
    brigand/functions/xor.hpp)

set(SEQUENCES_GROUP
    brigand/sequences/append.hpp
    brigand/sequences/at.hpp
    brigand/sequences/back.hpp
    brigand/sequences/front.hpp
    brigand/sequences/last_element.hpp
    brigand/sequences/list.hpp
    brigand/sequences/make_sequence.hpp
    brigand/sequences/map.hpp
    brigand/sequences/pair.hpp
    brigand/sequences/size.hpp
    brigand/sequences/set.hpp
)

set(TYPES_GROUP
    brigand/types/bool.hpp
    brigand/types/integer.hpp
    brigand/types/no_such_type.hpp
)

set(PLACEHOLDER_GROUP brigand/nothing.cpp)

source_group(brigand FILES ${BRIGAND_GROUP})
source_group(brigand\\adapted FILES ${ADAPTED_GROUP})
source_group(brigand\\algorithms FILES ${ALGORITHMS_GROUP})
source_group(brigand\\algorithms\\detail FILES ${ALGORITHMS_DETAIL_GROUP})
source_group(brigand\\functions FILES ${FUNCTIONS_GROUPS})
source_group(brigand\\sequences FILES ${SEQUENCES_GROUP})
source_group(brigand\\types FILES ${TYPES_GROUP})
source_group(placeholder FILES ${PLACEHOLDER_GROUP})

add_library(brigand
    ${BRIGAND_GROUP}
    ${ADAPTED_GROUP}
    ${ALGORITHMS_GROUP}
    ${ALGORITHMS_DETAIL_GROUP}
    ${FUNCTIONS_GROUPS}
    ${SEQUENCES_GROUP}
    ${TYPES_GROUP}
    ${PLACEHOLDER_GROUP})

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(test_files
    test/comparison_test.cpp
    test/find.cpp
    test/fold.cpp
    test/for_each.cpp
    test/identity.cpp
    test/include_test.cpp
    test/integral_list_test.cpp
    test/integral_test.cpp
    test/is_set_test.cpp
    test/list_test.cpp
    test/logical_test.cpp
    test/make_sequence_test.cpp
    test/map_test.cpp
    test/mpl_test.cpp
    test/pair_test.cpp
    test/reverse_test.cpp
    test/set_test.cpp
    test/transform.cpp
    test/tuple_test.cpp)

if (${Boost_INCLUDE_DIR})
    set(test_files ${test_files} test/variant_test.cpp)
endif()

source_group(tests FILES ${test_files})

add_executable(brigand_test ${test_files})

install ( DIRECTORY ${PROJECT_SOURCE_DIR}/brigand
          DESTINATION .
        )
