
#include <brigand/functions/logical.hpp>

static_assert(brigand::not_<std::true_type>::value == false, "invalid not result");
static_assert(brigand::not_<std::false_type>::value == true, "invalid not result");

static_assert(brigand::not_<brigand::not_<std::true_type>>::value == true, "invalid not result");

static_assert(brigand::and_<std::false_type,std::false_type>::value == false, "invalid and result");
static_assert(brigand::and_<std::false_type,std::true_type>::value == false, "invalid and result");
static_assert(brigand::and_<std::true_type,std::false_type>::value == false, "invalid and result");
static_assert(brigand::and_<std::true_type,std::true_type>::value == true, "invalid and result");

static_assert(brigand::and_<brigand::not_<std::true_type>, std::false_type>::value == false, "invalid and/not result");

static_assert(brigand::or_<std::false_type,std::false_type>::value == false, "invalid or result");
static_assert(brigand::or_<std::false_type,std::true_type>::value == true, "invalid or result");
static_assert(brigand::or_<std::true_type,std::false_type>::value == true, "invalid or result");
static_assert(brigand::or_<std::true_type,std::true_type>::value == true, "invalid or result");

static_assert(brigand::xor_<std::false_type,std::false_type>::value == false, "invalid xor result");
static_assert(brigand::xor_<std::false_type,std::true_type>::value == true, "invalid xor result");
static_assert(brigand::xor_<std::true_type,std::false_type>::value == true, "invalid xor result");
static_assert(brigand::xor_<std::true_type,std::true_type>::value == false, "invalid xor result");
