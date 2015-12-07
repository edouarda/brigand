#include <brigand/algorithms/replace.hpp>

brigand::replace<brigand::list<>, int, float> replace_on_empty_list = brigand::list<>{};

brigand::replace<brigand::list<double, float>, int, float> replace_no_op = brigand::list<double, float>{};

brigand::replace<brigand::list<int>, int, float> replace_test1 = brigand::list<float>{};

brigand::replace<brigand::list<double>, int, float> replace_test2 = brigand::list<double>{};

//brigand::replace<brigand::list<int, float>, int, float> replace_int_to_float = brigand::list<float, float>{};
