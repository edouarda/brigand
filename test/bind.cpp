#include <brigand/functions.hpp>
#include <type_traits>

template<typename T1>
using f1 = T1;


template< typename T1, typename T2, typename T3, typename T4, typename T5 >
using f5 = T5;


static_assert (std::is_same < brigand::apply< brigand::bind<f1, brigand::_1>, int>
  , int
>::value
, "Invalid bind result"
);

static_assert (std::is_same < brigand::apply < brigand::bind<f1, brigand::_5>
  , void, void, void, void, int
>
, int
>::value
, "Invalid bind result"
);

static_assert (std::is_same
  < brigand::apply< brigand::bind<f5, brigand::_1, brigand::_2
  , brigand::_3, brigand::_4
  , brigand::_5
  >
  , void, void, void, void, int
  >
  , int
  >::value
  , "Invalid bind result"
  );

static_assert (std::is_same
  < brigand::apply< brigand::bind<f5, brigand::_5, brigand::_3
  , brigand::_4, brigand::_2
  , brigand::_1
  >
  , int, void, void, void, void
  >
  , int
  >::value
  , "Invalid bind result"
  );
