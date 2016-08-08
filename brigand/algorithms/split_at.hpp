/*==================================================================================================
Copyright (c) 2015 Edouard Alligand and Joel Falcou

Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/sequences/clear.hpp>

namespace brigand
{
namespace detail
{
    template <bool b, typename O, typename L, std::size_t I>
    struct split_at_impl; // if you get an error here your index is out of bounds
    template <template <typename...> class S, typename... Os, typename T, typename... Ts>
    struct split_at_impl<false, S<Os...>, S<T, Ts...>, 0>
    {
        using type = S<S<Os...>, S<T, Ts...>>;
    };
    template <template <typename...> class S, typename... Os, typename... Ts>
    struct split_at_impl<false, S<Os...>, S<Ts...>, 0>
    {
        using type = S<S<Os...>, S<Ts...>>;
    };
    template <template <typename...> class S, typename... Os, typename T, typename... Ts,
              std::size_t I>
    struct split_at_impl<false, S<Os...>, S<T, Ts...>, I>
        : split_at_impl<false, S<Os..., T>, S<Ts...>, (I - 1)>
    {
    };
    template <template <typename...> class S, typename... Os, typename T1, typename T2, typename T3,
              typename T4, typename T5, typename T6, typename T7, typename T8, typename T9,
              typename T10, typename T11, typename T12, typename T13, typename T14, typename T15,
              typename T16, typename... Ts, std::size_t I>
    struct split_at_impl<
        true, S<Os...>,
        S<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, Ts...>, I>
        : split_at_impl<((I - 16) > 16), S<Os..., T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12,
                                           T13, T14, T15, T16>,
                        S<Ts...>, (I - 16)>
    {
    };

    template <typename L, typename I>
    struct call_split_at_impl : split_at_impl<(I::value > 16), brigand::clear<L>, L, I::value>
    {
    };
}
namespace lazy
{
    template <typename L, typename I>
    using split_at = ::brigand::detail::call_split_at_impl<L, I>;
}
template <typename L, typename I>
using split_at = typename ::brigand::lazy::split_at<L, I>::type;
}