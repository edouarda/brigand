#include <brigand/algorithms/product.hpp>
#include <type_traits>

using li = brigand::list<int, bool, char>;
using lo = brigand::list<float, double>;

using cart = brigand::product<li, lo>;
using lazy_cart = brigand::lazy::product<li, lo>;
using cart_expected = brigand::list<brigand::list<int, float>, brigand::list<int, double>, brigand::list<bool, float>, brigand::list<bool, double>, brigand::list<char, float>, brigand::list<char, double> >;
static_assert(std::is_same<cart, cart_expected>::value, "invalid product");
static_assert(std::is_same<lazy_cart, cart_expected>::value, "invalid product");
