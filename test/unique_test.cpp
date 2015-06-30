
#include <brigand/functions/unique.hpp>
#include <brigand/sequences/list.hpp>

static_assert(!brigand::unique<int, int, int>::value, "error in brigand::unique");
static_assert(!brigand::unique<int, int>::value, "error in brigand::unique");
static_assert(brigand::unique<int>::value, "error in brigand::unique");
static_assert(brigand::unique<>::value, "error in brigand::unique");
static_assert(brigand::unique<int, short>::value, "error in brigand::unique");
static_assert(brigand::unique<int, short, double>::value, "error in brigand::unique");
static_assert(brigand::unique<int, short, double, float>::value, "error in brigand::unique");
