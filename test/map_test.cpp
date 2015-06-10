
#include <brigand/map.hpp>
#include <brigand/size.hpp>
#include <brigand/at.hpp>

// empty maps are allowed
static_assert(brigand::size<brigand::map<>>::value == 0, "empty map isn't empty");
static_assert(std::is_same<brigand::lookup<brigand::map<>, int>::type, brigand::no_such_type_>::value, "should find no such type in empty map");

using map_test = brigand::map<brigand::pair<int, bool>, brigand::pair<char, int>>;

static_assert(std::is_same<brigand::lookup<map_test, int>::type, int>::value, "should be bool");
static_assert(std::is_same<brigand::lookup<map_test, char>::type, int>::value, "should be int");
static_assert(std::is_same<brigand::lookup<map_test, bool>::type, brigand::no_such_type_>::value, "should be not found");