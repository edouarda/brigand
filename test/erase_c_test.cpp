
#include <brigand/sequences/erase.hpp>
#include <brigand/sequences/list.hpp>
#include <type_traits>

static_assert(std::is_same<brigand::erase_c<brigand::list<int>, 0>, brigand::list<>>::value, "invalid erase_c result");
static_assert(std::is_same<brigand::erase_c<brigand::list<int, char, bool>, 0>, brigand::list<char, bool>>::value, "invalid erase_c result");
static_assert(std::is_same<brigand::erase_c<brigand::list<int, char, bool>, 1>, brigand::list<int, bool>>::value, "invalid erase_c result");
static_assert(std::is_same<brigand::erase_c<brigand::list<int, char, bool>, 2>, brigand::list<int, char>>::value, "invalid erase_c result");
