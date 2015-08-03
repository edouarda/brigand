/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once
#include <type_traits>
#include <brigand/types/type.hpp>
#include <brigand/sequences/list.hpp>

namespace brigand
{
namespace detail
{
    // at
    template <int Index, class First, class... T>
    struct element_at
    {
        using type = typename element_at<Index - 1, T...>::type;
    };

    template <class First, class... T>
    struct element_at<0, First, T...>
    {
        using type = First;
    };

    template <int Index, class L> struct at_impl;

    template<int Index, template<class...> class L, class... U>
    struct at_impl<Index, L<U...>>
    {
        using type = typename element_at<Index, U...>::type;
    };
}

    template <class L, int Index>
    using at_c = typename detail::at_impl<Index, L>::type;

    template <typename M, typename K>
    using lookup = decltype(M::at(type_<K>{}));

namespace detail
{
    template <typename T>
    struct has_at_method
    {
        struct dummy {};
        template <typename C, typename P>
        static auto test(P *) -> decltype(C::at(type_<P>{}), std::true_type());

        template <typename, typename>
        static std::false_type test(...);

        static const bool value = std::is_same<std::true_type, decltype(test<T, dummy>(nullptr))>::value;
    };

    template <class L, typename Index, bool>
    struct at_dispatch
    {
        using type = at_c<L, Index::value>;
    };

    template <class L, typename Index>
    struct at_dispatch<L, Index, true>
    {
        using type = lookup<L, Index>;
    };
}

    template <class Seq, typename K>
    using at = typename detail::at_dispatch<Seq, K, detail::has_at_method<Seq>::value>::type;
}
