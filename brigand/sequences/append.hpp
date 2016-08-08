/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/sequences/list.hpp>
#include <brigand/algorithms/wrap.hpp>

namespace brigand
{
namespace detail
{
    template <typename... Ts>
    struct append_impl
    {
        using type = brigand::empty_sequence;
    };

    template <typename T>
    struct append_impl<T>
    {
        using type = T;
    };

    template <template <typename...> class L1, template <typename...> class L2, typename... T1s,
              typename... T2s, typename... Ts>
    struct append_impl<L1<T1s...>, L2<T2s...>, Ts...> : append_impl<L1<T1s..., T2s...>, Ts...>
    {
    };
    // fast track
    template <template <typename...> class L, template <typename...> class L1,
              template <typename...> class L2, template <typename...> class L3,
              template <typename...> class L4, template <typename...> class L5,
              template <typename...> class L6, template <typename...> class L7,
              template <typename...> class L8, template <typename...> class L9,
              template <typename...> class L10, template <typename...> class L11,
              template <typename...> class L12, template <typename...> class L13,
              template <typename...> class L14, template <typename...> class L15,
              template <typename...> class L16, typename... Ts, typename... T1s, typename... T2s,
              typename... T3s, typename... T4s, typename... T5s, typename... T6s, typename... T7s,
              typename... T8s, typename... T9s, typename... T10s, typename... T11s,
              typename... T12s, typename... T13s, typename... T14s, typename... T15s,
              typename... T16s, typename... Us>
    struct append_impl<L<Ts...>, L1<T1s...>, L2<T2s...>, L3<T3s...>, L4<T4s...>, L5<T5s...>,
                       L6<T6s...>, L7<T7s...>, L8<T8s...>, L9<T9s...>, L10<T10s...>, L11<T11s...>,
                       L12<T12s...>, L13<T13s...>, L14<T14s...>, L15<T15s...>, L16<T16s...>, Us...>
        : append_impl<L<Ts..., T1s..., T2s..., T3s..., T4s..., T5s..., T6s..., T7s..., T8s...,
                        T9s..., T10s..., T11s..., T12s..., T13s..., T14s..., T15s..., T16s...>,
                      Us...>
    {
    };
}
namespace lazy
{
	template <typename... Ts>
	using append = detail::append_impl<Ts...>;
}
template <typename... Ts>
using append = typename detail::append_impl<Ts...>::type;


namespace lazy
{
	template <typename T>
	struct join;
	template<template<typename...> class L, typename...Ts>
	struct join<L<Ts...>> : ::brigand::detail::append_impl<L<>,Ts...>
	{
	};
}
template <typename T>
using join = wrap<T,append>;
}
