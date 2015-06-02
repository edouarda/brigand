
#include <qdb/mpl/plus.hpp>
#include <qdb/mpl/minus.hpp>
#include <qdb/mpl/not.hpp>

// integral constant tests
using value_int_one = std::integral_constant<int, 1>;
using value_int_two = std::integral_constant<int, 2>;

static_assert(brigand::plus<value_int_one, value_int_two>::value == 3, "invalid plus result");
static_assert(brigand::minus<value_int_two, value_int_one>::value == 1, "invalid minus result");

static_assert(brigand::not<std::integral_constant<bool, false>>::value, "invalid not result");
