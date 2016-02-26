
#include <tuple>

#include <brigand/adapted/tuple.hpp>
#include <brigand/sequences/list.hpp>

using test_list = brigand::list<int, bool, char>;

static_assert(std::is_same<std::tuple<int, bool, char>, brigand::as_tuple<test_list>>::value,
              "error in brigand::as_tuple");

template <class...>
class custom_list
{
};

using test_list2 = custom_list<int, bool, char>;

static_assert(std::is_same<std::tuple<int, bool, char>, brigand::as_tuple<test_list2>>::value,
              "error in brigand::as_tuple");
