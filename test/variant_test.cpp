
#include <boost/variant.hpp>

#include <brigand/list.hpp>
#include <brigand/variant/make_variant.hpp>

using test_list = brigand::list<int, bool, char>;

static_assert(std::is_same<boost::variant<int, bool, char>, brigand::make_variant_over<test_list>::type>::value, "error in brigand::make_variant");
