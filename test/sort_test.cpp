#include <brigand/algorithms/sort.hpp>
#include <brigand/functions/comparison/greater.hpp>
#include <brigand/functions/comparison/less.hpp>
#include <brigand/functions/misc/sizeof.hpp>
#include <brigand/sequences/list.hpp>
#include <brigand/types/bool.hpp>
#include <cstddef>

template <unsigned int... List>
using size_t_list = brigand::integral_list<unsigned int, List...>;

size_t_list<4> sort_test1 = brigand::sort<size_t_list<4>>{};
size_t_list<4> sort_test2 = brigand::sort<size_t_list<4>, brigand::greater<brigand::_1, brigand::_2>>{};

size_t_list<1, 4> sort_test3 = brigand::sort<size_t_list<1, 4>>{};
size_t_list<4, 1> sort_test4 = brigand::sort<size_t_list<1, 4>, brigand::greater<brigand::_1, brigand::_2>>{};

size_t_list<1, 2, 3> sort_test5 = brigand::sort<size_t_list<3, 2, 1>>{};
size_t_list<3, 2, 1> sort_test6 =
brigand::sort<size_t_list<3, 2, 1>, brigand::greater<brigand::_1, brigand::_2>>{};

size_t_list<1, 1, 2, 3, 4, 5, 7> sort_test7 = brigand::sort<size_t_list<3, 7, 5, 2, 1, 1, 4>>{};
size_t_list<7, 5, 4, 3, 2, 1, 1> sort_test8 =
brigand::sort<size_t_list<3, 5, 2, 1, 4, 1, 7>, brigand::greater<brigand::_1, brigand::_2>>{};

size_t_list<1, 2, 3, 4, 5, 7, 8, 9> sort_test9 =
brigand::sort<size_t_list<3, 7, 8, 5, 2, 1, 9, 4>>{};
size_t_list<9, 8, 7, 5, 4, 3, 2, 1> sort_test10 =
brigand::sort<size_t_list<3, 7, 8, 5, 2, 1, 9, 4>, brigand::greater<brigand::_1, brigand::_2>>{};

size_t_list<1, 1, 2, 3, 4, 5, 7, 8, 9> sort_test11 =
brigand::sort<size_t_list<3, 7, 8, 5, 2, 1, 9, 4, 1>>{};
size_t_list<9, 8, 7, 5, 4, 3, 2, 1, 1> sort_test12 =
brigand::sort<size_t_list<3, 7, 8, 5, 2, 1, 9, 4, 1>, brigand::greater<brigand::_1, brigand::_2>>{};

size_t_list<1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15> sort_test13 =
brigand::sort<size_t_list<15, 3, 7, 8, 5, 2, 1, 9, 4, 10, 11, 12, 6, 14, 13>>{};
size_t_list<15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1> sort_test14 =
brigand::sort<size_t_list<1, 7, 8, 5, 13, 3, 9, 4, 10, 11, 12, 6, 14, 15, 2>,
  brigand::greater<brigand::_1, brigand::_2>>{};

size_t_list<1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16> sort_test15 =
brigand::sort<size_t_list<16, 3, 7, 8, 5, 2, 1, 9, 4, 10, 11, 12, 6, 14, 15, 13>>{};
size_t_list<16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1> sort_test16 =
brigand::sort<size_t_list<16, 3, 7, 8, 5, 2, 1, 9, 4, 10, 11, 12, 6, 14, 15, 13>,
  brigand::greater<brigand::_1, brigand::_2>>{};

size_t_list<1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17> sort_test17 =
brigand::sort<size_t_list<3, 7, 16, 17, 8, 5, 2, 1, 9, 4, 10, 11, 12, 6, 14, 15, 13>>{};
size_t_list<17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1> sort_test18 =
brigand::sort<size_t_list<3, 7, 16, 17, 8, 5, 2, 1, 9, 4, 10, 11, 12, 6, 14, 15, 13>,
  brigand::greater<brigand::_1, brigand::_2>>{};

size_t_list<1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18> sort_test19 =
brigand::sort<size_t_list<3, 7, 16, 17, 18, 8, 5, 2, 1, 9, 4, 10, 11, 12, 6, 14, 15, 13>>{};
size_t_list<18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1> sort_test20 =
brigand::sort<size_t_list<3, 7, 16, 17, 18, 8, 5, 2, 1, 9, 4, 10, 11, 12, 6, 14, 15, 13>,
  brigand::greater<brigand::_1, brigand::_2>>{};

brigand::empty_sequence sort_test21 = brigand::sort<brigand::empty_sequence>{};

using sorted = size_t_list<0, 1, 2, 3, 4>;
sorted sort_test22 = brigand::sort<sorted>{};

using type_list = brigand::list<double, short, char, int>;
using sorted_type_list = brigand::list<char, short, int, double>;

template <typename Lhs, typename Rhs>
using less_sizeof = brigand::bool_<sizeof(Lhs) < sizeof(Rhs)>;

sorted_type_list sort_test23 = brigand::sort<type_list, brigand::bind<less_sizeof, brigand::_1, brigand::_2>>{};
sorted_type_list sort_test24 =
brigand::sort<type_list,
  brigand::less<brigand::sizeof_<brigand::_1>, brigand::sizeof_<brigand::_2>>>{};

size_t_list<1, 2> sort_test25 = brigand::sort<size_t_list<2, 1>>{};
size_t_list<1> sort_test26 = brigand::sort<size_t_list<1>>{};

