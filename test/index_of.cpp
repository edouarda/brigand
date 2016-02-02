#include <brigand/algorithms/index_of.hpp>

using l1 = brigand::list<int, void, float, int *>;

brigand::size_t<0> i_int = brigand::index_of<l1, int>{};
brigand::size_t<1> i_void = brigand::index_of<l1, void>{};
brigand::size_t<2> i_float = brigand::index_of<l1, float>{};
brigand::size_t<3> i_int_p = brigand::index_of<l1, int *>{};

brigand::no_such_type_ i_double = brigand::index_of<l1, double>{};
