
#include <brigand/functions/eval_if.hpp>
#include <brigand/types/bool.hpp>

static_assert(std::is_same<brigand::eval_if<brigand::true_, std::enable_if<true, long>, std::enable_if<false>>::type, long>::value, "invalid eval_if result");
static_assert(std::is_same<brigand::eval_if<brigand::false_, std::enable_if<false>, std::enable_if<true, bool>>::type, bool>::value, "invalid eval_if result");

static_assert(std::is_same<brigand::eval_if_c<true, std::enable_if<true, long>, std::enable_if<false>>::type, long>::value, "invalid eval_if result");
static_assert(std::is_same<brigand::eval_if_c<false, std::enable_if<false>, std::enable_if<true, bool>>::type, bool>::value, "invalid eval_if result");
