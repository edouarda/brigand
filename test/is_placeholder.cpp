
#include <utility>

#include <brigand/types/placeholders.hpp>
#include <brigand/types/is_placeholder.hpp>

static_assert( !brigand::is_placeholder<int>::value, "error in brigand::is_placeholder");
static_assert( brigand::is_placeholder<brigand::_1>::value, "error in brigand::is_placeholder");
static_assert( brigand::is_placeholder<brigand::_9>::value, "error in brigand::is_placeholder");

static_assert( !brigand::is_placeholder<int         , int         >::value, "error in brigand::is_placeholder");
static_assert(  brigand::is_placeholder<brigand::_1 , int         >::value, "error in brigand::is_placeholder");
static_assert(  brigand::is_placeholder<int         , brigand::_1 >::value, "error in brigand::is_placeholder");
static_assert(  brigand::is_placeholder<brigand::_1 , brigand::_1 >::value, "error in brigand::is_placeholder");
