#include <brigand/functions.hpp>
#include <type_traits>

static_assert(brigand::apply<std::is_same<brigand::_1,int>,float>::value == false, "invalid apply1 result");
static_assert(brigand::apply<std::is_same<int,brigand::_1>,int>::value   == true, "invalid apply2 result");

static_assert ( brigand::apply < std::is_same<brigand::_5, brigand::_1>
                                , float,void,void,void,float
                                >::value == true
              , "invalid apply3 result"
              );
