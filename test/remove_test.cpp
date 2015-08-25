#include <brigand/algorithms/remove.hpp>
#include <brigand/sequences/list.hpp>
#include <brigand/functions/not.hpp>
#include <brigand/types/integer.hpp>

using remove_test_list = brigand::list<int, bool, int, char, float, double>;
using remove_test_int_list = brigand::list<brigand::int_<1>, brigand::int_<0>, brigand::int_<0>, brigand::int_<2>>;

static_assert(std::is_same<brigand::remove_element<remove_test_int_list, brigand::int_<2>>, brigand::list<brigand::int_<1>, brigand::int_<0>, brigand::int_<0>>>::value, "invalid remove result");
static_assert(std::is_same<brigand::remove<remove_test_int_list, brigand::not_>, brigand::list<brigand::int_<1>, brigand::int_<2>>>::value, "invalid remove result");

template<class T>
using remove_int_2_predicate = std::is_same<T, brigand::int_<2>>;

static_assert(std::is_same<brigand::remove<remove_test_int_list, remove_int_2_predicate>, brigand::list<brigand::int_<1>, brigand::int_<0>, brigand::int_<0>>>::value, "invalid remove_if result");
static_assert(std::is_same<brigand::remove_element<remove_test_list, int>, brigand::list<bool, char, float, double>>::value, "invalid remove result");
static_assert(std::is_same<brigand::remove_element<remove_test_list, double>, brigand::list<int, bool, int, char, float>>::value, "invalid remove result");

template<class T>
using remove_double_predicate = std::is_same<T, double>;

static_assert(std::is_same<brigand::remove<remove_test_list, remove_double_predicate>, brigand::list<int, bool, int, char, float>>::value, "invalid remove_if result");

