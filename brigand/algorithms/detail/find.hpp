/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/functions/lambda/apply.hpp>
#include <brigand/types/bool.hpp>

namespace brigand
{
namespace detail
{
    template <typename P, template <class...> class Sequence>
    struct finder
    {
        template <typename T>
        struct Pred : brigand::apply<P, T>
        {
        };

        // default only if not found
        template <bool C, bool F, typename... Ts>
        struct find
        {
            using type = Sequence<>;
        };

        // found it, terminate
        template <bool F, typename T1, typename... Ts>
        struct find<true, F, T1, Ts...>
        {
            using type = Sequence<T1, Ts...>;
        };

        // not found but close enough to no fast track
        template <typename T1, typename T2, typename... Ts>
        struct find<false, true, T1, T2, Ts...> : find<Pred<T2>::value, true, T2, Ts...>
        {
        };

        // not found and not enough to no fast track again
        template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6,
                  typename T7, typename T8, typename T9, typename... Ts>
        struct find<false, false, T1, T2, T3, T4, T5, T6, T7, T8, T9, Ts...>
            : find<
                  Pred<T9>::value,
                  true /*technically we don't know if its going to be in the next 8 but if not the default will kick in so its ok*/,
                  T9, Ts...>
        {
        };

        // not found and can fast track again
        template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6,
                  typename T7, typename T8, typename T9, typename T10, typename T11, typename T12,
                  typename T13, typename T14, typename T15, typename T16, typename... Ts>
        struct find<false, false, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15,
                    T16, Ts...>
            : find<Pred<T9>::value,
                   (Pred<T9>::value || Pred<T10>::value || Pred<T11>::value || Pred<T12>::value ||
                    Pred<T13>::value || Pred<T14>::value || Pred<T15>::value || Pred<T16>::value),
                   T9, T10, T11, T12, T13, T14, T15, T16, Ts...>
        {
        };
    };
    // By default, consider we found nothing
    template <typename Predicate, class Sequence>
    struct find_if_impl
    {
        using type = Sequence;
    };

    template <typename Predicate, template <class...> class Sequence, typename T1, typename... T>
    struct find_if_impl<Predicate, Sequence<T1, T...>>
        : finder<Predicate, Sequence>::template find<false, false, void, void, void, void, void,
                                                     void, void, void, T1, T...>
    {
    };
}
}
