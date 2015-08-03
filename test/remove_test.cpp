#include <brigand/algorithms/remove.hpp>
#include <brigand/sequences/list.hpp>
#include <brigand/types/bind.hpp>
#include <brigand/types/integer.hpp>

using remove_test_list = brigand::list<int, bool, int, char, float, double>;
using remove_test_int_list = brigand::list<brigand::int_<1>, brigand::int_<0>, brigand::int_<0>, brigand::int_<2>>;

static_assert(std::is_same<brigand::remove<remove_test_int_list, brigand::int_<2>>, brigand::list<brigand::int_<1>, brigand::int_<0>, brigand::int_<0>>>::value, "invalid remove result");
static_assert(std::is_same<brigand::remove_if<remove_test_int_list>, brigand::list<brigand::int_<1>, brigand::int_<2>>>::value, "invalid remove result");
static_assert(std::is_same<brigand::remove_if<remove_test_int_list, brigand::unary_bind<std::is_same, brigand::int_<2>>::type>, brigand::list<brigand::int_<1>, brigand::int_<0>, brigand::int_<0>>>::value, "invalid remove_if result");

static_assert(std::is_same<brigand::remove<remove_test_list, int>, brigand::list<bool, char, float, double>>::value, "invalid remove result");
static_assert(std::is_same<brigand::remove<remove_test_list, double>, brigand::list<int, bool, int, char, float>>::value, "invalid remove result");
static_assert(std::is_same<brigand::remove_if<remove_test_list, brigand::unary_bind<std::is_same, double>::type>, brigand::list<int, bool, int, char, float>>::value, "invalid remove_if result");

