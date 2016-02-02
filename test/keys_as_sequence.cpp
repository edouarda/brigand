#include "map_test.hpp"

#include <brigand/sequences/keys_as_sequence.hpp>

brigand::keys_as_sequence<map_of_ten> keys_of_ten =
    brigand::set<type_one, type_two, type_three, type_four, type_five, type_six, type_seven,
                 type_eight, type_nine, void>{};

brigand::keys_as_sequence<map_of_ten, brigand::set> keys_of_ten_set =
    brigand::set<type_one, type_two, type_three, type_four, type_five, type_six, type_seven,
                 type_eight, type_nine, void>{};

brigand::keys_as_sequence<map_of_ten, brigand::list> keys_of_ten_list =
    brigand::list<type_one, type_two, type_three, type_four, type_five, type_six, type_seven,
                  type_eight, type_nine, void>{};
