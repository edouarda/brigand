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

namespace detail
{
	template <typename T, typename U>
	struct  remove_pred{
		using type = brigand::list<U>;
	};
	template <typename T>
	struct remove_pred<T,T>{
		using type = brigand::list<>;
	};
}
namespace lazy
{
    template <typename L, typename T>
    using remove = brigand::wrap<brigand::append<brigand::list<brigand::clear<L>>,brigand::transform<L, detail::remove_pred<T,brigand::_1>>>, brigand::append>;
}

template <typename L, typename T>
using remove = lazy::remove<L, T>; 
}
