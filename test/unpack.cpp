#include <brigand/functions.hpp>
#include <type_traits>
#include <tuple>

static_assert ( brigand::apply < brigand::unpack<std::is_same<brigand::_5, brigand::_1>>
                                , brigand::list<float,void,void,void,float>
                                >::value == true
              , "invalid unpack result"
              );

static_assert ( brigand::apply< brigand::unpack<std::is_same<brigand::_2, brigand::_3>>
                              , std::tuple<void,float,float,void,void>
                              >::value == true
              , "invalid unpack result"
              );
