
#include <brigand/sequences/list.hpp>
#include <brigand/sequences/size.hpp>
#include <brigand/sequences/append.hpp>
#include <brigand/sequences/back.hpp>
#include <brigand/sequences/front.hpp>
#include <brigand/sequences/at.hpp>
#include <brigand/sequences/erase.hpp>
#include <brigand/types/integer.hpp>

// list tests
static_assert(!brigand::detail::has_at_method<brigand::empty_list>::value, "wrongly detected at method");

static_assert(brigand::size<brigand::empty_list>::value == 0, "invalid empty list size");

using single_int_list = brigand::list<int>;

static_assert(brigand::size<single_int_list>::value == 1, "invalid single list size");

static_assert(std::is_same<brigand::push_back<brigand::empty_list, int>, single_int_list>::value, "invalid push back int");
static_assert(std::is_same<brigand::push_front<brigand::empty_list, int>, single_int_list>::value, "invalid push back int");

using int_bool_list = brigand::list<int, bool>;

using single_bool_list = brigand::list<bool>;

static_assert(std::is_same<brigand::push_back<single_int_list, bool>, int_bool_list>::value, "invalid push back result");
static_assert(std::is_same<brigand::push_front<single_bool_list, int>, int_bool_list>::value, "invalid push front result");

using int_bool_bool_int_list = brigand::list<int, bool, bool, int>;

static_assert(std::is_same<brigand::front<int_bool_list>, int>::value, "invalid front result");
static_assert(std::is_same<brigand::back<int_bool_list>, bool>::value, "invalid front result");

static_assert(std::is_same<brigand::front<int_bool_bool_int_list>, int>::value, "invalid front result");
static_assert(std::is_same<brigand::back<int_bool_bool_int_list>, int>::value, "invalid front result");

static_assert(std::is_same<brigand::pop_front<int_bool_list>, brigand::list<bool>>::value, "invalid pop front result");
static_assert(std::is_same<brigand::pop_front<int_bool_bool_int_list>, brigand::list<bool, bool, int>>::value, "invalid pop front result");
static_assert(std::is_same<brigand::pop_front<single_int_list>, brigand::empty_list>::value, "invalid pop front result");

static_assert(std::is_same<brigand::pop_back<int_bool_list>, brigand::list<int>>::value, "invalid pop back result");
static_assert(std::is_same<brigand::pop_back<int_bool_bool_int_list>, brigand::list<int, bool, bool>>::value, "invalid pop back result");
static_assert(std::is_same<brigand::pop_back<single_int_list>, brigand::empty_list>::value, "invalid pop back result");

static_assert(std::is_same<brigand::at_c<int_bool_bool_int_list, 0>, int>::value,  "invalid at result");
static_assert(std::is_same<brigand::at_c<int_bool_bool_int_list, 1>, bool>::value, "invalid at result");
static_assert(std::is_same<brigand::at_c<int_bool_bool_int_list, 2>, bool>::value, "invalid at result");
static_assert(std::is_same<brigand::at_c<int_bool_bool_int_list, 3>, int>::value,  "invalid at result");

static_assert(std::is_same<brigand::at<int_bool_bool_int_list, std::integral_constant<int, 0>>, int>::value,  "invalid at result");
static_assert(std::is_same<brigand::at<int_bool_bool_int_list, std::integral_constant<int, 1>>, bool>::value, "invalid at result");
static_assert(std::is_same<brigand::at<int_bool_bool_int_list, std::integral_constant<int, 2>>, bool>::value, "invalid at result");
static_assert(std::is_same<brigand::at<int_bool_bool_int_list, std::integral_constant<int, 3>>, int>::value,  "invalid at result");

static_assert(std::is_same<brigand::erase_c<int_bool_bool_int_list, 1>, brigand::list<int, bool, int>>::value,  "invalid erase result");
static_assert(std::is_same<brigand::erase<int_bool_bool_int_list, brigand::int_<1>>, brigand::list<int, bool, int>>::value,  "invalid erase result");

using bool_int_list = brigand::list<bool, int>;

static_assert(std::is_same<brigand::append<int_bool_list, bool_int_list>, int_bool_bool_int_list>::value, "invalid append result");
