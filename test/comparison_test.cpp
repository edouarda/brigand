
#include <brigand/functions/comparisons.hpp>

// integral constant tests
using value_int_one = std::integral_constant<int, 1>;
using value_int_two = std::integral_constant<int, 2>;

static_assert(brigand::less<value_int_one, value_int_two>::value == true, "invalid less result");
static_assert(brigand::less<value_int_one, value_int_one>::value == false, "invalid less result");
static_assert(brigand::less<value_int_two, value_int_one>::value == false, "invalid less result");

static_assert(brigand::less_equal<value_int_one, value_int_two>::value == true, "invalid less_equal result");
static_assert(brigand::less_equal<value_int_one, value_int_one>::value == true, "invalid less_equal result");
static_assert(brigand::less_equal<value_int_two, value_int_one>::value == false, "invalid less_equal result");

static_assert(brigand::greater<value_int_one, value_int_two>::value == false, "invalid greater result");
static_assert(brigand::greater<value_int_one, value_int_one>::value == false, "invalid greater result");
static_assert(brigand::greater<value_int_two, value_int_one>::value == true, "invalid greater result");

static_assert(brigand::greater_equal<value_int_one, value_int_two>::value == false, "invalid greater_equal result");
static_assert(brigand::greater_equal<value_int_one, value_int_one>::value == true, "invalid greater_equal result");
static_assert(brigand::greater_equal<value_int_two, value_int_one>::value == true, "invalid greater_equal result");

static_assert(brigand::equal_to<value_int_one, value_int_two>::value == false, "invalid equal_to result");
static_assert(brigand::equal_to<value_int_one, value_int_one>::value == true, "invalid equal_to result");
static_assert(brigand::equal_to<value_int_two, value_int_one>::value == false, "invalid equal_to result");

static_assert(brigand::not_equal_to<value_int_one, value_int_two>::value == true, "invalid not_equal_to result");
static_assert(brigand::not_equal_to<value_int_one, value_int_one>::value == false, "invalid not_equal_to result");
static_assert(brigand::not_equal_to<value_int_two, value_int_one>::value == true, "invalid not_equal_to result");
