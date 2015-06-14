
#include <brigand/list.hpp>
#include <brigand/find.hpp>
#include <type_traits>

template<typename T> using is_float = typename std::is_floating_point<T>::type;

static_assert ( std::is_same< brigand::find<brigand::list<>,is_float>
                            , brigand::list<>
                            >::value
              , "invalid fold on empty list"
              );

static_assert ( std::is_same< brigand::find < brigand::list<int,int,int,float,char>
                                            , is_float
                                            >
                            , brigand::list<float,char>
                            >::value
              , "invalid fold on list"
              );

static_assert ( std::is_same< brigand::find<brigand::integral_list<int,0,0,0,0,0,1,99,0,0>>
                            , brigand::integral_list<int,1,99,0,0>
                            >::value
              , "invalid fold on values list"
              );

static_assert ( brigand::not_found< brigand::empty_list>::value
              , "invalid not_found on empty list"
              );

static_assert ( brigand::not_found< brigand::integral_list<int,0,0,0,0,0,0>>::value
              , "invalid not_found on values list"
              );

static_assert ( brigand::not_found< brigand::list<int,int,char>
                                  , is_float
                                  >::value
              , "invalid not_found on list"
              );

static_assert ( !brigand::found<brigand::empty_list>::value
              , "invalid found on empty list"
              );

static_assert ( brigand::found< brigand::integral_list<int,0,0,7,0,0,0>>::value
              , "invalid found on values list"
              );

static_assert ( brigand::found< brigand::list<int,int,double,char>
                              , is_float
                              >::value
              , "invalid found on list"
              );
