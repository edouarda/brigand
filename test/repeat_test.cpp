#include <brigand/functions/misc/repeat.hpp>
#include <brigand/functions/arithmetic/next.hpp>
#include <brigand/types/integer.hpp>

static_assert(brigand::repeat<brigand::next, brigand::uint32_t<0>, brigand::uint32_t<0>>::value == 0, "invalid result");
static_assert(brigand::repeat<brigand::next, brigand::uint32_t<1>, brigand::uint32_t<0>>::value == 1, "invalid result");
static_assert(brigand::repeat<brigand::next, brigand::uint32_t<2>, brigand::uint32_t<0>>::value == 2, "invalid result");
static_assert(brigand::repeat<brigand::next, brigand::uint32_t<3>, brigand::uint32_t<0>>::value == 3, "invalid result");
static_assert(brigand::repeat<brigand::next, brigand::uint32_t<4>, brigand::uint32_t<0>>::value == 4, "invalid result");
static_assert(brigand::repeat<brigand::next, brigand::uint32_t<5>, brigand::uint32_t<0>>::value == 5, "invalid result");
static_assert(brigand::repeat<brigand::next, brigand::uint32_t<6>, brigand::uint32_t<0>>::value == 6, "invalid result");
static_assert(brigand::repeat<brigand::next, brigand::uint32_t<7>, brigand::uint32_t<0>>::value == 7, "invalid result");
static_assert(brigand::repeat<brigand::next, brigand::uint32_t<8>, brigand::uint32_t<0>>::value == 8, "invalid result");
static_assert(brigand::repeat<brigand::next, brigand::uint32_t<9>, brigand::uint32_t<0>>::value == 9, "invalid result");

