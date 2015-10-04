
#include <utility>

#include <brigand/types/args.hpp>
#include <brigand/types/is_placeholder.hpp>
#include <brigand/types/has_placeholders.hpp>

static_assert( !brigand::is_placeholder<int>::value, "error in brigand::is_placeholder");
static_assert( brigand::is_placeholder<brigand::_1>::value, "error in brigand::is_placeholder");
static_assert( brigand::is_placeholder<brigand::_9>::value, "error in brigand::is_placeholder");

static_assert( !brigand::has_placeholders<int         , int         >::value, "error in brigand::has_placeholders");
static_assert(  brigand::has_placeholders<brigand::_1 , int         >::value, "error in brigand::has_placeholders");
static_assert(  brigand::has_placeholders<int         , brigand::_1 >::value, "error in brigand::has_placeholders");
static_assert(  brigand::has_placeholders<brigand::_1 , brigand::_1 >::value, "error in brigand::has_placeholders");

static_assert(  brigand::has_placeholders<brigand::_1 , brigand::_1, int >::value, "error in brigand::has_placeholders");
static_assert(  brigand::has_placeholders<brigand::_1 , int, brigand::_1 >::value, "error in brigand::has_placeholders");
static_assert(  brigand::has_placeholders<brigand::_1 , int, int >::value, "error in brigand::has_placeholders");
static_assert( !brigand::has_placeholders<int,int,int >::value, "error in brigand::has_placeholders");
