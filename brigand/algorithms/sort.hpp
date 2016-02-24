/*==================================================================================================
Copyright (c) 2015 Edouard Alligand and Joel Falcou

Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/algorithms/wrap.hpp>
#include <brigand/functions/comparison/less.hpp>
#include <brigand/functions/lambda/apply.hpp>
#include <brigand/functions/lambda/quote.hpp>
#include <brigand/sequences/append.hpp>

namespace brigand
{
namespace detail
{
    template <typename P>
    struct S
    {
        template <typename T, typename U>
        struct Pred : brigand::apply<P, T, U>
        {
        };

        template <typename Out, typename In, bool Tag, bool FTag, typename... Ts>
        struct insert;

        // next is not less than insert, no more ins, terminate
        template <typename... Os, typename In, typename... Ts>
        struct insert<list<Os...>, list<In>, false, false, Ts...>
        {
            using type = list<Os..., In, Ts...>;
        };

        // next is less than insert, next is end, terminate
        template <typename... Os, typename... Ins, typename T>
        struct insert<list<Os...>, list<Ins...>, true, false, T>
        {
            using type = list<Os..., T, Ins...>;
        };

        // next is not less than insert, have more next and have more ins, can't fast track
        template <typename... Os, typename In1, typename In2, typename... Ins, typename T,
                  typename... Ts>
        struct insert<list<Os...>, list<In1, In2, Ins...>, false, false, T, Ts...>
            : insert<list<Os..., In1>, list<In2, Ins...>, Pred<T, In2>::value, false, T, Ts...>
        {
        };
        // next is not less than insert, have more next and have more ins, can fast track
        template <typename... Os, typename In1, typename In2, typename... Ins, typename T1,
                  typename T2, typename T3, typename T4, typename T5, typename T6, typename T7,
                  typename T8, typename... Ts>
        struct insert<list<Os...>, list<In1, In2, Ins...>, false, false, T1, T2, T3, T4, T5, T6, T7,
                      T8, Ts...>
            : insert<list<Os..., In1>, list<In2, Ins...>, Pred<T1, In2>::value,
                     Pred<T8, In2>::value, T1, T2, T3, T4, T5, T6, T7, T8, Ts...>
        {
        };
        // next is less than insert, next is not end
        template <typename... Os, typename In, typename... Ins, typename T1, typename T2,
                  typename... Ts>
        struct insert<list<Os...>, list<In, Ins...>, true, false, T1, T2, Ts...>
            : insert<list<Os..., T1>, list<In, Ins...>, Pred<T2, In>::value, false, T2, Ts...>
        {
        };
        // fast track is less than insert, no more
        template <typename... Os, typename In, typename... Ins, typename T1, typename T2,
                  typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
        struct insert<list<Os...>, list<In, Ins...>, true, true, T1, T2, T3, T4, T5, T6, T7, T8>
        {
            using type = list<Os..., T1, T2, T3, T4, T5, T6, T7, T8, In, Ins...>;
        };

        // fast track is less than insert, not enough to fast track again
        template <typename... Os, typename In, typename... Ins, typename T1, typename T2,
                  typename T3, typename T4, typename T5, typename T6, typename T7, typename T8,
                  typename T9, typename... Ts>
        struct insert<list<Os...>, list<In, Ins...>, true, true, T1, T2, T3, T4, T5, T6, T7, T8, T9,
                      Ts...> : insert<list<Os..., T1, T2, T3, T4, T5, T6, T7, T8>, list<In, Ins...>,
                                      Pred<T9, In>::value, false, T9, Ts...>
        {
        };
        // fast track is less than insert, can fast track again
        template <typename... Os, typename In, typename... Ins, typename T1, typename T2,
                  typename T3, typename T4, typename T5, typename T6, typename T7, typename T8,
                  typename T9, typename T10, typename T11, typename T12, typename T13, typename T14,
                  typename T15, typename T16, typename... Ts>
        struct insert<list<Os...>, list<In, Ins...>, true, true, T1, T2, T3, T4, T5, T6, T7, T8, T9,
                      T10, T11, T12, T13, T14, T15, T16, Ts...>
            : insert<list<Os..., T1, T2, T3, T4, T5, T6, T7, T8>, list<In, Ins...>,
                     Pred<T9, In>::value, Pred<T16, In>::value, T9, T10, T11, T12, T13, T14, T15,
                     T16, Ts...>
        {
        };

        template <typename Out, typename In>
        struct insert_helper;

        // cant fast track
        template <typename O, typename... Os, typename In, typename... Ins>
        struct insert_helper<list<O, Os...>, list<In, Ins...>>
            : insert<list<>, list<In, Ins...>, Pred<O, In>::value, false, O, Os...>
        {
        };
        // can fast track
        template <typename O1, typename O2, typename O3, typename O4, typename O5, typename O6,
                  typename O7, typename O8, typename... Os, typename In, typename... Ins>
        struct insert_helper<list<O1, O2, O3, O4, O5, O6, O7, O8, Os...>, list<In, Ins...>>
            : insert<list<>, list<In, Ins...>, Pred<O1, In>::value, Pred<O8, In>::value, O1, O2, O3,
                     O4, O5, O6, O7, O8, Os...>
        {
        };

        template <typename Out, typename... Ts>
        struct sort_loop
        {
            using type = Out; // in is empty
        };
        // cant fast track
        template <typename Out, typename In, typename... Ts>
        struct sort_loop<Out, In, Ts...>
            : sort_loop<typename insert_helper<Out, list<In>>::type, Ts...>
        {
        };
        // can fast track
        template <typename Out, typename T1, typename T2, typename T3, typename T4, typename T5,
                  typename T6, typename T7, typename T8, typename T9, typename T10, typename T11,
                  typename T12, typename T13, typename T14, typename T15, typename T16,
                  typename... Ts>
        struct sort_loop<Out, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16,
                         Ts...>
            : sort_loop<typename insert_helper<
                            Out, typename sort_loop<list<T1>, T2, T3, T4, T5, T6, T7, T8, T9, T10,
                                                    T11, T12, T13, T14, T15, T16>::type>::type,
                        Ts...>
        {
        };
    };
    // Sort
    template <typename Seq, typename Comp>
    struct sort_impl;
    // empty input case
    template <template <class...> class Seq, typename... T, typename Comp>
    struct sort_impl<Seq<T...>, Comp>
    {
        using type = Seq<T...>;
    };
    // one element case
    template <template <class...> class Seq, typename T, typename Comp>
    struct sort_impl<Seq<T>, Comp>
    {
        using type = Seq<T>;
    };
    // two or more elements case
    template <template <class...> class Seq, typename T, typename U, typename... Ts, typename Comp>
    struct sort_impl<Seq<T, U, Ts...>, Comp>
    {
        using type =
            brigand::wrap<typename S<Comp>::template sort_loop<list<T>, U, Ts...>::type, Seq>;
    };
}

template <typename Seq, typename Comp = quote<less>>
using sort = typename detail::sort_impl<Seq, Comp>::type;
}
