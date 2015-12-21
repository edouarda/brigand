
#include <brigand/algorithms/split.hpp>


static_assert(std::is_same<brigand::split<brigand::empty_sequence, void>, brigand::empty_sequence>::value, "invalid split on empty sequence");

using no_delim_seq = brigand::list<char, bool, int>;

static_assert(std::is_same<brigand::split<no_delim_seq, void>, brigand::list<no_delim_seq>>::value, "invalid split on sequence with no delim");

using one_delim = brigand::list<char, bool, int, void, char, char>;

static_assert(std::is_same<brigand::split<one_delim, void>, brigand::list<brigand::list<char, bool, int>, brigand::list<char, char>>>::value, "invalid flatten on one level sequence");
