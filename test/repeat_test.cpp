#include <brigand/functions/repeat.hpp>
#include <brigand/functions/arithmetic/next.hpp>
#include <brigand/types/integer.hpp>

static_assert(brigand::repeat<brigand::next, brigand::int_<0>, brigand::int_<0>>::value == 0, "invalid result");
static_assert(brigand::repeat<brigand::next, brigand::int_<1>, brigand::int_<0>>::value == 1, "invalid result");
static_assert(brigand::repeat<brigand::next, brigand::int_<2>, brigand::int_<0>>::value == 2, "invalid result");
static_assert(brigand::repeat<brigand::next, brigand::int_<3>, brigand::int_<0>>::value == 3, "invalid result");
static_assert(brigand::repeat<brigand::next, brigand::int_<4>, brigand::int_<0>>::value == 4, "invalid result");
static_assert(brigand::repeat<brigand::next, brigand::int_<5>, brigand::int_<0>>::value == 5, "invalid result");
static_assert(brigand::repeat<brigand::next, brigand::int_<6>, brigand::int_<0>>::value == 6, "invalid result");
static_assert(brigand::repeat<brigand::next, brigand::int_<7>, brigand::int_<0>>::value == 7, "invalid result");
static_assert(brigand::repeat<brigand::next, brigand::int_<8>, brigand::int_<0>>::value == 8, "invalid result");
static_assert(brigand::repeat<brigand::next, brigand::int_<9>, brigand::int_<0>>::value == 9, "invalid result");

