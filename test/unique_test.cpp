#include <brigand/algorithms/unique.hpp>

template <std::size_t... List>
using size_t_list = brigand::integral_list<std::size_t, List...>;

brigand::list<> unique_test_1 = brigand::unique<brigand::list<>>{};

size_t_list<1> unique_test_2 = brigand::unique<size_t_list<1>>{};
size_t_list<1> unique_test_3 = brigand::unique<size_t_list<1, 1>>{};
size_t_list<1> unique_test_4 = brigand::unique<size_t_list<1, 1, 1, 1, 1>>{};

size_t_list<1, 2, 0> unique_test_5 = brigand::unique<size_t_list<1, 1, 2, 0>>{};
size_t_list<1, 2, 0> unique_test_6 = brigand::unique<size_t_list<1, 1, 2, 0, 0>>{};
size_t_list<1, 2, 0> unique_test_7 = brigand::unique<size_t_list<1, 1, 2, 2, 2, 2, 0, 0>>{};
size_t_list<1, 2, 0> unique_test_8 = brigand::unique<size_t_list<1, 1, 2, 2, 2, 2, 0>>{};

size_t_list<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11> unique_test_9 =
  brigand::unique<size_t_list<0, 0, 1, 2, 3, 3, 3, 4, 5, 6, 7, 7, 8, 9, 9, 9, 9, 9, 10, 11>>{};

brigand::list<float, char, void*> unique_test_10 =
  brigand::unique<brigand::list<float, float, char, void*, void*, void*>>{};
