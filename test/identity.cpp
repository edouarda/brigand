
#include <brigand/functions/arithmetic/identity.hpp>
#include <type_traits>

static_assert( std::is_same<int**&&, brigand::identity<int**&&>::type>::value, "invalid identity");
static_assert( std::is_same<void, brigand::identity<void>::type>::value, "invalid identity");
