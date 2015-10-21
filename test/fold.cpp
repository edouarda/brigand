#include <brigand/sequences/list.hpp>
#include <brigand/algorithms/fold.hpp>
#include <brigand/types/integer.hpp>
#include <brigand/functions/arithmetic/next.hpp>
#include <brigand/functions/arithmetic/plus.hpp>
#include <brigand/functions/arithmetic/times.hpp>
#include <brigand/functions/arithmetic/modulo.hpp>
#include <brigand/functions/comparison/equal_to.hpp>
#include <brigand/types/args.hpp>
#include <brigand/functions/if.hpp>
#include <type_traits>
#include <utility>

using list0 = brigand::list<>;
using list1y = brigand::list<float>;
using list1n = brigand::list<int*>;
using list6 = brigand::list<int, float, double, long, char, float>;
using list12 = brigand::list<float, double, float, double, float, double, float, double, float, double, float, double>;

using zero_ = brigand::uint32_t<0>;
using c88 = brigand::uint32_t<88>;
using leet_ = brigand::uint32_t<1337>;

// local functor to apply
using f_ =  brigand::if_<std::is_floating_point<brigand::_element>, brigand::next<brigand::_state>, brigand::_state>;

static_assert(brigand::fold<list0, leet_, f_>::value == 1337, "invalid fold on empty list");
static_assert(brigand::fold<list1y, zero_, f_>::value == 1, "invalid fold on 1 element list");
static_assert(brigand::fold<list1n, zero_, f_>::value == 0, "invalid fold on 1 element list");
static_assert(brigand::fold<list6, zero_, f_>::value == 3, "invalid fold on list");
static_assert(brigand::fold<list12, c88, f_>::value == 100, "invalid fold with state");

using small_list = brigand::list<brigand::uint32_t<1>, brigand::uint32_t<2>, brigand::uint32_t<3>>;

static_assert(brigand::fold<small_list, zero_, brigand::plus<brigand::_state, brigand::_element>>::value == 6, "invalid fold result");

// YO MR. WHITE WE'RE MAKING FAT STACKS YO
using big_fat_list = brigand::list<brigand::int32_t<1>, brigand::int32_t<2>, brigand::int32_t<3>,
    brigand::int32_t<4>, brigand::int32_t<5>, brigand::int32_t<6>,
    brigand::int32_t<7>, brigand::int32_t<8>, brigand::int32_t<9>>;

static_assert(brigand::fold<big_fat_list, brigand::int32_t<0>, brigand::plus<brigand::_state, brigand::_element>>::value == 45, "invalid fold result");

// do an operation that is dependent on the order
using ordered_result = brigand::if_<
    brigand::equal_to<brigand::modulo<brigand::_element, brigand::int32_t<2>>, brigand::int32_t<0>>,
    brigand::times<brigand::_state, brigand::_element>,
   brigand::plus<brigand::_state, brigand::_element>>;

static_assert(brigand::fold<big_fat_list, brigand::int32_t<0>, ordered_result>::value == 1265, "invalid fold on empty list");
