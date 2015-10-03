#include <brigand/functions.hpp>
#include <brigand/types/type.hpp>
#include <type_traits>

static_assert(std::is_same<brigand::apply<brigand::protect<brigand::type_<brigand::_1>>,int>,brigand::type_<brigand::_1>>::value, "invalid protect result");
