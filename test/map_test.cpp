
#include <brigand/sequences/map.hpp>
#include <brigand/sequences/size.hpp>
#include <brigand/sequences/at.hpp>

static_assert(brigand::detail::has_at_method<brigand::map<>>::value, "at not detected!");

// empty maps are allowed
static_assert(brigand::size<brigand::map<>>::value == 0, "empty map isn't empty");
static_assert(std::is_same<brigand::lookup<brigand::map<>, int>, brigand::no_such_type_>::value, "should find no such type in empty map");

using map_test = brigand::map<brigand::pair<int, bool>, brigand::pair<char, int>>;

static_assert(std::is_same<brigand::lookup<map_test, int>, bool>::value, "should be bool");
static_assert(std::is_same<brigand::lookup<map_test, char>, int>::value, "should be int");
static_assert(std::is_same<brigand::lookup<map_test, bool>, brigand::no_such_type_>::value, "should be not found");

static_assert(std::is_same<brigand::insert<map_test, brigand::pair<bool, char>>, brigand::map<brigand::pair<int, bool>, brigand::pair<char, int>, brigand::pair<bool, char>>>::value,   "invalid insert result");
static_assert(std::is_same<brigand::insert<map_test, brigand::pair<int, int>>, map_test>::value,   "invalid insert result");

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
    brigand::pair<type_nine, type_eight>,
    brigand::pair<void, float****>
    >;

static_assert(std::is_same<brigand::at<big_map, type_one>, int>::value,                  "not found in big map!");
static_assert(std::is_same<brigand::at<big_map, type_two>, type_one>::value,             "not found in big map!");
static_assert(std::is_same<brigand::at<big_map, type_three>, type_two>::value,           "not found in big map!");
static_assert(std::is_same<brigand::at<big_map, type_four>, type_three>::value,          "not found in big map!");
static_assert(std::is_same<brigand::at<big_map, type_five>, type_four>::value,           "not found in big map!");
static_assert(std::is_same<brigand::at<big_map, type_six>, type_five>::value,            "not found in big map!");
static_assert(std::is_same<brigand::at<big_map, type_seven>, type_six>::value,           "not found in big map!");
static_assert(std::is_same<brigand::at<big_map, type_eight>, type_seven>::value,         "not found in big map!");
static_assert(std::is_same<brigand::at<big_map, type_nine>, type_eight>::value,          "not found in big map!");
static_assert(std::is_same<brigand::at<big_map, void>, float****>::value,          "not found in big map!");
static_assert(std::is_same<brigand::at<big_map, bool>, brigand::no_such_type_>::value,   "found in big map!");
