
#include <brigand/functions/bitwise.hpp>

// integral constant tests
using value_int_one = std::integral_constant<int, 1>;
using value_int_two = std::integral_constant<int, 2>;
using value_int_three = std::integral_constant<int, 3>;

static_assert(brigand::bitand_<value_int_one, value_int_one>::value == 1, "invalid bitand_ result");
static_assert(brigand::bitand_<value_int_one, value_int_two>::value == 0, "invalid bitand_ result");
static_assert(brigand::bitand_<value_int_two, value_int_three>::value == 2, "invalid bitand_ result");

static_assert(brigand::bitor_<value_int_one, value_int_one>::value == 1, "invalid bitor_ result");
static_assert(brigand::bitor_<value_int_one, value_int_two>::value == 3, "invalid bitor_ result");

static_assert(brigand::bitxor_<value_int_one, value_int_one>::value == 0, "invalid bitxor_ result");
static_assert(brigand::bitxor_<value_int_one, value_int_two>::value == 3, "invalid bitxor_ result");
static_assert(brigand::bitxor_<value_int_two, value_int_three>::value == 1, "invalid bitxor_ result");

static_assert(brigand::shift_left<value_int_one, value_int_one>::value == 2, "invalid shift_left result");
static_assert(brigand::shift_left<value_int_one, value_int_two>::value == 4, "invalid shift_left result");
static_assert(brigand::shift_left<value_int_three, value_int_two>::value == 12, "invalid shift_left result");

static_assert(brigand::shift_right<value_int_one, value_int_one>::value == 0, "invalid shift_right result");
static_assert(brigand::shift_right<value_int_one, value_int_two>::value == 0, "invalid shift_right result");
static_assert(brigand::shift_right<value_int_two, value_int_one>::value == 1, "invalid shift_right result");
static_assert(brigand::shift_right<value_int_three, value_int_one>::value == 1, "invalid shift_right result");
