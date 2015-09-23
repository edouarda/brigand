/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/sequences/clear.hpp>
#include <brigand/functions/apply.hpp>
#include <type_traits>

namespace brigand
{
  namespace detail
  {
    template< class L1, typename Pred, class L2 = clear<L1>>
    struct remove_if_impl
    {
      using type = L2;
    };

    template< class L1, typename Pred, class L2, bool >
    struct remove_if_shortcut;

    template< template<class...> class L1, class T, class... Ts,
              typename Pred,
              template<class...> class L2, class... Us >
    struct remove_if_shortcut<L1<T, Ts...>, Pred, L2<Us...>, true>
    : remove_if_impl<L1<Ts...>, Pred, L2<Us...>>
    {};

    template< template<class...> class L1, class T, class... Ts,
              typename Pred,
              template<class...> class L2, class... Us >
    struct remove_if_shortcut<L1<T, Ts...>, Pred, L2<Us...>, false>
    : remove_if_impl<L1<Ts...>, Pred, L2<Us..., T>>
    {};

    template<typename Pred, typename T> using pred = brigand::apply<Pred,T>;

    template< template<class...> class L1, class T, class... Ts,
              typename Pred, class L2 >
    struct remove_if_impl<L1<T, Ts...>, Pred, L2>
    : remove_if_shortcut< L1<T, Ts...>, Pred, L2
                        , bool(pred<Pred,T>::value)
                        >
    {};
  }

    template<typename L, typename Pred>
    using remove = typename detail::remove_if_impl<L, Pred>::type;


namespace detail
{
    template< typename L1, typename T, typename L2 = clear<L1>>
    struct remove_element_impl
    {
      using type = L2;
    };

    template< template<class...> class L1, typename T, typename... Ts,
              typename U, template<class...> class L2, typename... Us >
    struct remove_element_impl<L1<T, Ts...>, U, L2<Us...>>
    : remove_element_impl<L1<Ts...>, U, L2<Us..., T>>
    {};

    template< template<class...> class L1, typename T, typename... Ts,
              template<class...> class L2, typename... Us >
    struct remove_element_impl<L1<T, Ts...>, T, L2<Us...>>
    : remove_element_impl<L1<Ts...>, T, L2<Us...>>
    {};
}

    template<typename L, typename T>
    using remove_element = typename detail::remove_element_impl<L, T>::type;
}
