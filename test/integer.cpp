#include <brigand/types/integer.hpp>
#include <type_traits>

static_assert(sizeof(brigand::int8_t<1>::value_type) == 1, "wrong brigand type");
static_assert(sizeof(brigand::uint8_t<1>::value_type) == 1, "wrong brigand type");
static_assert(std::is_signed<brigand::int8_t<1>::value_type>::value, "wrong brigand sign");
static_assert(!std::is_signed<brigand::uint8_t<1>::value_type>::value, "wrong brigand sign");

static_assert(sizeof(brigand::int16_t<1>::value_type) == 2, "wrong brigand type");
static_assert(sizeof(brigand::uint16_t<1>::value_type) == 2, "wrong brigand type");
static_assert(std::is_signed<brigand::int16_t<1>::value_type>::value, "wrong brigand sign");
static_assert(!std::is_signed<brigand::uint16_t<1>::value_type>::value, "wrong brigand sign");

static_assert(sizeof(brigand::int32_t<1>::value_type) == 4, "wrong brigand type");
static_assert(sizeof(brigand::uint32_t<1>::value_type) == 4, "wrong brigand type");
static_assert(std::is_signed<brigand::int32_t<1>::value_type>::value, "wrong brigand sign");
static_assert(!std::is_signed<brigand::uint32_t<1>::value_type>::value, "wrong brigand sign");

static_assert(sizeof(brigand::int64_t<1>::value_type) == 8, "wrong brigand type");
static_assert(sizeof(brigand::uint64_t<1>::value_type) == 8, "wrong brigand type");
static_assert(std::is_signed<brigand::int64_t<1>::value_type>::value, "wrong brigand sign");
static_assert(!std::is_signed<brigand::uint64_t<1>::value_type>::value, "wrong brigand sign");
