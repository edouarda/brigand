#include "map_test.hpp"

#include <brigand/sequences/map.hpp>
#include <brigand/sequences/size.hpp>
#include <brigand/sequences/at.hpp>
#include <brigand/sequences/erase.hpp>
#include <brigand/sequences/has_key.hpp>
#include <brigand/sequences/insert.hpp>

static_assert(brigand::detail::has_at_method<brigand::map<>>::value, "at not detected!");

// empty maps are allowed
static_assert(brigand::size<brigand::map<>>::value == 0, "empty map isn't empty");
static_assert(std::is_same<brigand::lookup<brigand::map<>, int>, brigand::no_such_type_>::value, "should find no such type in empty map");
static_assert(std::is_same<brigand::lookup<brigand::map<brigand::pair<int, int[1]>>, int>, int[1]>::value, "should be int[1]");
static_assert(std::is_same<brigand::lookup<brigand::map<brigand::pair<int[1], int>>, int[1]>, int>::value, "should be int");
static_assert(std::is_same<brigand::lookup<brigand::map<brigand::pair<void, int&>>, void>, int&>::value, "should be int");
static_assert(std::is_same<brigand::lookup<brigand::map<brigand::pair<int&, void>>, int&>, void>::value, "should be int");
static_assert(std::is_same<brigand::lookup<brigand::map<brigand::pair<void, int&>>, int&>, brigand::no_such_type_>::value, "should be int");
static_assert(std::is_same<brigand::lookup<brigand::map<brigand::pair<int&, void>>, void>, brigand::no_such_type_>::value, "should be int");

using map_test = brigand::map<brigand::pair<int, bool>, brigand::pair<char, int>>;

void map_has_key_test()
{
  brigand::has_key<map_test, int>{} = std::true_type{};
  brigand::has_key<map_test, char>{} = std::true_type{};
  brigand::has_key<map_test, bool>{} = std::false_type{};
  brigand::has_key<map_test, void>{} = std::false_type{};
  brigand::has_key<brigand::map<>, void>{} = std::false_type{};
}

void map_erase_test()
{
  brigand::erase<map_test, int>{} = brigand::map<brigand::pair<char, int>>{};
  brigand::erase<map_test, char>{} = brigand::map<brigand::pair<int, bool>>{};
  brigand::erase<map_test, bool>{} = map_test{};
  brigand::erase<map_test, void>{} = map_test{};
  brigand::erase<brigand::map<>, void>{} = brigand::map<>{};
}

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

// test insertions all the way up to the fast lanes

using map_of_one = brigand::map<pair_one>;
static_assert(std::is_same<brigand::insert<brigand::map<>, pair_one>, map_of_one>::value, "insertion failed");
static_assert(std::is_same<brigand::insert<map_of_one, pair_one>, map_of_one>::value, "insertion failed");

using map_of_two = brigand::map<pair_one, pair_two>;
static_assert(std::is_same<brigand::insert<map_of_one, pair_two>, map_of_two>::value, "insertion failed");
static_assert(std::is_same<brigand::insert<map_of_two, pair_two>, map_of_two>::value, "insertion failed");

using map_of_three = brigand::map<pair_one, pair_two, pair_three>;
static_assert(std::is_same<brigand::insert<map_of_two, pair_three>, map_of_three>::value, "insertion failed");
static_assert(std::is_same<brigand::insert<map_of_three, pair_three>, map_of_three>::value, "insertion failed");

using map_of_four = brigand::map<pair_one, pair_two, pair_three, pair_four>;
static_assert(std::is_same<brigand::insert<map_of_three, pair_four>, map_of_four>::value, "insertion failed");
static_assert(std::is_same<brigand::insert<map_of_four, pair_four>, map_of_four>::value, "insertion failed");

using map_of_five = brigand::map<pair_one, pair_two, pair_three, pair_four, pair_five>;
static_assert(std::is_same<brigand::insert<map_of_four, pair_five>, map_of_five>::value, "insertion failed");
static_assert(std::is_same<brigand::insert<map_of_five, pair_five>, map_of_five>::value, "insertion failed");

using map_of_six = brigand::map<pair_one, pair_two, pair_three, pair_four, pair_five, pair_six>;
static_assert(std::is_same<brigand::insert<map_of_five, pair_six>, map_of_six>::value, "insertion failed");
static_assert(std::is_same<brigand::insert<map_of_six, pair_six>, map_of_six>::value, "insertion failed");

using map_of_seven = brigand::map<pair_one, pair_two, pair_three, pair_four, pair_five, pair_six, pair_seven>;
static_assert(std::is_same<brigand::insert<map_of_six, pair_seven>, map_of_seven>::value, "insertion failed");
static_assert(std::is_same<brigand::insert<map_of_seven, pair_seven>, map_of_seven>::value, "insertion failed");

using map_of_eight = brigand::map<pair_one, pair_two, pair_three, pair_four, pair_five, pair_six, pair_seven, pair_eight>;
static_assert(std::is_same<brigand::insert<map_of_seven, pair_eight>, map_of_eight>::value, "insertion failed");
static_assert(std::is_same<brigand::insert<map_of_eight, pair_eight>, map_of_eight>::value, "insertion failed");

using map_of_nine = brigand::map<pair_one, pair_two, pair_three, pair_four, pair_five, pair_six, pair_seven, pair_eight, pair_nine>;
static_assert(std::is_same<brigand::insert<map_of_eight, pair_nine>, map_of_nine>::value, "insertion failed");
static_assert(std::is_same<brigand::insert<map_of_nine, pair_nine>, map_of_nine>::value, "insertion failed");

using map_of_ten = brigand::map<pair_one, pair_two, pair_three, pair_four, pair_five, pair_six, pair_seven, pair_eight, pair_nine, pair_ten>;
static_assert(std::is_same<brigand::insert<map_of_nine, pair_ten>, map_of_ten>::value, "insertion failed");
static_assert(std::is_same<brigand::insert<map_of_ten, pair_ten>, map_of_ten>::value, "insertion failed");

static_assert(std::is_same<brigand::insert<brigand::map<>, brigand::pair<void, int&>>, brigand::map<brigand::pair<void, int&>>>::value, "insertion failed");
static_assert(std::is_same<brigand::insert<brigand::map<>, brigand::pair<int&, void>>, brigand::map<brigand::pair<int&, void>>>::value, "insertion failed");

// try exhaustive on big map, we don't do a brigand::fold because we want to test map and insert only we don't want a potential problem in
// fold to interfere with this test
static_assert(std::is_same<brigand::insert<big_map, pair_one>, big_map>::value, "insertion failed");
static_assert(std::is_same<brigand::insert<big_map, pair_two>, big_map>::value, "insertion failed");
static_assert(std::is_same<brigand::insert<big_map, pair_three>, big_map>::value, "insertion failed");
static_assert(std::is_same<brigand::insert<big_map, pair_four>, big_map>::value, "insertion failed");
static_assert(std::is_same<brigand::insert<big_map, pair_five>, big_map>::value, "insertion failed");
static_assert(std::is_same<brigand::insert<big_map, pair_six>, big_map>::value, "insertion failed");
static_assert(std::is_same<brigand::insert<big_map, pair_seven>, big_map>::value, "insertion failed");
static_assert(std::is_same<brigand::insert<big_map, pair_eight>, big_map>::value, "insertion failed");
static_assert(std::is_same<brigand::insert<big_map, pair_nine>, big_map>::value, "insertion failed");
static_assert(std::is_same<brigand::insert<big_map, pair_ten>, big_map>::value, "insertion failed");
