
#include <brigand/functions.hpp>
#include <type_traits>

static_assert(brigand::invoke<std::is_same<brigand::_1,int>,float>::value == false, "invalid invoke result");
static_assert(brigand::invoke<std::is_same<int,brigand::_1>,int>::value   == true, "invalid invoke result");

static_assert ( brigand::invoke < std::is_same< brigand::_5
                                              , brigand::_1
                                              >
                                , float,void,void,void,float
                                >::value == true
              , "invalid invoke result"
              );


