#include <brigand/adapted/integral_list.hpp>
#include <brigand/algorithms/transform.hpp>
#include <brigand/algorithms/wrap.hpp>
#include <brigand/functions/arithmetic/identity.hpp>
#include <brigand/functions/arithmetic/minus.hpp>
#include <brigand/functions/arithmetic/plus.hpp>
#include <brigand/functions/if.hpp>
#include <brigand/sequences/list.hpp>
#include <brigand/types/args.hpp>
#include <type_traits>
#include <utility>

using list0 = brigand::list<>;

using list1 = brigand::list<int>;
using expect1 = brigand::list<int *>;
using expect1b = brigand::list<std::pair<int, int>>;

using list2 = brigand::list<float, double, int, char, void *>;
using expect2 = brigand::list<float *, double *, int *, char *, void **>;
using expect2b =
    brigand::list<std::pair<float, float>, std::pair<double, double>, std::pair<int, int>,
                  std::pair<char, char>, std::pair<void *, void *>>;
using expect2c = brigand::list<float *, double *, int *, char *, void *>;

// local functors to apply
using ptr_t = std::add_pointer<brigand::_1>;
using pair_t = std::pair<brigand::_1, brigand::_2>;

static_assert(std::is_same<brigand::transform<list0, std::add_pointer<brigand::_1>>, list0>::value,
              "invalid unary transform on empty list");

static_assert(std::is_same<brigand::transform<list0, ptr_t>, list0>::value,
              "invalid unary transform on empty list");

static_assert(std::is_same<brigand::transform<list0, list0, pair_t>, list0>::value,
              "invalid binary transform on empty list");

static_assert(std::is_same<brigand::transform<list1, ptr_t>, expect1>::value,
              "invalid unary transform on list");

static_assert(
    std::is_same<brigand::transform<list1, std::add_pointer<brigand::_1>>, expect1>::value,
    "invalid unary transform on list");

static_assert(std::is_same<brigand::transform<list1, list1, pair_t>, expect1b>::value,
              "invalid binary transform on list");

static_assert(std::is_same<brigand::transform<list2, ptr_t>, expect2>::value,
              "invalid unary transform on list");

static_assert(std::is_same<brigand::transform<list2, list2, pair_t>, expect2b>::value,
              "invalid binary transform on list");

static_assert(std::is_same<brigand::transform<list2, list2, pair_t>, expect2b>::value,
              "invalid binary transform on list");

static_assert(
    std::is_same<
        brigand::transform<brigand::list<void, char, int>,
                           std::add_pointer<std::add_pointer<std::add_pointer<brigand::_1>>>>,
        brigand::list<void ***, char ***, int ***>>::value,
    "invalid transform on list");

static_assert(std::is_same<brigand::transform<list2, brigand::if_<std::is_pointer<brigand::_1>,
                                                                  brigand::identity<brigand::_1>,
                                                                  std::add_pointer<brigand::_1>>>,
                           expect2c>::value,
              "invalid binary transform on list");

using sum_list = brigand::integral_list<int, 1, 2, 3>;

static_assert(std::is_same<brigand::as_integral_list<brigand::transform<
                               sum_list, sum_list, brigand::plus<brigand::_1, brigand::_2>>>,
                           brigand::integral_list<int, 2, 4, 6>>::value,
              "invalid transform sum");

static_assert(
    std::is_same<brigand::as_integral_list<brigand::transform<
                     sum_list, brigand::plus<brigand::_1, std::integral_constant<int, 2>>>>,
                 brigand::integral_list<int, 3, 4, 5>>::value,
    "invalid transform sum");

static_assert(
    std::is_same<brigand::as_integral_list<brigand::transform<
                     sum_list, brigand::minus<std::integral_constant<int, 10>, brigand::_1>>>,
                 brigand::integral_list<int, 9, 8, 7>>::value,
    "invalid transform sum");

namespace custom
{
template <class...>
class custom_list
{
};

template <int... Is>
using custom_int_list = brigand::wrap<brigand::integral_list<int, Is...>, custom_list>;
using list0 = custom_list<>;

using list1 = custom_list<int>;
using expect1 = custom_list<int *>;
using expect1b = custom_list<std::pair<int, int>>;

using list2 = custom_list<float, double, int, char, void *>;
using expect2 = custom_list<float *, double *, int *, char *, void **>;
using expect2b = custom_list<std::pair<float, float>, std::pair<double, double>,
                             std::pair<int, int>, std::pair<char, char>, std::pair<void *, void *>>;
using expect2c = custom_list<float *, double *, int *, char *, void *>;

// local functors to apply
using ptr_t = std::add_pointer<brigand::_1>;
using pair_t = std::pair<brigand::_1, brigand::_2>;

static_assert(std::is_same<brigand::transform<list0, std::add_pointer<brigand::_1>>, list0>::value,
              "invalid unary transform on empty list");

static_assert(std::is_same<brigand::transform<list0, ptr_t>, list0>::value,
              "invalid unary transform on empty list");

static_assert(std::is_same<brigand::transform<list0, list0, pair_t>, list0>::value,
              "invalid binary transform on empty list");

static_assert(std::is_same<brigand::transform<list1, ptr_t>, expect1>::value,
              "invalid unary transform on list");

static_assert(
    std::is_same<brigand::transform<list1, std::add_pointer<brigand::_1>>, expect1>::value,
    "invalid unary transform on list");

static_assert(std::is_same<brigand::transform<list1, list1, pair_t>, expect1b>::value,
              "invalid binary transform on list");

static_assert(std::is_same<brigand::transform<list2, ptr_t>, expect2>::value,
              "invalid unary transform on list");

static_assert(std::is_same<brigand::transform<list2, list2, pair_t>, expect2b>::value,
              "invalid binary transform on list");

static_assert(std::is_same<brigand::transform<list2, list2, pair_t>, expect2b>::value,
              "invalid binary transform on list");

static_assert(
    std::is_same<
        brigand::transform<custom_list<void, char, int>,
                           std::add_pointer<std::add_pointer<std::add_pointer<brigand::_1>>>>,
        custom_list<void ***, char ***, int ***>>::value,
    "invalid transform on list");

static_assert(std::is_same<brigand::transform<list2, brigand::if_<std::is_pointer<brigand::_1>,
                                                                  brigand::identity<brigand::_1>,
                                                                  std::add_pointer<brigand::_1>>>,
                           expect2c>::value,
              "invalid binary transform on list");

using sum_list = custom_int_list<1, 2, 3>;

static_assert(std::is_same<brigand::as_integral_list<brigand::transform<
                               sum_list, sum_list, brigand::plus<brigand::_1, brigand::_2>>>,
                           custom_int_list<2, 4, 6>>::value,
              "invalid transform sum");

static_assert(
    std::is_same<brigand::as_integral_list<brigand::transform<
                     sum_list, brigand::plus<brigand::_1, std::integral_constant<int, 2>>>>,
                 custom_int_list<3, 4, 5>>::value,
    "invalid transform sum");

static_assert(
    std::is_same<brigand::as_integral_list<brigand::transform<
                     sum_list, brigand::minus<std::integral_constant<int, 10>, brigand::_1>>>,
                 custom_int_list<9, 8, 7>>::value,
    "invalid transform sum");
}