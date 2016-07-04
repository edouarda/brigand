#include <brigand/functions/arithmetic/prev.hpp>
#include <brigand/sequences/make_sequence.hpp>
#include <brigand/types/integer.hpp>

static_assert(std::is_same<brigand::make_sequence<brigand::uint32_t<0>, 3>,
                           brigand::integral_list<std::uint32_t, 0, 1, 2>>::value,
              "invalid make_sequence result");
static_assert(
    std::is_same<brigand::make_sequence<brigand::int32_t<2>, 4, brigand::prev<brigand::_1>>,
                 brigand::integral_list<std::int32_t, 2, 1, 0, -1>>::value,
    "invalid make_sequence result");
static_assert(
    std::is_same<brigand::make_sequence<brigand::uint32_t<0>, 10>,
                 brigand::integral_list<std::uint32_t, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9>>::value,
    "invalid make_sequence result");
static_assert(std::is_same<brigand::make_sequence<brigand::uint32_t<0>, 19>,
                           brigand::integral_list<std::uint32_t, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                                                  11, 12, 13, 14, 15, 16, 17, 18>>::value,
              "invalid make_sequence result");
