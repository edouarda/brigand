#include "map_test.hpp"

#include <brigand/sequences/set.hpp>
#include <brigand/sequences/values_as_sequence.hpp>

brigand::values_as_sequence<map_of_ten> values_of_ten =
    brigand::list<int, type_one, type_two, type_three, type_four, type_five, type_six, type_seven,
                  type_eight, float ****>{};

brigand::values_as_sequence<map_of_ten, brigand::list> values_of_ten_list =
    brigand::list<int, type_one, type_two, type_three, type_four, type_five, type_six, type_seven,
                  type_eight, float ****>{};

brigand::values_as_sequence<map_of_ten, brigand::set> values_of_ten_set =
    brigand::set<int, type_one, type_two, type_three, type_four, type_five, type_six, type_seven,
                 type_eight, float ****>{};
