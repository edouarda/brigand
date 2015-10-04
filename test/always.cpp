
#include <brigand/functions/apply.hpp>
#include <brigand/functions/lambda/always.hpp>
#include <type_traits>

static_assert( std::is_same<int**&&, brigand::apply<brigand::always<int**&&>,float>>::value, "invalid always");
static_assert( std::is_same<void, brigand::apply<brigand::always<void>,float*&>>::value, "invalid always");
