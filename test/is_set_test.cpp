
#include <brigand/algorithms/is_set.hpp>
#include <brigand/sequences/list.hpp>

static_assert(!brigand::is_set<int, int, int>::value, "error in brigand::is_set");
static_assert(!brigand::is_set<int, int>::value, "error in brigand::is_set");
static_assert(!brigand::is_set<void, int&, int, int>::value, "error in brigand::is_set");
static_assert(!brigand::is_set<void, const int, int, int>::value, "error in brigand::is_set");
static_assert(!brigand::is_set<void, const int, const int>::value, "error in brigand::is_set");
static_assert(brigand::is_set<void, int&, int>::value, "error in brigand::is_set");
static_assert(brigand::is_set<void, const int, int>::value, "error in brigand::is_set");
static_assert(brigand::is_set<int>::value, "error in brigand::is_set");
static_assert(brigand::is_set<>::value, "error in brigand::is_set");
static_assert(brigand::is_set<int, short>::value, "error in brigand::is_set");
static_assert(brigand::is_set<int, short, double>::value, "error in brigand::is_set");
static_assert(brigand::is_set<int, short, double, float>::value, "error in brigand::is_set");
static_assert(brigand::is_set<int, void, int&>::value, "error in brigand::is_set");
