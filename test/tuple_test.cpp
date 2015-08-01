
#include <tuple>

#include <brigand/sequences/list.hpp>
#include <brigand/adapted/tuple.hpp>

using test_list = brigand::list<int, bool, char>;

static_assert(std::is_same<std::tuple<int, bool, char>, brigand::as_tuple<test_list>>::value, "error in brigand::as_tuple");
