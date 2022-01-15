cmake_minimum_required(VERSION 2.8)

project(brigand)
# When moving to CMake 3.0 and newer the set(brigand_VERSION 1.3.0) should
# be replaced with project(brigand VERSION 1.3.0)
set(brigand_VERSION 1.3.0)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMake")

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
    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include ${Boost_INCLUDE_DIRS})
else()
    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DBRIGAND_NO_BOOST_SUPPORT")
endif()

# Install pre-commit git hook
execute_process(COMMAND ${CMAKE_COMMAND} -E copy
                ${PROJECT_SOURCE_DIR}/script/pre-commit
                ${PROJECT_SOURCE_DIR}/.git/hooks
               )

set (STANDALONE_GROUP
    script/embed.py
)

add_custom_target(standalone
    COMMAND ${CMAKE_COMMAND} -E remove ${PROJECT_SOURCE_DIR}/include/standalone/brigand.hpp
    COMMAND ${PYTHON_EXECUTABLE} ${PROJECT_SOURCE_DIR}/script/embed.py -I${PROJECT_SOURCE_DIR}/include --include-match=brigand/* ${PROJECT_SOURCE_DIR}/include/brigand/brigand.hpp -o ${PROJECT_SOURCE_DIR}/include/standalone/brigand.hpp
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
    COMMENT "Building standalone header file"
    VERBATIM
    SOURCES ${STANDALONE_GROUP}
)

set(CMAKE_DEBUG_POSTFIX "d")

set(BRIGAND_GROUP
    ${PROJECT_SOURCE_DIR}/include/brigand/adapted.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/algorithms.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/brigand.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/config.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/functions.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/sequences.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/types.hpp
)

set(ADAPTED_GROUP
    ${PROJECT_SOURCE_DIR}/include/brigand/adapted/fusion.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/adapted/integral_list.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/adapted/list.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/adapted/pair.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/adapted/tuple.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/adapted/fusion.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/adapted/variant.hpp
)

set(ALGORITHMS_GROUP
    ${PROJECT_SOURCE_DIR}/include/brigand/algorithms/all.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/algorithms/any.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/algorithms/wrap.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/algorithms/count.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/algorithms/find.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/algorithms/flatten.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/algorithms/fold.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/algorithms/for_each.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/algorithms/for_each_args.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/algorithms/index_of.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/algorithms/is_set.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/algorithms/merge.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/algorithms/none.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/algorithms/partition.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/algorithms/remove.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/algorithms/replace.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/algorithms/reverse.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/algorithms/split.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/algorithms/split_at.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/algorithms/sort.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/algorithms/transform.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/algorithms/select.hpp
)

set(ALGORITHMS_DETAIL_GROUP
    ${PROJECT_SOURCE_DIR}/include/brigand/algorithms/detail/find.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/algorithms/detail/fold.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/algorithms/detail/non_null.hpp
)

set(FUNCTIONS_ARITHMETIC_GROUP
    ${PROJECT_SOURCE_DIR}/include/brigand/functions/arithmetic/complement.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/functions/arithmetic/divides.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/functions/arithmetic/identity.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/functions/arithmetic/max.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/functions/arithmetic/min.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/functions/arithmetic/minus.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/functions/arithmetic/modulo.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/functions/arithmetic/negate.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/functions/arithmetic/next.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/functions/arithmetic/plus.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/functions/arithmetic/prev.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/functions/arithmetic/times.hpp
)

set(FUNCTIONS_BITWISE_GROUP
    ${PROJECT_SOURCE_DIR}/include/brigand/functions/bitwise/bitand.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/functions/bitwise/bitor.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/functions/bitwise/bitxor.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/functions/bitwise/shift_left.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/functions/bitwise/shift_right.hpp
)

set(FUNCTIONS_COMPARISON_GROUP
    ${PROJECT_SOURCE_DIR}/include/brigand/functions/comparison/equal_to.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/functions/comparison/greater.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/functions/comparison/greater_equal.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/functions/comparison/less.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/functions/comparison/less_equal.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/functions/comparison/not_equal_to.hpp
)

set(FUNCTIONS_LOGICAL_GROUP
    ${PROJECT_SOURCE_DIR}/include/brigand/functions/logical/and.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/functions/logical/not.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/functions/logical/or.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/functions/logical/xor.hpp
)

set(FUNCTIONS_LAMBDA_GROUP
    ${PROJECT_SOURCE_DIR}/include/brigand/functions/lambda/substitute.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/functions/lambda/apply.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/functions/lambda/bind.hpp
)

set(FUNCTIONS_MISC_GROUP
    ${PROJECT_SOURCE_DIR}/include/brigand/functions/misc/always.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/functions/misc/sizeof.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/functions/misc/repeat.hpp
)

set(FUNCTIONS_GROUPS
    ${PROJECT_SOURCE_DIR}/include/brigand/functions/arithmetic.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/functions/bitwise.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/functions/comparisons.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/functions/if.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/functions/eval_if.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/functions/logical.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/functions/lambda.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/functions/misc.hpp
)

set(SEQUENCES_GROUP
    ${PROJECT_SOURCE_DIR}/include/brigand/sequences/append.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/sequences/at.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/sequences/back.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/sequences/clear.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/sequences/contains.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/sequences/erase.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/sequences/filled_list.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/sequences/front.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/sequences/has_key.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/sequences/insert.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/sequences/keys_as_sequence.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/sequences/list.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/sequences/make_sequence.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/sequences/map.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/sequences/pair.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/sequences/range.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/sequences/set.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/sequences/size.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/sequences/values_as_sequence.hpp
)

set(TYPES_GROUP
    ${PROJECT_SOURCE_DIR}/include/brigand/types/args.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/types/bool.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/types/empty_base.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/types/has_type.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/types/inherit.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/types/inherit_linearly.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/types/integer.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/types/integral_constant.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/types/no_such_type.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/types/operators.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/types/real.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/types/type.hpp
    ${PROJECT_SOURCE_DIR}/include/brigand/types/voidp.hpp
)

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

set(BRIGAND_HEADERS ${BRIGAND_GROUP}
    ${ADAPTED_GROUP}
    ${ALGORITHMS_GROUP}
    ${ALGORITHMS_DETAIL_GROUP}
    ${FUNCTIONS_GROUPS}
    ${FUNCTIONS_ARITHMETIC_GROUP}
    ${FUNCTIONS_BITWISE_GROUP}
    ${FUNCTIONS_LAMBDA_GROUP}
    ${FUNCTIONS_LOGICAL_GROUP}
    ${FUNCTIONS_MISC_GROUP}
    ${FUNCTIONS_COMPARISON_GROUP}
    ${SEQUENCES_GROUP}
    ${TYPES_GROUP})

include(CTest)
if(BUILD_TESTING)
    add_subdirectory(test)
endif()

configure_file(libbrigand.pc.in
    libbrigand.pc
    @ONLY
)

install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/brigand
    DESTINATION include
)

install(FILES ${CMAKE_BINARY_DIR}/libbrigand.pc
    DESTINATION lib/pkgconfig
)

include(SetupDoxygen)
include(SetupStandardese)

option(BUILD_EXAMPLES "Build examples" ${BUILD_TESTING})
if(BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()
