
#include <brigand/functions/arithmetic.hpp>

// integral constant tests
using value_int_one = brigand::integral_constant<int, 1>;
using value_int_two = brigand::integral_constant<int, 2>;
using value_int_three = brigand::integral_constant<int, 3>;
using value_int_ten = brigand::integral_constant<int, 10>;
using value_byte_zero = brigand::integral_constant<unsigned char, 0>;

static_assert(brigand::min<value_int_one, value_int_two>::value == 1, "invalid min result");
static_assert(brigand::max<value_int_one, value_int_two>::value == 2, "invalid max result");
static_assert(brigand::plus<value_int_one, value_int_two>::value == 3, "invalid plus result");
static_assert(brigand::minus<value_int_two, value_int_one>::value == 1, "invalid minus result");
static_assert(brigand::times<value_int_two, value_int_two>::value == 4, "invalid times result");
static_assert(brigand::divides<value_int_ten, value_int_two>::value == 5, "invalid divides result");
static_assert(brigand::modulo<value_int_ten, value_int_three>::value == 1, "invalid modulo result");
static_assert(brigand::next<value_int_one>::value == 2, "invalid next result");
static_assert(brigand::next<brigand::next<value_int_one>>::value == 3, "invalid next result");
static_assert(brigand::prev<value_int_three>::value == 2, "invalid prev result");
static_assert(brigand::prev<brigand::prev<value_int_three>>::value == 1, "invalid prev result");
static_assert(brigand::prev<brigand::next<value_int_one>>::value == 1, "invalid prev next result");
static_assert(brigand::negate<value_int_three>::value == -3, "invalid negate result");
static_assert(brigand::complement<value_byte_zero>::value == 255, "invalid complement result");

static_assert(std::is_same<typename brigand::min<brigand::integral_constant<short, 10>,
                                                 brigand::integral_constant<long, 3>>::type,
                           brigand::integral_constant<long, 3>>::value,
              "failed min with cast");
static_assert(std::is_same<typename brigand::min<brigand::integral_constant<long, 10>,
                                                 brigand::integral_constant<short, 3>>::type,
                           brigand::integral_constant<long, 3>>::value,
              "failed min with cast");
static_assert(std::is_same<typename brigand::max<brigand::integral_constant<short, 10>,
                                                 brigand::integral_constant<long, 3>>::type,
                           brigand::integral_constant<long, 10>>::value,
              "failed max with cast");
static_assert(std::is_same<typename brigand::max<brigand::integral_constant<long, 10>,
                                                 brigand::integral_constant<short, 3>>::type,
                           brigand::integral_constant<long, 10>>::value,
              "failed max with cast");
static_assert(std::is_same<typename brigand::plus<brigand::integral_constant<short, 1>,
                                                  brigand::integral_constant<long, 2>>::type,
                           brigand::integral_constant<long, 3>>::value,
              "failed addition with cast");
static_assert(std::is_same<typename brigand::plus<brigand::integral_constant<long, 1>,
                                                  brigand::integral_constant<short, 2>>::type,
                           brigand::integral_constant<long, 3>>::value,
              "failed addition with cast");
static_assert(std::is_same<typename brigand::minus<brigand::integral_constant<short, 1>,
                                                   brigand::integral_constant<long, 2>>::type,
                           brigand::integral_constant<long, -1>>::value,
              "failed subtraction with cast");
static_assert(std::is_same<typename brigand::minus<brigand::integral_constant<long, 1>,
                                                   brigand::integral_constant<short, 2>>::type,
                           brigand::integral_constant<long, -1>>::value,
              "failed subtraction with cast");
static_assert(std::is_same<typename brigand::times<brigand::integral_constant<short, 1>,
                                                   brigand::integral_constant<long, 2>>::type,
                           brigand::integral_constant<long, 2>>::value,
              "failed times with cast");
static_assert(std::is_same<typename brigand::times<brigand::integral_constant<long, 1>,
                                                   brigand::integral_constant<short, 2>>::type,
                           brigand::integral_constant<long, 2>>::value,
              "failed times with cast");
static_assert(std::is_same<typename brigand::divides<brigand::integral_constant<short, 4>,
                                                     brigand::integral_constant<long, 2>>::type,
                           brigand::integral_constant<long, 2>>::value,
              "failed divides with cast");
static_assert(std::is_same<typename brigand::divides<brigand::integral_constant<long, 4>,
                                                     brigand::integral_constant<short, 2>>::type,
                           brigand::integral_constant<long, 2>>::value,
              "failed divides with cast");
static_assert(std::is_same<typename brigand::modulo<brigand::integral_constant<short, 10>,
                                                    brigand::integral_constant<long, 3>>::type,
                           brigand::integral_constant<long, 1>>::value,
              "failed modulo with cast");
static_assert(std::is_same<typename brigand::modulo<brigand::integral_constant<long, 10>,
                                                    brigand::integral_constant<short, 3>>::type,
                           brigand::integral_constant<long, 1>>::value,
              "failed modulo with cast");
