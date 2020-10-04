
#include <brigand/algorithms/count.hpp>
#include <brigand/sequences/list.hpp>
#include <brigand/types/integer.hpp>
#include <brigand/types/bool.hpp>
#include <type_traits>


template <typename N>
using is_odd = brigand::bool_<(N::value % 2) != 0>;

template <typename N>
struct lazy_is_odd {
  using type = brigand::bool_<(N::value % 2) != 0>;
};

template <unsigned int... List>
using size_t_list = brigand::integral_list<unsigned int, List...>;
using full_list = size_t_list<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11>;

using l1 = brigand::count_if<full_list, brigand::bind<is_odd, brigand::_1>>;
using l2 = brigand::count_if<full_list, lazy_is_odd<brigand::_1>>;

static_assert(l1::value == 6, "eager count_if error");
static_assert(l2::value == 6, "lazy count_if error");
static_assert(brigand::count_if<brigand::list<>, lazy_is_odd<brigand::_1>>::value == 0, "eager empty count_if error");
static_assert(brigand::count_if<brigand::list<>, lazy_is_odd<brigand::_1>>::value == 0, "lazy empty count_if error");
static_assert(brigand::count_if<size_t_list<3>, lazy_is_odd<brigand::_1>>::value == 1, "eager single count_if error");
static_assert(brigand::count_if<size_t_list<3>, lazy_is_odd<brigand::_1>>::value == 1, "lazy single count_if error");
static_assert(brigand::count_if<size_t_list<2>, lazy_is_odd<brigand::_1>>::value == 0, "eager single count_if error");
static_assert(brigand::count_if<size_t_list<2>, lazy_is_odd<brigand::_1>>::value == 0, "lazy single count_if error");

template <typename>
struct true_false {
  static constexpr bool value = true;
  using type = brigand::false_type;
};
template <typename>
struct lazy_true_false {
  using type = true_false<void>;
};
static_assert(brigand::count_if<brigand::list<int>, lazy_true_false<void>>::value == 1, "lazy count_if error");
static_assert(brigand::count_if<brigand::list<int>, lazy_true_false<brigand::_1>>::value == 1, "lazy count_if error");
static_assert(brigand::count_if<brigand::list<int>, brigand::bind<true_false, void>>::value == 1, "eager count_if error");
static_assert(brigand::count_if<brigand::list<int>, brigand::bind<true_false, brigand::_1>>::value == 1, "eager count_if error");
