
#include <boost/variant.hpp>

#include <brigand/adapted/variant.hpp>
#include <brigand/sequences/list.hpp>

using test_list = brigand::list<int, bool, char>;

static_assert(std::is_same<boost::variant<int, bool, char>, brigand::as_variant<test_list>>::value,
              "error in brigand::make_variant");

template <class...>
class custom_list
{
};

using test_list2 = custom_list<int, bool, char>;

static_assert(std::is_same<boost::variant<int, bool, char>, brigand::as_variant<test_list2>>::value,
              "error in brigand::make_variant");
