#include <brigand/types/bool.hpp>
#include <brigand/sequences/list.hpp>
#include <brigand/functions/comparison/greater.hpp>
#include <brigand/functions/comparison/less.hpp>
#include <brigand/functions/misc/sizeof.hpp>
#include <brigand/algorithms/sort.hpp>
#include <cstddef>

template <std::size_t... List>
using size_t_list = brigand::integral_list<std::size_t, List...>;

size_t_list<1, 2, 3, 4, 5, 7, 8, 9> sort_test1 = brigand::sort<size_t_list<3, 7, 8, 5, 2, 1, 9, 4>>{};
size_t_list<9, 8, 7, 5, 4, 3, 2, 1> sort_test2 = brigand::sort<size_t_list<3, 7, 8, 5, 2, 1, 9, 4>, brigand::quote<brigand::greater>>{};

brigand::empty_sequence sort_test3 = brigand::sort<brigand::empty_sequence>{};

using sorted = size_t_list<0, 1, 2, 3, 4>;
sorted sort_test4 = brigand::sort<sorted>{};


using type_list        = brigand::list<double, short, char, int>;
using sorted_type_list = brigand::list<char, short, int, double>;

template <typename Lhs, typename Rhs>
using less_sizeof = brigand::bool_<sizeof(Lhs) < sizeof(Rhs)>;

sorted_type_list sort_test5 = brigand::sort<type_list, brigand::quote<less_sizeof>>{};
sorted_type_list sort_test6 = brigand::sort<type_list, brigand::less<brigand::sizeof_<brigand::_1>, brigand::sizeof_<brigand::_2>>>{};
