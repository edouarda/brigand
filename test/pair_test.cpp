
#include <utility>

#include <brigand/sequences/list.hpp>
#include <brigand/adapted/pair.hpp>

using test_list = brigand::list<int, char>;

static_assert(std::is_same<std::pair<int, char>, brigand::as_pair<test_list>>::value, "error in brigand::as_pair");
