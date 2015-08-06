#include <brigand/functions/repeat.hpp>
#include <brigand/functions/next.hpp>
#include <brigand/types/integer.hpp>

static_assert(brigand::repeat<brigand::next, 0, brigand::int_<0>>::value == 0, "invalid result");
static_assert(brigand::repeat<brigand::next, 1, brigand::int_<0>>::value == 1, "invalid result");
static_assert(brigand::repeat<brigand::next, 2, brigand::int_<0>>::value == 2, "invalid result");
static_assert(brigand::repeat<brigand::next, 3, brigand::int_<0>>::value == 3, "invalid result");
static_assert(brigand::repeat<brigand::next, 4, brigand::int_<0>>::value == 4, "invalid result");
static_assert(brigand::repeat<brigand::next, 5, brigand::int_<0>>::value == 5, "invalid result");
static_assert(brigand::repeat<brigand::next, 6, brigand::int_<0>>::value == 6, "invalid result");
static_assert(brigand::repeat<brigand::next, 7, brigand::int_<0>>::value == 7, "invalid result");
static_assert(brigand::repeat<brigand::next, 8, brigand::int_<0>>::value == 8, "invalid result");
static_assert(brigand::repeat<brigand::next, 9, brigand::int_<0>>::value == 9, "invalid result");

