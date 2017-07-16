
#include <brigand/functions/logical.hpp>

static_assert(brigand::not_<brigand::true_type>::value == false, "invalid not result");
static_assert(brigand::not_<brigand::false_type>::value == true, "invalid not result");

static_assert(brigand::not_<brigand::not_<brigand::true_type>>::value == true,
              "invalid not result");

static_assert(brigand::and_<>::value == true,
              "invalid not result");
static_assert(brigand::and_<brigand::false_type>::value == false,
              "invalid not result");
static_assert(brigand::and_<brigand::true_type>::value == true,
              "invalid not result");
static_assert(brigand::and_<brigand::false_type, brigand::false_type>::value == false,
              "invalid and result");
static_assert(brigand::and_<brigand::false_type, brigand::true_type>::value == false,
              "invalid and result");
static_assert(brigand::and_<brigand::true_type, brigand::false_type>::value == false,
              "invalid and result");
static_assert(brigand::and_<brigand::true_type, brigand::true_type>::value == true,
              "invalid and result");
static_assert(brigand::and_<brigand::false_type, brigand::false_type, brigand::false_type>::value == false,
              "invalid not result");
static_assert(brigand::and_<brigand::true_type, brigand::false_type, brigand::false_type>::value == false,
              "invalid not result");
static_assert(brigand::and_<brigand::true_type, brigand::true_type, brigand::false_type>::value == false,
              "invalid not result");
static_assert(brigand::and_<brigand::true_type, brigand::true_type, brigand::true_type>::value == true,
              "invalid not result");

static_assert(brigand::and_<brigand::not_<brigand::true_type>, brigand::false_type>::value == false,
              "invalid and/not result");

static_assert(brigand::and_<brigand::true_type, brigand::true_type,
              brigand::true_type, brigand::true_type,
              brigand::true_type, brigand::true_type,
              brigand::true_type, brigand::true_type,
              brigand::true_type, brigand::true_type,
              brigand::true_type, brigand::true_type,
              brigand::true_type, brigand::true_type,
              brigand::true_type, brigand::true_type,
              brigand::true_type, brigand::true_type,
              brigand::false_type, brigand::true_type,
              brigand::true_type, brigand::true_type,
              brigand::true_type, brigand::true_type,
              brigand::true_type, brigand::true_type,
              brigand::true_type, brigand::true_type,
              brigand::true_type, brigand::true_type,
              brigand::true_type, brigand::true_type,
              brigand::true_type, brigand::true_type,
              brigand::true_type, brigand::true_type,
              brigand::true_type, brigand::true_type,
              brigand::true_type, brigand::true_type,
              brigand::true_type, brigand::true_type,
              brigand::true_type, brigand::true_type>::value == false,
              "invalid or result");

static_assert(brigand::and_<brigand::true_type, brigand::true_type,
              brigand::true_type, brigand::true_type,
              brigand::true_type, brigand::true_type,
              brigand::true_type, brigand::true_type,
              brigand::true_type, brigand::true_type,
              brigand::true_type, brigand::true_type,
              brigand::true_type, brigand::true_type,
              brigand::true_type, brigand::true_type,
              brigand::true_type, brigand::true_type,
              brigand::true_type, brigand::true_type,
              brigand::true_type, brigand::true_type,
              brigand::true_type, brigand::true_type,
              brigand::true_type, brigand::true_type,
              brigand::true_type, brigand::true_type,
              brigand::true_type, brigand::true_type,
              brigand::true_type, brigand::true_type,
              brigand::true_type, brigand::true_type,
              brigand::true_type, brigand::true_type,
              brigand::true_type, brigand::true_type,
              brigand::true_type, brigand::true_type,
              brigand::true_type, brigand::true_type,
              brigand::true_type, brigand::true_type>::value == true,
              "invalid or result");


static_assert(brigand::or_<>::value == false,
              "invalid not result");
static_assert(brigand::or_<brigand::false_type>::value == false,
              "invalid not result");
static_assert(brigand::or_<brigand::true_type>::value == true,
              "invalid not result");
static_assert(brigand::or_<brigand::false_type, brigand::false_type>::value == false,
              "invalid or result");
static_assert(brigand::or_<brigand::false_type, brigand::true_type>::value == true,
              "invalid or result");
static_assert(brigand::or_<brigand::true_type, brigand::false_type>::value == true,
              "invalid or result");
static_assert(brigand::or_<brigand::true_type, brigand::true_type>::value == true,
              "invalid or result");
static_assert(brigand::or_<brigand::false_type, brigand::false_type, brigand::false_type>::value == false,
              "invalid not result");
static_assert(brigand::or_<brigand::true_type, brigand::false_type, brigand::false_type>::value == true,
              "invalid not result");
static_assert(brigand::or_<brigand::true_type, brigand::true_type, brigand::false_type>::value == true,
              "invalid not result");
static_assert(brigand::or_<brigand::true_type, brigand::true_type, brigand::true_type>::value == true,
              "invalid not result");

static_assert(brigand::or_<brigand::false_type, brigand::false_type,
              brigand::false_type, brigand::false_type,
              brigand::false_type, brigand::false_type,
              brigand::false_type, brigand::false_type,
              brigand::false_type, brigand::false_type,
              brigand::false_type, brigand::false_type,
              brigand::false_type, brigand::false_type,
              brigand::false_type, brigand::false_type,
              brigand::false_type, brigand::false_type,
              brigand::false_type, brigand::false_type,
              brigand::false_type, brigand::false_type,
              brigand::false_type, brigand::false_type,
              brigand::false_type, brigand::false_type,
              brigand::false_type, brigand::false_type,
              brigand::false_type, brigand::false_type,
              brigand::false_type, brigand::false_type,
              brigand::false_type, brigand::false_type,
              brigand::false_type, brigand::false_type,
              brigand::false_type, brigand::false_type,
              brigand::false_type, brigand::false_type,
              brigand::false_type, brigand::false_type,
              brigand::false_type, brigand::false_type>::value == false,
              "invalid or result");

static_assert(brigand::or_<brigand::false_type, brigand::false_type,
              brigand::false_type, brigand::false_type,
              brigand::false_type, brigand::false_type,
              brigand::false_type, brigand::false_type,
              brigand::false_type, brigand::false_type,
              brigand::false_type, brigand::false_type,
              brigand::false_type, brigand::false_type,
              brigand::false_type, brigand::false_type,
              brigand::false_type, brigand::false_type,
              brigand::false_type, brigand::false_type,
              brigand::false_type, brigand::false_type,
              brigand::false_type, brigand::false_type,
              brigand::false_type, brigand::true_type,
              brigand::false_type, brigand::false_type,
              brigand::false_type, brigand::false_type,
              brigand::false_type, brigand::false_type,
              brigand::false_type, brigand::false_type,
              brigand::false_type, brigand::false_type,
              brigand::false_type, brigand::false_type,
              brigand::false_type, brigand::false_type,
              brigand::false_type, brigand::false_type,
              brigand::false_type, brigand::false_type>::value == true,
              "invalid or result");

static_assert(brigand::xor_<brigand::false_type, brigand::false_type>::value == false,
              "invalid xor result");
static_assert(brigand::xor_<brigand::false_type, brigand::true_type>::value == true,
              "invalid xor result");
static_assert(brigand::xor_<brigand::true_type, brigand::false_type>::value == true,
              "invalid xor result");
static_assert(brigand::xor_<brigand::true_type, brigand::true_type>::value == false,
              "invalid xor result");
