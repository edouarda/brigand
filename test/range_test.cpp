#include <brigand/sequences/range.hpp>
#include <brigand/functions/prev.hpp>
#include <brigand/types/integer.hpp>
#include <brigand/adapted/integral_list.hpp>

static_assert(std::is_same<brigand::range<int, 0, 0>, brigand::integral_list<int>>::value, "invalid range result");
static_assert(std::is_same<brigand::as_integral_list <brigand::range<int, 0, 3>>, brigand::integral_list<int, 0, 1, 2>>::value, "invalid range result");
static_assert(std::is_same<brigand::as_integral_list <brigand::range<int, 2, 4>>, brigand::integral_list<int, 2, 3>>::value, "invalid range result");

static_assert(std::is_same<brigand::reverse_range<int, 0, 0>, brigand::integral_list<int>>::value, "invalid reverse_range result");
static_assert(std::is_same<brigand::as_integral_list <brigand::reverse_range<int, 2, 0>>, brigand::integral_list<int, 2, 1>>::value, "invalid reverse_range result");
static_assert(std::is_same<brigand::as_integral_list <brigand::reverse_range<int, 5, 2>>, brigand::integral_list<int, 5, 4, 3>>::value, "invalid reverse_range result");
