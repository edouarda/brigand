
#include <brigand/logical.hpp>

static_assert(brigand::not_<brigand::true_>::value == false, "invalid not result");
static_assert(brigand::not_<brigand::false_>::value == true, "invalid not result");

static_assert(brigand::and_<brigand::false_,brigand::false_>::value == false, "invalid and result");
static_assert(brigand::and_<brigand::false_,brigand::true_>::value == false, "invalid and result");
static_assert(brigand::and_<brigand::true_,brigand::false_>::value == false, "invalid and result");
static_assert(brigand::and_<brigand::true_,brigand::true_>::value == true, "invalid and result");

static_assert(brigand::or_<brigand::false_,brigand::false_>::value == false, "invalid or result");
static_assert(brigand::or_<brigand::false_,brigand::true_>::value == true, "invalid or result");
static_assert(brigand::or_<brigand::true_,brigand::false_>::value == true, "invalid or result");
static_assert(brigand::or_<brigand::true_,brigand::true_>::value == true, "invalid or result");

static_assert(brigand::xor_<brigand::false_,brigand::false_>::value == false, "invalid xor result");
static_assert(brigand::xor_<brigand::false_,brigand::true_>::value == true, "invalid xor result");
static_assert(brigand::xor_<brigand::true_,brigand::false_>::value == true, "invalid xor result");
static_assert(brigand::xor_<brigand::true_,brigand::true_>::value == false, "invalid xor result");
