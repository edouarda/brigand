
#include <brigand/sequences/list.hpp>
#include <brigand/algorithms/find.hpp>
#include <type_traits>

template<typename T> using is_float = typename std::is_floating_point<T>::type;

static_assert ( std::is_same< brigand::find<brigand::list<>,is_float>
                            , brigand::list<>
                            >::value
              , "invalid find on empty list"
              );

static_assert ( std::is_same< brigand::reverse_find<brigand::list<>,is_float>
                            , brigand::list<>
                            >::value
              , "invalid reverse_find on empty list"
              );

static_assert ( std::is_same< brigand::find < brigand::list<int,int,int,float,char>
                                            , is_float
                                            >
                            , brigand::list<float,char>
                            >::value
              , "invalid find on list"
              );

static_assert ( std::is_same< brigand::reverse_find < brigand::list<int,int,int,float,char>
                                                    , is_float
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
