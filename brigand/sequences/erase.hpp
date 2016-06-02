/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once
#include <brigand/algorithms/split_at.hpp>

#include <brigand/sequences/append.hpp>
#include <brigand/sequences/back.hpp>
#include <brigand/sequences/front.hpp>

#include <brigand/types/integer.hpp>
#include <brigand/types/type.hpp>


namespace brigand
{

    template<class L, std::size_t Index>
    using erase_c = append<
        front<split_at<L, size_t<Index>>>,
        pop_front<back<split_at<L, size_t<Index>>>>
    >;

namespace detail
{
    template <typename T>
    struct has_erase_method
    {
        struct dummy {};

        template <typename C, typename P>
        static auto test(P * p) -> decltype(C::erase(type_<P>{}), std::true_type());

        template <typename, typename>
        static std::false_type test(...);

        static const bool value = std::is_same<std::true_type, decltype(test<T, dummy>(nullptr))>::value;
    };


    template<class L, class I, bool>
    struct erase_dispatch
    {
        using type = erase_c<L, I::value>;
    };

    template<class C, class K>
    struct erase_dispatch<C, K, true>
    {
        using type = decltype(C::erase(type_<K>{}));
    };
}

    template<class L, class K>
    using erase = typename detail::erase_dispatch<L, K, detail::has_erase_method<L>::value>::type;
}
