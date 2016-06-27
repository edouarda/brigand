
#include <brigand/sequences/set.hpp>
#include <brigand/sequences/size.hpp>
#include <brigand/sequences/at.hpp>
#include <brigand/sequences/erase.hpp>
#include <brigand/sequences/insert.hpp>
#include <brigand/sequences/has_key.hpp>

// empty sets are allowed
static_assert(brigand::size<brigand::set<>>::value == 0, "empty set isn't empty");
static_assert(!brigand::contains<brigand::set<>, int>::value, "should find no such type in empty set");

using set_test = brigand::set<int,char>;

static_assert(brigand::contains<set_test, int>::value, "should be bool");
static_assert(brigand::contains<set_test, char>::value, "should be int");
static_assert(!brigand::contains<set_test, bool>::value, "should be not found");

static_assert(std::is_same<brigand::has_key<set_test, bool>, std::false_type>::value,   "invalid has_key result");
static_assert(std::is_same<brigand::has_key<set_test, int>, std::true_type>::value,   "invalid has_key result");
static_assert(std::is_same<brigand::has_key<set_test, void>, std::false_type>::value,   "invalid has_key result");

static_assert(std::is_same<brigand::insert<set_test, void>, brigand::set<int, char, void>>::value,   "invalid insert result");
static_assert(std::is_same<brigand::insert<set_test, bool>, brigand::set<int, char, bool>>::value,   "invalid insert result");
static_assert(std::is_same<brigand::insert<set_test, int>, set_test>::value,   "invalid insert result");

static_assert(brigand::detail::has_erase_method<set_test>::value, "invalid has_erase_method");

static_assert(std::is_same<brigand::erase<set_test, int>, brigand::set<char>>::value,   "invalid erase result");
static_assert(std::is_same<brigand::erase<set_test, char>, brigand::set<int>>::value,   "invalid erase result");
static_assert(std::is_same<brigand::erase<set_test, bool>, set_test>::value,   "invalid erase result");
static_assert(std::is_same<brigand::erase<set_test, void>, set_test>::value,   "invalid erase result");


static_assert(brigand::contains<brigand::set<void, int&>, int&>::value, "should be int&");
static_assert(brigand::contains<brigand::set<int&, void>, void>::value, "should be void");

static_assert(brigand::has_key<brigand::set<void, int&>, int&>::value, "invalid has_key result");
static_assert(brigand::has_key<brigand::set<int&, void>, void>::value, "invalid has_key result");

static_assert(std::is_same<brigand::insert<brigand::set<>, int&>, brigand::set<int&>>::value,   "invalid insert result");
static_assert(std::is_same<brigand::insert<brigand::set<int&>, int&>, brigand::set<int&>>::value,   "invalid insert result");
static_assert(std::is_same<brigand::insert<brigand::set<int>, int&>, brigand::set<int, int&>>::value,   "invalid insert result");

static_assert(std::is_same<brigand::erase<brigand::set<int&>, int&>, brigand::set<>>::value,   "invalid erase result");
static_assert(std::is_same<brigand::erase<brigand::set<int&, int>, int&>, brigand::set<int>>::value,   "invalid erase result");
static_assert(std::is_same<brigand::erase<brigand::set<void>, void>, brigand::set<>>::value,   "invalid erase result");
static_assert(std::is_same<brigand::erase<brigand::set<int&, void>, void>, brigand::set<int&>>::value,   "invalid erase result");


struct type_one {};
struct type_two {};
struct type_three {};
struct type_four {};
struct type_five {};
struct type_six {};
struct type_seven {};
struct type_eight {};
struct type_nine {};

using big_set = brigand::set< type_one,type_two,type_three
                            , type_four,type_five,type_six
                            , type_seven,type_eight,type_nine
                            , void
                            >;

static_assert(brigand::contains<big_set, type_one>::value,                  "not found in big set!");
static_assert(brigand::contains<big_set, type_two>::value,             "not found in big set!");
static_assert(brigand::contains<big_set, type_three>::value,           "not found in big set!");
static_assert(brigand::contains<big_set, type_four>::value,          "not found in big set!");
static_assert(brigand::contains<big_set, type_five>::value,           "not found in big set!");
static_assert(brigand::contains<big_set, type_six>::value,            "not found in big set!");
static_assert(brigand::contains<big_set, type_seven>::value,           "not found in big set!");
static_assert(brigand::contains<big_set, type_eight>::value,         "not found in big set!");
static_assert(brigand::contains<big_set, type_nine>::value,          "not found in big set!");
static_assert(brigand::contains<big_set, void>::value,          "not found in big set!");
static_assert(!brigand::contains<big_set, bool>::value,   "found in big set!");
