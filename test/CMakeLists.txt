set(test_files
    always.cpp
    apply.cpp
    args.cpp
    bind.cpp
    bitwise_test.cpp
    comparison_test.cpp
    count_test.cpp
    config_test.cpp
    eval_if_test.cpp
    erase_c_test.cpp
    find.cpp
    flatten.cpp
    fold.cpp
    for_each.cpp
    identity.cpp
    if_test.cpp
    index_of.cpp
    include_test.cpp
    inherit.cpp
    inherit_linearly.cpp
    integer.cpp
    integral_list_test.cpp
    integral_test.cpp
    is_set_test.cpp
    keys_as_sequence.cpp
    list_test.cpp
    logical_test.cpp
    main.cpp
    make_sequence_test.cpp
    map_test.cpp
    merge_test.cpp
    pair_test.cpp
    partition_test.cpp
    predicate_reduction_test.cpp
    range_test.cpp
    real.cpp
    remove_test.cpp
    repeat_test.cpp
    replace.cpp
    reverse_test.cpp
    select.cpp
    set_test.cpp
    sizeof.cpp
    sort_test.cpp
    split.cpp
    split_at.cpp
    transform.cpp
    tuple_test.cpp
    values_as_sequence.cpp
)

if(Boost_FOUND)
    set(test_files
        ${test_files}
        variant_test.cpp
        fusion_test.cpp)
endif()

source_group(tests FILES ${test_files})

add_executable(brigand_test ${test_files})

IF(${CMAKE_MAJOR_VERSION} GREATER 2)
    add_library(brigand INTERFACE)
    add_custom_target(brigand_headers SOURCES ${BRIGAND_HEADERS})
    target_link_libraries(brigand_test brigand)
ENDIF()

add_test(NAME brigand_test COMMAND brigand_test)
