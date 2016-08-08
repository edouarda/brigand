#include <brigand/functions.hpp>
#include <brigand/algorithms/fold.hpp>
#include <brigand/algorithms/transform.hpp>
#include <brigand/sequences/append.hpp>
#include <type_traits>

static_assert(brigand::apply<std::is_same<brigand::_1, int>, float>::value == false, "invalid apply1 result");
static_assert(brigand::apply<std::is_same<int, brigand::_1>, int>::value == true, "invalid apply2 result");

static_assert (brigand::apply < std::is_same<brigand::_5, brigand::_1>
	, float, void, void, void, float
>::value == true
, "invalid apply3 result"
);

template<typename T>
struct is_int
{
	using type = typename std::is_same<T, int>::type;
};

static_assert(brigand::apply<is_int<brigand::_1>, float>::value == false, "invalid apply1 result");
static_assert(brigand::apply<is_int<brigand::_1>, int>::value == true, "invalid apply2 result");

using li = brigand::list<int, bool, char>;
using lo = brigand::list<float, double>;

using cart = brigand::reverse_fold<brigand::list<li, lo>, brigand::list<brigand::list<>>, brigand::bind<brigand::join, brigand::bind<brigand::transform, brigand::_2, brigand::defer<brigand::bind<brigand::join, brigand::bind<brigand::transform, brigand::parent<brigand::_1>, brigand::defer<brigand::bind<brigand::list, brigand::bind<brigand::push_front, brigand::_1, brigand::parent<brigand::_1>>>>>>>>>>;
using lazy_cart = brigand::reverse_fold<brigand::list<li, lo>, brigand::list<brigand::list<>>, brigand::lazy::join<brigand::lazy::transform< brigand::_2, brigand::defer<brigand::lazy::join< brigand::lazy::transform< brigand::parent<brigand::_1>, brigand::defer<brigand::bind<brigand::list, brigand::lazy::push_front< brigand::_1, brigand::parent<brigand::_1>>>>>>>>>>;
using cart_expected = brigand::list<brigand::list<int, float>, brigand::list<int, double>, brigand::list<bool, float>, brigand::list<bool, double>, brigand::list<char, float>, brigand::list<char, double> >;
static_assert(std::is_same<cart, cart_expected>::value, "");
static_assert(std::is_same<lazy_cart, cart_expected>::value, "");


