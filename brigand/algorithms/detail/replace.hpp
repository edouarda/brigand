/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou
  Author: Marek Kurdej

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/functions/lambda/apply.hpp>
#include <type_traits>

namespace brigand
{
namespace detail
{
// By default, consider we replace nothing
template <class Sequence, typename Predicate, typename NewType>
struct replace_if_impl
{
    using type = Sequence;
};

template <class Condition, class NewType, class T>
struct condition_test
: std::conditional<Condition::value, NewType, T>
{};

template <template <class...> class Sequence, typename Predicate, typename NewType, typename... T>
struct replace_if_impl<Sequence<T...>, Predicate, NewType>
{
    using type = Sequence<typename condition_test<::brigand::apply<Predicate, T>, NewType, T
    >::type...>;
};
}
}
