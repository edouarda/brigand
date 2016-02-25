#include <brigand/algorithms/partition.hpp>
#include <brigand/algorithms/wrap.hpp>
#include <brigand/functions/lambda/bind.hpp>
#include <brigand/functions/lambda/quote.hpp>
#include <brigand/sequences/list.hpp>
#include <brigand/types/integer.hpp>
#include <type_traits>

template <typename N>
using is_odd = brigand::size_t<(N::value % 2) != 0>;

template <std::size_t... List>
using size_t_list = brigand::integral_list<std::size_t, List...>;

using odd_list = size_t_list<1, 3, 5, 7, 9, 11>;
using even_list = size_t_list<0, 2, 4, 6, 8, 10>;
using full_list = size_t_list<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11>;

brigand::partition<odd_list, brigand::quote<is_odd>> partition_test1 =
    brigand::pair<odd_list, size_t_list<>>{};
brigand::partition<even_list, brigand::quote<is_odd>> partition_test2 =
    brigand::pair<size_t_list<>, even_list>{};
brigand::partition<full_list, brigand::quote<is_odd>> partition_test3 =
    brigand::pair<odd_list, even_list>{};

brigand::partition<size_t_list<>, brigand::quote<is_odd>> partition_test4 =
    brigand::pair<size_t_list<>, size_t_list<>>{};

brigand::partition<brigand::list<int, float, char, double>, std::is_floating_point<brigand::_1>>
    partition_test5 = brigand::pair<brigand::list<float, double>, brigand::list<int, char>>{};
// custom list tests
namespace custom
{
template <class...>
class custom_list
{
};
template <std::size_t... List>
using size_t_list = brigand::wrap<brigand::integral_list<std::size_t, List...>, custom_list>;

using odd_list = size_t_list<1, 3, 5, 7, 9, 11>;
using even_list = size_t_list<0, 2, 4, 6, 8, 10>;
using full_list = size_t_list<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11>;

brigand::partition<odd_list, brigand::quote<is_odd>> partition_test1 =
    brigand::pair<odd_list, size_t_list<>>{};
brigand::partition<even_list, brigand::quote<is_odd>> partition_test2 =
    brigand::pair<size_t_list<>, even_list>{};
brigand::partition<full_list, brigand::quote<is_odd>> partition_test3 =
    brigand::pair<odd_list, even_list>{};

brigand::partition<size_t_list<>, brigand::quote<is_odd>> partition_test4 =
    brigand::pair<size_t_list<>, size_t_list<>>{};

brigand::partition<brigand::list<int, float, char, double>, std::is_floating_point<brigand::_1>>
    partition_test5 = brigand::pair<brigand::list<float, double>, brigand::list<int, char>>{};
}