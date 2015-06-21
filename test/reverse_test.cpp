
#include <brigand/algorithms/reverse.hpp>

#include <brigand/sequences/list.hpp>


static_assert(std::is_same<brigand::empty_list, brigand::reverse<brigand::empty_list>::type>::value, "reversing an empty list should return the same empty list");

using one_list = brigand::list<char>;

using reversed_one_list = brigand::reverse<one_list>::type;

static_assert(std::is_same<one_list, brigand::reverse<one_list>::type>::value, "reversing a one elment list should return the same list");

using two_list = brigand::list<char, int>;
using reversed_two_list = brigand::list<int, char>;

static_assert(std::is_same<reversed_two_list, brigand::reverse<two_list>::type>::value, "invalid reverse algorithm");

struct type_one {};
struct type_two {};
struct type_three {};
struct type_four {};
struct type_five {};
struct type_six {};
struct type_seven {};
struct type_eight {};
struct type_nine {};

using large_list          = brigand::list<type_one, type_two, type_three, type_four, type_five, type_six, type_seven, type_eight, type_nine>;
using reversed_large_list = brigand::list<type_nine, type_eight, type_seven, type_six, type_five, type_four, type_three, type_two, type_one>;

static_assert(std::is_same<reversed_large_list, brigand::reverse<large_list>::type>::value, "invalid reverse algorithm");
