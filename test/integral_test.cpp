
#include <brigand/arithmetic.hpp>

// integral constant tests
using value_int_one = std::integral_constant<int, 1>;
using value_int_two = std::integral_constant<int, 2>;
using value_int_three = std::integral_constant<int, 3>;
using value_int_ten = std::integral_constant<int, 10>;
using value_byte_zero = std::integral_constant<unsigned char, 0>;

static_assert(brigand::min<value_int_one, value_int_two>::value == 1, "invalid min result");
static_assert(brigand::max<value_int_one, value_int_two>::value == 2, "invalid max result");
static_assert(brigand::plus<value_int_one, value_int_two>::value == 3, "invalid plus result");
static_assert(brigand::minus<value_int_two, value_int_one>::value == 1, "invalid minus result");
static_assert(brigand::times<value_int_two, value_int_two>::value == 4, "invalid times result");
static_assert(brigand::divides<value_int_ten, value_int_two>::value == 5, "invalid divides result");
static_assert(brigand::modulo<value_int_ten, value_int_three>::value == 1, "invalid modulo result");
static_assert(brigand::next<value_int_one>::value == 2, "invalid next result");
static_assert(brigand::prev<value_int_three>::value == 2, "invalid prev result");
static_assert(brigand::negate<value_int_three>::value == -3, "invalid negate result");
static_assert(brigand::complement<value_byte_zero>::value == 255, "invalid complement result");
