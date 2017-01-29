
#include <brigand/functions/bitwise.hpp>
#include <brigand/types/integral_constant.hpp>

#include <cstdint>

// integral constant tests

using value_uint16_zero = brigand::integral_constant<std::uint16_t, 0x0000>;
using value_uint16_alt1 = brigand::integral_constant<std::uint16_t, 0xff00>;
using value_uint16_alt2 = brigand::integral_constant<std::uint16_t, 0x00ff>;
using value_uint16_full = brigand::integral_constant<std::uint16_t, 0xffff>;

// and
static_assert(brigand::bitor_<value_uint16_zero, value_uint16_zero>::value == value_uint16_zero::value, "invalid bitand_ result");
static_assert(brigand::bitand_<value_uint16_alt1, value_uint16_alt2>::value == value_uint16_zero::value, "invalid bitand_ result");
static_assert(brigand::bitand_<value_uint16_alt1, value_uint16_alt1>::value == value_uint16_alt1::value, "invalid bitand_ result");
static_assert(brigand::bitand_<value_uint16_alt2, value_uint16_alt2>::value == value_uint16_alt2::value, "invalid bitand_ result");
static_assert(brigand::bitand_<value_uint16_full, value_uint16_full>::value == value_uint16_full::value, "invalid bitand_ result");

// or
static_assert(brigand::bitor_<value_uint16_zero, value_uint16_zero>::value == value_uint16_zero::value, "invalid bitand_ result");
static_assert(brigand::bitor_<value_uint16_alt1, value_uint16_alt2>::value == value_uint16_full::value, "invalid bitand_ result");
static_assert(brigand::bitor_<value_uint16_alt1, value_uint16_alt1>::value == value_uint16_alt1::value, "invalid bitand_ result");
static_assert(brigand::bitor_<value_uint16_alt2, value_uint16_alt2>::value == value_uint16_alt2::value, "invalid bitand_ result");
static_assert(brigand::bitor_<value_uint16_full, value_uint16_full>::value == value_uint16_full::value, "invalid bitand_ result");

// xor
static_assert(brigand::bitxor_<value_uint16_zero, value_uint16_zero>::value == value_uint16_zero::value, "invalid bitand_ result");
static_assert(brigand::bitxor_<value_uint16_alt1, value_uint16_alt2>::value == value_uint16_full::value, "invalid bitand_ result");
static_assert(brigand::bitxor_<value_uint16_alt1, value_uint16_alt1>::value == value_uint16_zero::value, "invalid bitand_ result");
static_assert(brigand::bitxor_<value_uint16_alt2, value_uint16_alt2>::value == value_uint16_zero::value, "invalid bitand_ result");
static_assert(brigand::bitxor_<value_uint16_full, value_uint16_full>::value == value_uint16_zero::value, "invalid bitand_ result");

using value_int_one = brigand::integral_constant<int, 1>;
using value_int_two = brigand::integral_constant<int, 2>;
using value_int_three = brigand::integral_constant<int, 3>;
using value_int_four = brigand::integral_constant<int, 4>;

// shift left
static_assert(brigand::shift_left<value_int_one, value_int_one>::value == 2, "invalid shift_left result");
static_assert(brigand::shift_left<value_int_one, value_int_two>::value == 4, "invalid shift_left result");
static_assert(brigand::shift_left<value_int_three, value_int_two>::value == 12, "invalid shift_left result");

// shift right
static_assert(brigand::shift_right<value_int_one, value_int_one>::value == 0, "invalid shift_right result");
static_assert(brigand::shift_right<value_int_one, value_int_two>::value == 0, "invalid shift_right result");
static_assert(brigand::shift_right<value_int_two, value_int_one>::value == 1, "invalid shift_right result");
static_assert(brigand::shift_right<value_int_three, value_int_one>::value == 1, "invalid shift_right result");

