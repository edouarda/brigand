
#include <brigand/types/bool.hpp>
#include <brigand/sequences/list.hpp>
#include <brigand/algorithms/partition.hpp>
#include <type_traits>

template<typename N>
using is_odd = brigand::bool_<(N::value & 1) != 0>;

template<typename T>
using is_float = typename std::is_floating_point<T>::type;

template <std::size_t... List>
using size_t_list = brigand::integral_list<std::size_t, List...>;

using  odd_list = size_t_list<1, 3, 5, 7, 9, 11>;
using even_list = size_t_list<0, 2, 4, 6, 8, 10>;
using full_list = size_t_list<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11>;

namespace test1 {
using result = brigand::partition<full_list, is_odd>;
static_assert ( std::is_same<result::first_type,   odd_list>::value &&
                std::is_same<result::second_type, even_list>::value
              , "invalid partition on odd/even list"
              );
}

namespace test2 {
using result = brigand::partition<odd_list, is_odd>;
static_assert ( std::is_same<result::first_type,  odd_list>::value &&
                std::is_same<result::second_type, brigand::empty_list>::value
              , "invalid partition on odd list"
              );
}

namespace test3 {
using result = brigand::partition<even_list, is_odd>;
static_assert ( std::is_same<result::first_type,  brigand::empty_list>::value &&
                std::is_same<result::second_type, even_list>::value
              , "invalid partition on even list"
              );
}

namespace test4 {
using result = brigand::partition<brigand::empty_list, is_odd>;
static_assert ( std::is_same<result::first_type,  brigand::empty_list>::value &&
                std::is_same<result::second_type, brigand::empty_list>::value
              , "invalid partition on empty_list"
              );
}

namespace test5 {
using result = brigand::partition<brigand::list<int, float, char, double>, is_float>;
static_assert ( std::is_same<result::first_type,  brigand::list<float, double> >::value &&
                std::is_same<result::second_type, brigand::list<int, char> >::value
              , "invalid partition on types list"
              );
}
