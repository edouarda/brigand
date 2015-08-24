
#include <brigand/types/bool.hpp>
#include <brigand/sequences/list.hpp>
#include <brigand/functions/greater.hpp>
#include <brigand/functions/less.hpp>
#include <brigand/algorithms/sort.hpp>
#include <type_traits>
#include <cstddef>

template <std::size_t... List>
using size_t_list = brigand::integral_list<std::size_t, List...>;

template <typename Lhs, typename Rhs>
using meta_sizeof = brigand::bool_<sizeof(Lhs) < sizeof(Rhs)>;

namespace test1 {
using result = brigand::sort<size_t_list<3, 7, 8, 5, 2, 1, 9, 4>, brigand::less>;
static_assert ( std::is_same<result, size_t_list<1, 2, 3, 4, 5, 7, 8, 9> >::value
              , "invalid sort of size_t list"
              );
}

namespace test2 {
using result = brigand::sort<size_t_list<3, 7, 8, 5, 2, 1, 9, 4>, brigand::greater>;
static_assert ( std::is_same<result, size_t_list<9, 8, 7, 5, 4, 3, 2, 1> >::value
              , "invalid sort of size_t list"
              );
}

namespace test3 {
using result = brigand::sort<brigand::empty_list, brigand::less>;
static_assert ( std::is_same<result, brigand::empty_list>::value
              , "invalid sort of empty list"
              );
}

namespace test4 {
using sorted = size_t_list<0, 1, 2, 3, 4>;
using result = brigand::sort<sorted, brigand::less>;
static_assert ( std::is_same<result, sorted>::value
              , "invalid sort of sorted list"
              );
}

namespace test5 {
using type_list        = brigand::list<double, short, char, int>;
using sorted_type_list = brigand::list<char, short, int, double>;
using result           = brigand::sort<type_list, meta_sizeof>;
static_assert ( std::is_same<result, sorted_type_list>::value
              , "invalid sort of type list (with sizeof predicate)"
              );
}
