#include <brigand/sequences/list.hpp>
#include <brigand/types/integer.hpp>
#include <brigand/sequences/size.hpp>
#include <brigand/sequences/append.hpp>
#include <brigand/sequences/back.hpp>
#include <brigand/sequences/front.hpp>
#include <brigand/sequences/at.hpp>

// list tests
static_assert(!brigand::detail::has_at_method<brigand::empty_sequence>::value, "wrongly detected at method");

static_assert(brigand::size<brigand::empty_sequence>::value == 0, "invalid empty list size");

using list1 = brigand::integral_list<int,42>;

static_assert(brigand::size<list1>::value == 1, "invalid single value list size");

using n_ = brigand::int_<42>;
using m_ = brigand::int_<69>;

static_assert(std::is_same<brigand::push_back<brigand::empty_sequence, n_>, list1>::value, "invalid push back int");
static_assert(std::is_same<brigand::push_front<brigand::empty_sequence, n_>, list1>::value, "invalid push back int");

using list2 = brigand::integral_list<int,69>;
using listref = brigand::integral_list<int,42,69>;

static_assert(std::is_same<brigand::push_back<list1, m_>, listref>::value, "invalid push back result");
static_assert(std::is_same<brigand::push_front<list2, n_>, listref>::value, "invalid push front result");

static_assert(std::is_same<brigand::front<listref>, n_>::value, "invalid front result");
static_assert(std::is_same<brigand::back<listref>, m_>::value, "invalid back result");

static_assert(std::is_same<brigand::pop_front<listref>, list2>::value, "invalid pop front result");
static_assert(std::is_same<brigand::pop_front<list2>, brigand::empty_sequence>::value, "invalid pop front result");

static_assert(std::is_same<brigand::pop_back<listref>, list1>::value, "invalid pop back result");
static_assert(std::is_same<brigand::pop_back<list1>, brigand::empty_sequence>::value, "invalid pop back result");

static_assert(std::is_same<brigand::at_c<listref, 0>, n_>::value,  "invalid at result");
static_assert(std::is_same<brigand::at_c<listref, 1>, m_>::value, "invalid at result");

static_assert(std::is_same<brigand::at<listref, std::integral_constant<int, 0>>, n_>::value,  "invalid at result");
static_assert(std::is_same<brigand::at<listref, std::integral_constant<int, 1>>, m_>::value, "invalid at result");

static_assert(std::is_same<brigand::append<list1, list2>, listref>::value, "invalid append result");
