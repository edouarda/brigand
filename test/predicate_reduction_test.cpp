#include <brigand/algorithms/all.hpp>
#include <brigand/algorithms/any.hpp>
#include <brigand/algorithms/none.hpp>
#include <brigand/algorithms/wrap.hpp>
#include <brigand/sequences/list.hpp>
#include <type_traits>

static_assert(brigand::none<brigand::empty_sequence>::value, "invalid none on empty list");

static_assert(brigand::none<brigand::integral_list<int, 0, 0, 0, 0, 0, 0>>::value,
  "invalid none on values list");

static_assert(
  brigand::none<brigand::list<int, int, char>, std::is_floating_point<brigand::_1>>::value,
  "invalid none on list");

static_assert(!brigand::any<brigand::empty_sequence>::value, "invalid any on empty list");

static_assert(brigand::any<brigand::integral_list<int, 0, 0, 7, 0, 0, 0>>::value,
  "invalid any on values list");

static_assert(
  brigand::any<brigand::list<int, int, double, char>, std::is_floating_point<brigand::_1>>::value,
  "invalid any on list");

static_assert(brigand::all<brigand::empty_sequence>::value, "invalid all on empty list");

static_assert(brigand::any<brigand::integral_list<int, 1, 1, 1, 1>>::value, "invalid any list");
static_assert(!brigand::any<brigand::integral_list<int, 0, 0, 0, 0>>::value, "invalid any list");

static_assert(brigand::all<brigand::integral_list<int, 42, 69, 1337, 1664>>::value,
  "invalid all on values list");

static_assert(brigand::all<brigand::list<float, long double, double>,
  std::is_floating_point<brigand::_1>>::value,
  "invalid all on list");

template <class...>
class custom_list
{
};
template <typename T, T... List>
using custom_integral_list =
brigand::wrap<brigand::integral_list<std::size_t, List...>, custom_list>;

static_assert(brigand::none<custom_list<>>::value, "invalid none on empty list");

static_assert(brigand::none<custom_integral_list<int, 0, 0, 0, 0, 0, 0>>::value,
  "invalid none on values list");

static_assert(
  brigand::none<brigand::list<int, int, char>, std::is_floating_point<brigand::_1>>::value,
  "invalid none on list");

static_assert(!brigand::any<custom_list<>>::value, "invalid any on empty list");

static_assert(brigand::any<custom_integral_list<int, 0, 0, 7, 0, 0, 0>>::value,
  "invalid any on values list");

static_assert(
  brigand::any<brigand::list<int, int, double, char>, std::is_floating_point<brigand::_1>>::value,
  "invalid any on list");

static_assert(brigand::all<custom_list<>>::value, "invalid all on empty list");

static_assert(brigand::any<custom_integral_list<int, 1, 1, 1, 1>>::value, "invalid any list");
static_assert(!brigand::any<custom_integral_list<int, 0, 0, 0, 0>>::value, "invalid any list");

static_assert(brigand::all<custom_integral_list<int, 42, 69, 1337, 1664>>::value,
  "invalid all on values list");

static_assert(brigand::all<brigand::list<float, long double, double>,
  std::is_floating_point<brigand::_1>>::value,
  "invalid all on list");
