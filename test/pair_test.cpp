
#include <utility>

#include <brigand/list.hpp>
#include <brigand/adapted/pair.hpp>

using test_list = brigand::list<int, char>;

static_assert(std::is_same<std::pair<int, char>, brigand::as_pair<test_list>::type>::value, "error in brigand::as_pair");
