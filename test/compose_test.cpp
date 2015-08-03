
#include <type_traits>
#include <brigand/types/compose.hpp>
#include <brigand/functions/plus.hpp>
#include <brigand/functions/next.hpp>
#include <brigand/types/integer.hpp>

static_assert(std::is_same<brigand::compose<brigand::next, brigand::plus>::type<brigand::int_<1>, brigand::int_<2>>, brigand::int_<4>>::value, "invalid result");
static_assert(std::is_same<brigand::compose2<brigand::plus, brigand::next>::type<brigand::int_<1>, brigand::int_<2>>, brigand::int_<5>>::value, "invalid result");

template<template<class> class>
struct unary_compose_test
: std::true_type
{};

static_assert(unary_compose_test<brigand::unary_compose<brigand::next, brigand::next>::type>::value, "invalid result");

template<template<class, class> class>
struct binary_compose_test
: std::true_type
{};

static_assert(binary_compose_test<brigand::binary_compose<brigand::next, brigand::plus>::type>::value, "invalid result");
