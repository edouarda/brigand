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

template <typename T>
using run_in_defer = brigand::apply<brigand::apply<brigand::defer<T>, char, bool>, double, float>;
template <typename T>
using eager_identity = T;
static_assert(std::is_same<run_in_defer<int>, int>::value, "defer<type> broken");
static_assert(std::is_same<run_in_defer<brigand::bind<eager_identity, int>>, int>::value, "defer<bind> broken");
static_assert(std::is_same<run_in_defer<brigand::always<int>>, int>::value, "defer<lazy> broken");
static_assert(std::is_same<run_in_defer<brigand::pin<brigand::list<int>>>, brigand::list<int>>::value, "defer<pin> broken");
static_assert(std::is_same<run_in_defer<brigand::_1>, double>::value, "defer<_1> broken");
static_assert(std::is_same<run_in_defer<brigand::_2>, float>::value, "defer<_2> broken");
static_assert(std::is_same<run_in_defer<brigand::args<0>>, double>::value, "defer<args> broken");
static_assert(std::is_same<run_in_defer<brigand::parent<brigand::_1>>, char>::value, "defer<parent> broken");
static_assert(std::is_same<brigand::apply<run_in_defer<brigand::defer<int>>>, int>::value, "defer<defer> broken");
static_assert(std::is_same<run_in_defer<brigand::apply<brigand::defer<int>>>, int>::value, "defer<lcall> broken");

template <typename T>
using run_in_nested_defer = brigand::apply<brigand::apply<brigand::defer<brigand::apply<brigand::apply<brigand::defer<brigand::defer<T>>, int>, float>>, double>, bool>;
using test_capture = brigand::bind<brigand::list, brigand::_1, brigand::parent<brigand::_1>, brigand::parent<brigand::parent<brigand::_1>>>;
static_assert(std::is_same<run_in_nested_defer<brigand::bind<eager_identity, test_capture>>, brigand::list<bool, float, int>>::value, "parent broken in defer<bind>");
static_assert(std::is_same<run_in_nested_defer<brigand::always<test_capture>>, brigand::list<bool, float, int>>::value, "parent broken in defer<lazy>");
static_assert(std::is_same<run_in_nested_defer<brigand::parent<brigand::bind<brigand::list, brigand::_1, brigand::parent<brigand::_1>>>>, brigand::list<float, int>>::value, "parent broken in defer<parent>");
static_assert(std::is_same<brigand::apply<run_in_nested_defer<brigand::defer<test_capture>>, char>, brigand::list<char, bool, float>>::value, "parent broken in defer<defer>");
// The capture groups in defer<lcall> are ignored

using li = brigand::list<int, bool, char>;
using lo = brigand::list<float, double>;

using cart = brigand::reverse_fold<brigand::list<li, lo>, brigand::list<brigand::list<>>, brigand::bind<brigand::join, brigand::bind<brigand::transform, brigand::_2, brigand::defer<brigand::bind<brigand::join, brigand::bind<brigand::transform, brigand::parent<brigand::_1>, brigand::defer<brigand::bind<brigand::list, brigand::bind<brigand::push_front, brigand::_1, brigand::parent<brigand::_1>>>>>>>>>>;
using lazy_cart = brigand::reverse_fold<brigand::list<li, lo>, brigand::list<brigand::list<>>, brigand::lazy::join<brigand::lazy::transform< brigand::_2, brigand::defer<brigand::lazy::join< brigand::lazy::transform< brigand::parent<brigand::_1>, brigand::defer<brigand::bind<brigand::list, brigand::lazy::push_front< brigand::_1, brigand::parent<brigand::_1>>>>>>>>>>;
using cart_expected = brigand::list<brigand::list<int, float>, brigand::list<int, double>, brigand::list<bool, float>, brigand::list<bool, double>, brigand::list<char, float>, brigand::list<char, double> >;
static_assert(std::is_same<cart, cart_expected>::value, "invalid cartesian product");
static_assert(std::is_same<lazy_cart, cart_expected>::value, "invalid cartesian product");


