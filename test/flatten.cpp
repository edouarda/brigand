
#include <brigand/algorithms/flatten.hpp>

static_assert(std::is_same<brigand::flatten<brigand::empty_sequence>, brigand::empty_sequence>::value, "invalid flatten on empty sequence");

using flat_seq = brigand::list<char, bool, int>;

static_assert(std::is_same<brigand::flatten<flat_seq>, flat_seq>::value, "invalid flatten on flat sequence");

using one_level = brigand::list<brigand::list<char, bool, int>, flat_seq, char, char>;
using flat_one_level = brigand::list<char, bool, int, char, bool, int, char, char>;

static_assert(std::is_same<brigand::flatten<one_level>, flat_one_level>::value, "invalid flatten on one level sequence");

using two_levels = brigand::list<brigand::list<flat_seq, bool, int>, flat_seq, char, char>;
using flat_two_levels = brigand::list<char, bool, int, bool, int, char, bool, int, char, char>;

static_assert(std::is_same<brigand::flatten<two_levels>, flat_two_levels>::value, "invalid flatten on two levels sequence");

using three_levels = brigand::list<brigand::list<flat_seq, bool, int>, brigand::empty_sequence, brigand::list<brigand::list<brigand::list<char>>>, int>;
using flat_three_levels = brigand::list<char, bool, int, bool, int, char, int>;

static_assert(std::is_same<brigand::flatten<three_levels>, flat_three_levels>::value, "invalid flatten on two levels sequence");
