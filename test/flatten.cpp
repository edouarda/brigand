
#include <brigand/algorithms/flatten.hpp>

#include <vector>
#include <string>

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

static_assert(std::is_same<brigand::flatten<three_levels>, flat_three_levels>::value, "invalid flatten on three levels sequence");

using proper_filter = brigand::list<std::vector<char>, std::string, flat_seq>;
using flat_proper_filter = brigand::list<std::vector<char>, std::string, char, bool, int>;

static_assert(std::is_same<brigand::flatten<proper_filter>, flat_proper_filter>::value, "invalid flatten on heterogenous sequence");

template <class ...> class custom_list;

using flat_seq_custom = custom_list<char, bool, int>;
using one_level_custom = custom_list<custom_list<char, bool, int>, flat_seq_custom, char, char>;
using flat_one_level_custom = custom_list<char, bool, int, char, bool, int, char, char>;

static_assert(std::is_same<brigand::flatten<one_level_custom>, flat_one_level_custom>::value, "invalid flatten on three levels sequence");
