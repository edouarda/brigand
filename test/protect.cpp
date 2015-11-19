#include <brigand/functions.hpp>
#include <brigand/types/type.hpp>

static_assert(std::is_same<brigand::apply<brigand::protect<brigand::type_<brigand::_1>>,int>, brigand::type_<brigand::_1>>::value, "invalid protect result");
static_assert(std::is_same<brigand::apply<brigand::protect<brigand::type_<brigand::protect<brigand::_1>>>,int>, brigand::type_<brigand::protect<brigand::_1>>>::value, "invalid protect result");

template<class T>
struct type_applier
{
  template<class...>
  struct apply { using type = T; };
};

brigand::apply<type_applier<brigand::protect<brigand::type_<brigand::_1>>>, int> protet_test1
  =                         brigand::protect<brigand::type_<brigand::_1>>{};
