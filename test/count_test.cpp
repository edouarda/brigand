
#include <brigand/algorithms/count.hpp>
#include <brigand/sequences/list.hpp>
#include <brigand/types/integer.hpp>
#include <type_traits>


template <typename N>
using is_odd = brigand::bool_t<(N::value % 2) != 0>;

template <typename N>
struct lazy_is_odd {
	using type = brigand::bool_t<(N::value % 2) != 0>;
};

template <std::size_t... List>
using size_t_list = brigand::integral_list<std::size_t, List...>;
using full_list = size_t_list<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11>;

using l1 = brigand::count_if<full_list, brigand::bind<is_odd, brigand::_1>>;
using l2 = brigand::count_if<full_list, lazy_is_odd<brigand::_1>>;

static_assert(l1::value == 6, "eager count_if error");
static_assert(l2::value == 6, "lazy count_if error");
