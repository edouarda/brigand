
#include <brigand/map.hpp>
#include <brigand/size.hpp>
#include <brigand/at.hpp>

static_assert(brigand::detail::has_at_method<brigand::map<>>::value, "at not detected!");

// empty maps are allowed
static_assert(brigand::size<brigand::map<>>::value == 0, "empty map isn't empty");
static_assert(std::is_same<brigand::lookup<brigand::map<>, int>::type, brigand::no_such_type_>::value, "should find no such type in empty map");

using map_test = brigand::map<brigand::pair<int, bool>, brigand::pair<char, int>>;

static_assert(std::is_same<brigand::lookup<map_test, int>::type, bool>::value, "should be bool");
static_assert(std::is_same<brigand::lookup<map_test, char>::type, int>::value, "should be int");
static_assert(std::is_same<brigand::lookup<map_test, bool>::type, brigand::no_such_type_>::value, "should be not found");

struct type_one {};
struct type_two {};
struct type_three {};
struct type_four {};
struct type_five {};
struct type_six {};
struct type_seven {};
struct type_eight {};
struct type_nine {};

using big_map = brigand::map<
    brigand::pair<type_one, int>,
    brigand::pair<type_two, type_one>,
    brigand::pair<type_three, type_two>,
    brigand::pair<type_four, type_three>,
    brigand::pair<type_five, type_four>,
    brigand::pair<type_six, type_five>,
    brigand::pair<type_seven, type_six>,
    brigand::pair<type_eight, type_seven>,
    brigand::pair<type_nine, type_eight>>;

static_assert(std::is_same<brigand::at<big_map, type_one>::type, int>::value,                  "not found in big map!");
static_assert(std::is_same<brigand::at<big_map, type_two>::type, type_one>::value,             "not found in big map!");
static_assert(std::is_same<brigand::at<big_map, type_three>::type, type_two>::value,           "not found in big map!");
static_assert(std::is_same<brigand::at<big_map, type_four>::type, type_three>::value,          "not found in big map!");
static_assert(std::is_same<brigand::at<big_map, type_five>::type, type_four>::value,           "not found in big map!");
static_assert(std::is_same<brigand::at<big_map, type_six>::type, type_five>::value,            "not found in big map!");
static_assert(std::is_same<brigand::at<big_map, type_seven>::type, type_six>::value,           "not found in big map!");
static_assert(std::is_same<brigand::at<big_map, type_eight>::type, type_seven>::value,         "not found in big map!");
static_assert(std::is_same<brigand::at<big_map, type_nine>::type, type_eight>::value,          "not found in big map!");
static_assert(std::is_same<brigand::at<big_map, bool>::type, brigand::no_such_type_>::value,   "found in big map!");
