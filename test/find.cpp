
#include <brigand/sequences/list.hpp>
#include <brigand/algorithms/find.hpp>
#include <type_traits>

static_assert ( std::is_same< brigand::find<brigand::list<>,std::is_floating_point<brigand::_1>>
                            , brigand::list<>
                            >::value
              , "invalid find on empty list"
              );

static_assert ( std::is_same< brigand::reverse_find<brigand::list<>,std::is_floating_point<brigand::_1>>
                            , brigand::list<>
                            >::value
              , "invalid reverse_find on empty list"
              );

static_assert ( std::is_same< brigand::find < brigand::list<int,int,int,float,char>
                                            , std::is_floating_point<brigand::_1>
                                            >
                            , brigand::list<float,char>
                            >::value
              , "invalid find on list"
              );

static_assert ( std::is_same< brigand::reverse_find < brigand::list<int,int,int,float,char>
                                                    , std::is_floating_point<brigand::_1>
                                                    >
                            , brigand::list<int,int,int,float>
                            >::value
              , "invalid reverse_find on list"
              );

static_assert ( std::is_same< brigand::find<brigand::integral_list<int,0,0,0,0,0,1,99,0,0>>
                            , brigand::integral_list<int,1,99,0,0>
                            >::value
              , "invalid find on values list"
              );

static_assert ( std::is_same< brigand::reverse_find<brigand::integral_list<int,0,0,0,0,0,1,99,0,0>>
                            , brigand::integral_list<int,0,0,0,0,0,1,99>
                            >::value
              , "invalid reverse_find on values list"
              );

static_assert ( std::is_same< brigand::apply<brigand::lazy::reverse_find<brigand::_1, brigand::true_type>, brigand::list<int>>
                            , brigand::list<int>
                            >::value
              , "invalid lazy reverse_find"
              );

static_assert ( brigand::not_found< brigand::empty_sequence>::value
              , "invalid not_found on empty list"
              );

static_assert ( brigand::not_found< brigand::integral_list<int,0,0,0,0,0,0>>::value
              , "invalid not_found on values list"
              );

static_assert ( brigand::not_found< brigand::list<int,int,char>
                                  , std::is_floating_point<brigand::_1>
                                  >::value
              , "invalid not_found on list"
              );

static_assert ( !brigand::found<brigand::empty_sequence>::value
              , "invalid found on empty list"
              );

static_assert ( brigand::found< brigand::integral_list<int,0,0,7,0,0,0>>::value
              , "invalid found on values list"
              );

static_assert ( brigand::found< brigand::list<int,int,double,char>
                              , std::is_floating_point<brigand::_1>
                              >::value
              , "invalid found on list"
              );


template <class ...> class custom_list;

static_assert(brigand::not_found<custom_list<int, int, char>, std::is_floating_point<brigand::_1>>::value, "invalid not_found on list");
