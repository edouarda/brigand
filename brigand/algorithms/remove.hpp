/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/functions/lambda/apply.hpp>
#include <brigand/sequences/clear.hpp>
#include <type_traits>

namespace brigand
{
namespace detail
{
    template <class L1, typename Pred, class L2 = clear<L1>>
    struct remove_if_impl
    {
        using type = L2;
    };

    template <class L1, typename Pred, class L2, bool>
    struct remove_if_shortcut;

    template <template <class...> class L1, class T, class... Ts, typename Pred,
              template <class...> class L2, class... Us>
    struct remove_if_shortcut<L1<T, Ts...>, Pred, L2<Us...>, true>
        : remove_if_impl<L1<Ts...>, Pred, L2<Us...>>
    {
    };

    template <template <class...> class L1, class T, class... Ts, typename Pred,
              template <class...> class L2, class... Us>
    struct remove_if_shortcut<L1<T, Ts...>, Pred, L2<Us...>, false>
        : remove_if_impl<L1<Ts...>, Pred, L2<Us..., T>>
    {
    };

    template <typename Pred, typename T>
    using pred = brigand::apply<Pred, T>;

    template <template <class...> class L1, class T, class... Ts, typename Pred, class L2>
    struct remove_if_impl<L1<T, Ts...>, Pred, L2>
        : remove_if_shortcut<L1<T, Ts...>, Pred, L2, bool(pred<Pred, T>::value)>
    {
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
    template <typename T>
    struct remove_if_pred
    {
        template <typename U>
        struct apply
        {
            using type =
                typename std::conditional<std::is_same<T, U>::value, list<>, list<U>>::type;
        };
    };
}
namespace lazy
{
    template <typename L, typename T>
    using remove = brigand::wrap<brigand::transform<L, detail::remove_if_pred<T>>, brigand::append>;
}

template <typename L, typename T>
using remove = lazy::remove<L, T>;
}
