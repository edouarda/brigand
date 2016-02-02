#pragma once

#include <brigand/sequences/map.hpp>

struct type_one {};
struct type_two {};
struct type_three {};
struct type_four {};
struct type_five {};
struct type_six {};
struct type_seven {};
struct type_eight {};
struct type_nine {};

using pair_one = brigand::pair<type_one, int>;
using pair_two = brigand::pair<type_two, type_one>;
using pair_three = brigand::pair<type_three, type_two>;
using pair_four = brigand::pair<type_four, type_three>;
using pair_five = brigand::pair<type_five, type_four>;
using pair_six = brigand::pair<type_six, type_five>;
using pair_seven = brigand::pair<type_seven, type_six>;
using pair_eight = brigand::pair<type_eight, type_seven>;
using pair_nine = brigand::pair<type_nine, type_eight>;
using pair_ten = brigand::pair<void, float ****>;

using map_of_ten = brigand::map<pair_one, pair_two, pair_three, pair_four, pair_five, pair_six,
                                pair_seven, pair_eight, pair_nine, pair_ten>;
