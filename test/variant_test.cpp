
#include <boost/variant.hpp>

#include <brigand/list.hpp>
#include <brigand/adapted/variant.hpp>

using test_list = brigand::list<int, bool, char>;

static_assert(std::is_same<boost::variant<int, bool, char>, brigand::as_variant<test_list>>::value, "error in brigand::make_variant");