namespace custom
{
  template <class...>
  class custom_list
  {
  };

  template <int... Is>
  using custom_int_list = brigand::wrap<brigand::integral_list<int, Is...>, custom_list>;

  custom_int_list<4> sort_test1 = brigand::sort<custom_int_list<4>>{};
  custom_int_list<4> sort_test2 =
    brigand::sort<custom_int_list<4>, brigand::greater<brigand::_1, brigand::_2>>{};

  custom_int_list<1, 4> sort_test3 = brigand::sort<custom_int_list<1, 4>>{};
  custom_int_list<4, 1> sort_test4 =
    brigand::sort<custom_int_list<1, 4>, brigand::greater<brigand::_1, brigand::_2>>{};

  custom_int_list<1, 2, 3> sort_test5 = brigand::sort<custom_int_list<3, 2, 1>>{};
  custom_int_list<3, 2, 1> sort_test6 =
    brigand::sort<custom_int_list<3, 2, 1>, brigand::greater<brigand::_1, brigand::_2>>{};

  custom_int_list<1, 1, 2, 3, 4, 5, 7> sort_test7 =
    brigand::sort<custom_int_list<3, 7, 5, 2, 1, 1, 4>>{};
  custom_int_list<7, 5, 4, 3, 2, 1, 1> sort_test8 =
    brigand::sort<custom_int_list<3, 5, 2, 1, 4, 1, 7>, brigand::greater<brigand::_1, brigand::_2>>{};

  custom_int_list<1, 2, 3, 4, 5, 7, 8, 9> sort_test9 =
    brigand::sort<custom_int_list<3, 7, 8, 5, 2, 1, 9, 4>>{};
  custom_int_list<9, 8, 7, 5, 4, 3, 2, 1> sort_test10 =
    brigand::sort<custom_int_list<3, 7, 8, 5, 2, 1, 9, 4>, brigand::greater<brigand::_1, brigand::_2>>{};

  custom_int_list<1, 1, 2, 3, 4, 5, 7, 8, 9> sort_test11 =
    brigand::sort<custom_int_list<3, 7, 8, 5, 2, 1, 9, 4, 1>>{};
  custom_int_list<9, 8, 7, 5, 4, 3, 2, 1, 1> sort_test12 =
    brigand::sort<custom_int_list<3, 7, 8, 5, 2, 1, 9, 4, 1>, brigand::greater<brigand::_1, brigand::_2>>{};

  custom_int_list<1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15> sort_test13 =
    brigand::sort<custom_int_list<15, 3, 7, 8, 5, 2, 1, 9, 4, 10, 11, 12, 6, 14, 13>>{};
  custom_int_list<15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1> sort_test14 =
    brigand::sort<custom_int_list<1, 7, 8, 5, 13, 3, 9, 4, 10, 11, 12, 6, 14, 15, 2>,
    brigand::greater<brigand::_1, brigand::_2>>{};

  custom_int_list<1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16> sort_test15 =
    brigand::sort<custom_int_list<16, 3, 7, 8, 5, 2, 1, 9, 4, 10, 11, 12, 6, 14, 15, 13>>{};
  custom_int_list<16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1> sort_test16 =
    brigand::sort<custom_int_list<16, 3, 7, 8, 5, 2, 1, 9, 4, 10, 11, 12, 6, 14, 15, 13>,
    brigand::greater<brigand::_1, brigand::_2>>{};

  custom_int_list<1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17> sort_test17 =
    brigand::sort<custom_int_list<3, 7, 16, 17, 8, 5, 2, 1, 9, 4, 10, 11, 12, 6, 14, 15, 13>>{};
  custom_int_list<17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1> sort_test18 =
    brigand::sort<custom_int_list<3, 7, 16, 17, 8, 5, 2, 1, 9, 4, 10, 11, 12, 6, 14, 15, 13>,
    brigand::greater<brigand::_1, brigand::_2>>{};

  custom_int_list<1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18> sort_test19 =
    brigand::sort<custom_int_list<3, 7, 16, 17, 18, 8, 5, 2, 1, 9, 4, 10, 11, 12, 6, 14, 15, 13>>{};
  custom_int_list<18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1> sort_test20 =
    brigand::sort<custom_int_list<3, 7, 16, 17, 18, 8, 5, 2, 1, 9, 4, 10, 11, 12, 6, 14, 15, 13>,
    brigand::greater<brigand::_1, brigand::_2>>{};

  brigand::empty_sequence sort_test21 = brigand::sort<brigand::empty_sequence>{};

  using sorted = custom_int_list<0, 1, 2, 3, 4>;
  sorted sort_test22 = brigand::sort<sorted>{};

  using type_list = brigand::list<double, short, char, int>;
  using sorted_type_list = brigand::list<char, short, int, double>;

  template <typename Lhs, typename Rhs>
  using less_sizeof = brigand::bool_<sizeof(Lhs) < sizeof(Rhs)>;

  sorted_type_list sort_test23 = brigand::sort<type_list, brigand::bind<less_sizeof, brigand::_1, brigand::_2>>{};
  sorted_type_list sort_test24 =
    brigand::sort<type_list,
    brigand::less<brigand::sizeof_<brigand::_1>, brigand::sizeof_<brigand::_2>>>{};

  custom_int_list<1, 2> sort_test25 = brigand::sort<custom_int_list<2, 1>>{};
  custom_int_list<1> sort_test26 = brigand::sort<custom_int_list<1>>{};
}

