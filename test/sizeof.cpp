
#include <brigand/functions/misc/sizeof.hpp>
#include <type_traits>

struct udt { char a[100]; };

static_assert( brigand::sizeof_<char>::value    == sizeof(char), "invalid sizeof_" );
static_assert( brigand::sizeof_<int>::value     == sizeof(int), "invalid sizeof_"  );
static_assert( brigand::sizeof_<double>::value  == sizeof(double), "invalid sizeof_"  );
static_assert( brigand::sizeof_<udt>::value     == sizeof(udt), "invalid sizeof_"  );
