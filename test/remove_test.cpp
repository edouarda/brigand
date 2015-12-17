#include <brigand/algorithms/remove.hpp>
#include <brigand/functions/logical/and.hpp>
#include <brigand/functions/logical/not.hpp>
#include <brigand/sequences/list.hpp>
#include <brigand/types/args.hpp>
#include <brigand/types/bool.hpp>
#include <brigand/types/integer.hpp>

using remove_test_list = brigand::list<int, bool, int, char, float, double>;
using remove_test_int_list = brigand::integral_list<std::uint32_t, 1, 0, 0, 2>;

static_assert(std::is_same<brigand::remove<remove_test_int_list, brigand::uint32_t<2>>,
                           brigand::integral_list<std::uint32_t, 1, 0, 0>>::value,
              "invalid remove result");

static_assert(std::is_same<brigand::remove_if<remove_test_int_list, brigand::not_<brigand::_1>>,
                           brigand::list<brigand::uint32_t<1>, brigand::uint32_t<2>>>::value,
              "invalid remove_if result");

static_assert(std::is_same<brigand::remove_if<remove_test_int_list,
                                              std::is_same<brigand::_1, brigand::uint32_t<2>>>,
                           brigand::integral_list<std::uint32_t, 1, 0, 0>>::value,
              "invalid remove_if result");

static_assert(
    std::is_same<brigand::remove_if<remove_test_int_list, brigand::and_<brigand::_1, brigand::_1>>,
                 brigand::integral_list<std::uint32_t, 0, 0>>::value,
    "invalid remove_if result");

static_assert(std::is_same<brigand::remove<remove_test_list, int>,
                           brigand::list<bool, char, float, double>>::value,
              "invalid remove result");

static_assert(std::is_same<brigand::remove<remove_test_list, double>,
                           brigand::list<int, bool, int, char, float>>::value,
              "invalid remove result");

static_assert(std::is_same<brigand::remove_if<remove_test_list, std::is_same<double, brigand::_1>>,
                           brigand::list<int, bool, int, char, float>>::value,
              "invalid remove_if result");
