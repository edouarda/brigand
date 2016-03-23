/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/algorithms/transform.hpp>
#include <brigand/algorithms/wrap.hpp>
#include <brigand/functions/lambda/apply.hpp>
#include <brigand/sequences/append.hpp>
#include <brigand/sequences/clear.hpp>
#include <type_traits>

namespace brigand
{
namespace detail
{
    template <bool B, typename T>
    struct remove_if_wrap
    {
        using type = brigand::list<T>;
    };
    template <typename T>
    struct remove_if_wrap<true, T>
    {
        using type = brigand::list<>;
    };

    template <typename Pred, typename T> // MSVC work around
    using remove_if_pred = brigand::apply<Pred, T>;
    template <typename T,
              typename U> // MSVC can't expand two instances of the same pack in one expression
    struct call_remove_if_wrap
    {
        using type = typename remove_if_wrap<remove_if_pred<T, U>::value, U>::type;
    };

    template <typename T, typename Pred>
    struct remove_if_impl;

    template <template <class...> class L, typename... Ts, typename Pred>
    struct remove_if_impl<L<Ts...>, Pred>
    {
        using type = brigand::append<L<>, typename call_remove_if_wrap<Pred, Ts>::type...>;
    };
}

namespace lazy
{
    template <typename L, typename Pred>
    using remove_if = typename detail::remove_if_impl<L, Pred>;
}

template <typename L, typename Pred>
using remove_if = typename ::brigand::lazy::remove_if<L, Pred>::type;

namespace lazy
{
    template <typename L, typename T>
    struct remove;

    template <template<class...> class L, typename... Ts, typename T>
    struct remove<L<Ts...>, T>
    : ::brigand::detail::append_impl<L<>, typename std::conditional<std::is_same<Ts,T>::value, list<>, list<Ts>>::type...>
    {
    };
}

template <typename L, typename T>
using remove = typename lazy::remove<L, T>::type;
}
