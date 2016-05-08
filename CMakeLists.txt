cmake_minimum_required(VERSION 2.8)

project(brigand)

enable_testing()

if((CMAKE_CXX_COMPILER_ID MATCHES "Clang") OR CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra -pedantic -Wold-style-cast")
endif()

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fcxx-exceptions")
endif()

include(FindPythonInterp)
find_package(Boost)

if(Boost_FOUND)
    include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${Boost_INCLUDE_DIRS})
else()
    include_directories(${CMAKE_CURRENT_SOURCE_DIR})
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DBRIGAND_NO_BOOST_SUPPORT")
endif()

# Install pre-commit git hook
execute_process(COMMAND ${CMAKE_COMMAND} -E copy
                ${PROJECT_SOURCE_DIR}/script/pre-commit
                ${PROJECT_SOURCE_DIR}/.git/hooks
               )

set ( STANDALONE_GROUP
    script/embed.py
)

add_custom_target(standalone
    COMMAND ${CMAKE_COMMAND} -E remove ${PROJECT_SOURCE_DIR}/standalone/brigand.hpp
    COMMAND ${PYTHON_EXECUTABLE} ${PROJECT_SOURCE_DIR}/script/embed.py -I./ --include-match=brigand/* ${PROJECT_SOURCE_DIR}/brigand/brigand.hpp -o ${PROJECT_SOURCE_DIR}/standalone/brigand.hpp
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
    COMMENT "Building standalone header file"
    VERBATIM
    SOURCES ${STANDALONE_GROUP}
)

set(CMAKE_DEBUG_POSTFIX "d")

set(BRIGAND_GROUP
    brigand/adapted.hpp
    brigand/algorithms.hpp
    brigand/brigand.hpp
    brigand/config.hpp
    brigand/functions.hpp
    brigand/sequences.hpp
    brigand/types.hpp
)

set(ADAPTED_GROUP
    brigand/adapted/fusion.hpp
    brigand/adapted/integral_list.hpp
    brigand/adapted/list.hpp
    brigand/adapted/pair.hpp
    brigand/adapted/tuple.hpp
    brigand/adapted/fusion.hpp
    brigand/adapted/variant.hpp
)

set(ALGORITHMS_GROUP
    brigand/algorithms/all.hpp
    brigand/algorithms/any.hpp
    brigand/algorithms/wrap.hpp
    brigand/algorithms/count.hpp
    brigand/algorithms/find.hpp
    brigand/algorithms/flatten.hpp
    brigand/algorithms/fold.hpp
    brigand/algorithms/for_each.hpp
    brigand/algorithms/for_each_args.hpp
    brigand/algorithms/index_of.hpp
    brigand/algorithms/is_set.hpp
    brigand/algorithms/none.hpp
    brigand/algorithms/partition.hpp
    brigand/algorithms/remove.hpp
    brigand/algorithms/replace.hpp
    brigand/algorithms/reverse.hpp
    brigand/algorithms/split.hpp
    brigand/algorithms/split_at.hpp
    brigand/algorithms/sort.hpp
    brigand/algorithms/transform.hpp
    brigand/algorithms/select.hpp
)

set(ALGORITHMS_DETAIL_GROUP
    brigand/algorithms/detail/find.hpp
    brigand/algorithms/detail/fold.hpp
    brigand/algorithms/detail/non_null.hpp
    brigand/algorithms/detail/replace.hpp
)

set(FUNCTIONS_ARITHMETIC_GROUP
    brigand/functions/arithmetic/complement.hpp
    brigand/functions/arithmetic/divides.hpp
    brigand/functions/arithmetic/identity.hpp
    brigand/functions/arithmetic/max.hpp>
    brigand/functions/arithmetic/min.hpp
    brigand/functions/arithmetic/minus.hpp
    brigand/functions/arithmetic/modulo.hpp
    brigand/functions/arithmetic/negate.hpp
    brigand/functions/arithmetic/next.hpp
    brigand/functions/arithmetic/plus.hpp
    brigand/functions/arithmetic/prev.hpp
    brigand/functions/arithmetic/times.hpp
)

set(FUNCTIONS_BITWISE_GROUP
    brigand/functions/bitwise/bitand.hpp
    brigand/functions/bitwise/bitor.hpp
    brigand/functions/bitwise/bitxor.hpp
    brigand/functions/bitwise/shift_left.hpp
    brigand/functions/bitwise/shift_right.hpp
)

set(FUNCTIONS_COMPARISON_GROUP
    brigand/functions/comparison/equal_to.hpp
    brigand/functions/comparison/greater.hpp
    brigand/functions/comparison/greater_equal.hpp
    brigand/functions/comparison/less.hpp
    brigand/functions/comparison/less_equal.hpp
    brigand/functions/comparison/not_equal_to.hpp
)

set(FUNCTIONS_LOGICAL_GROUP
    brigand/functions/logical/and.hpp
    brigand/functions/logical/not.hpp
    brigand/functions/logical/or.hpp
    brigand/functions/logical/xor.hpp
)

set(FUNCTIONS_LAMBDA_GROUP
    brigand/functions/lambda/substitute.hpp
    brigand/functions/lambda/apply.hpp
    brigand/functions/lambda/bind.hpp
    brigand/functions/lambda/lambda.hpp
    brigand/functions/lambda/protect.hpp
    brigand/functions/lambda/quote.hpp
    brigand/functions/lambda/unpack.hpp
)

set(FUNCTIONS_MISC_GROUP
    brigand/functions/misc/always.hpp
    brigand/functions/misc/sizeof.hpp
    brigand/functions/misc/repeat.hpp
)

set(FUNCTIONS_GROUPS
    brigand/functions/arithmetic.hpp
    brigand/functions/bitwise.hpp
    brigand/functions/comparisons.hpp
    brigand/functions/if.hpp
    brigand/functions/eval_if.hpp
    brigand/functions/logical.hpp
    brigand/functions/lambda.hpp
    brigand/functions/misc.hpp
)

set(SEQUENCES_GROUP
    brigand/sequences/append.hpp
    brigand/sequences/at.hpp
    brigand/sequences/back.hpp
    brigand/sequences/front.hpp
    brigand/sequences/last_element.hpp
    brigand/sequences/keys_as_sequence.hpp
    brigand/sequences/list.hpp
    brigand/sequences/make_sequence.hpp
    brigand/sequences/map.hpp
    brigand/sequences/pair.hpp
    brigand/sequences/range.hpp
    brigand/sequences/size.hpp
    brigand/sequences/set.hpp
    brigand/sequences/values_as_sequence.hpp
)

set(TYPES_GROUP
    brigand/types/bool.hpp
    brigand/types/empty_base.hpp
    brigand/types/has_placeholders.hpp
    brigand/types/has_type.hpp
    brigand/types/integer.hpp
    brigand/types/inherit.hpp
    brigand/types/inherit_linearly.hpp
    brigand/types/is_placeholder.hpp
    brigand/types/args.hpp
    brigand/types/no_such_type.hpp
    brigand/types/type.hpp
    brigand/types/real.hpp
    brigand/types/voidp.hpp
)

set(PLACEHOLDER_GROUP brigand/nothing.cpp)

source_group(brigand FILES ${BRIGAND_GROUP})
source_group(brigand\\adapted FILES ${ADAPTED_GROUP})
source_group(brigand\\algorithms FILES ${ALGORITHMS_GROUP})
source_group(brigand\\algorithms\\detail FILES ${ALGORITHMS_DETAIL_GROUP})
source_group(brigand\\functions FILES ${FUNCTIONS_GROUPS})
source_group(brigand\\functions\\arithmetic FILES ${FUNCTIONS_ARITHMETIC_GROUP})
source_group(brigand\\functions\\bitwise FILES ${FUNCTIONS_BITWISE_GROUP})
source_group(brigand\\functions\\lambda FILES ${FUNCTIONS_LAMBDA_GROUP})
source_group(brigand\\functions\\logical FILES ${FUNCTIONS_LOGICAL_GROUP})
source_group(brigand\\functions\\misc FILES ${FUNCTIONS_MISC_GROUP})
source_group(brigand\\functions\\comparison FILES ${FUNCTIONS_COMPARISON_GROUP})
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
    ${PLACEHOLDER_GROUP}
)

set(test_files
    test/always.cpp
    test/apply.cpp
    test/args.cpp
    test/bind.cpp
    test/bitwise_test.cpp
    test/comparison_test.cpp
    test/config_test.cpp
    test/eval_if_test.cpp
    test/erase_c_test.cpp
    test/find.cpp
    test/flatten.cpp
    test/fold.cpp
    test/for_each.cpp
    test/identity.cpp
    test/if_test.cpp
    test/index_of.cpp
    test/include_test.cpp
    test/inherit.cpp
    test/inherit_linearly.cpp
    test/integer.cpp
    test/integral_list_test.cpp
    test/integral_test.cpp
    test/is_placeholder.cpp
    test/is_set_test.cpp
    test/keys_as_sequence.cpp
    test/list_test.cpp
    test/logical_test.cpp
    test/main.cpp
    test/make_sequence_test.cpp
    test/map_test.cpp
    test/pair_test.cpp
    test/partition_test.cpp
    test/predicate_reduction_test.cpp
    test/protect.cpp
    test/quote.cpp
    test/range_test.cpp
    test/real.cpp
    test/remove_test.cpp
    test/repeat_test.cpp
    test/replace.cpp
    test/reverse_test.cpp
    test/select.cpp
    test/set_test.cpp
    test/sizeof.cpp
    test/sort_test.cpp
    test/split.cpp
    test/split_at.cpp
    test/transform.cpp
    test/tuple_test.cpp
    test/unpack.cpp
    test/values_as_sequence.cpp
)

if(Boost_FOUND)
    set(test_files
    ${test_files}
    test/variant_test.cpp
    test/fusion_test.cpp)
endif()

source_group(tests FILES ${test_files})

add_executable(brigand_test ${test_files})

add_test(brigand brigand_test)

install(DIRECTORY ${PROJECT_SOURCE_DIR}/brigand
    DESTINATION .
)
