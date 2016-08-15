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
    // this is essentially just a work around because MSVC can't expand variadic packs properly
    template <typename Pred, typename T, bool B>
    struct empty_if_true : std::conditional<::brigand::apply<Pred, T>::value == B, list<>, list<T>>
    {
    };
    template <template <typename...> class F, typename T, bool B>
    struct empty_if_true<bind<F, _1>, T, B> : std::conditional<F<T>::value == B, list<>, list<T>>
    {
    };
    template <template <typename...> class F, typename T, bool B>
    struct empty_if_true<F<_1>, T, B> : std::conditional<F<T>::type::value == B, list<>, list<T>>
    {
    };
}
namespace lazy
{

    template <typename L, typename Pred>
    struct remove_if;

    template <template <class...> class L, typename... Ts, typename Pred>
    struct remove_if<L<Ts...>, Pred>
        : ::brigand::detail::append_impl<
              L<>, typename ::brigand::detail::empty_if_true<Pred, Ts, true>::type...>
    {
    };
}

template <typename L, typename Pred>
using remove_if = typename lazy::remove_if<L, Pred>::type;

namespace lazy
{
    template <typename L, typename T>
    struct remove;

    template <template <class...> class L, typename... Ts, typename T>
    struct remove<L<Ts...>, T>
        : ::brigand::detail::append_impl<
              L<>, typename std::conditional<std::is_same<Ts, T>::value, list<>, list<Ts>>::type...>
    {
    };
}

template <typename L, typename T>
using remove = typename lazy::remove<L, T>::type;

namespace lazy
{

    template <typename L, typename Pred>
    struct filter;

    template <template <class...> class L, typename... Ts, typename Pred>
    struct filter<L<Ts...>, Pred>
        : ::brigand::detail::append_impl<
              L<>, typename ::brigand::detail::empty_if_true<Pred, Ts, false>::type...>
    {
    };
}

template <typename L, typename Pred>
using filter = typename lazy::filter<L, Pred>::type;
}
