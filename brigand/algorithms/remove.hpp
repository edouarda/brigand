/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once
#include <brigand/types/compose.hpp>
#include <brigand/sequences/clear.hpp>
#include <brigand/functions/not.hpp>

namespace brigand
{
namespace detail
{
  template< class L1, template<class> class Pred, class L2 = clear<L1>>
  struct remove_if_impl;

  template< class L1, template<class> class Pred, class L2, bool >
  struct remove_if_impl_shortcut;

  template< template<class...> class L1, class T, class... Ts,
            template<class> class Pred,
            template<class...> class L2, class... Us >
  struct remove_if_impl_shortcut<L1<T, Ts...>, Pred, L2<Us...>, true>
  {
    using type = typename remove_if_impl<L1<Ts...>, Pred, L2<Us...>>::type;
  };

  template< template<class...> class L1, class T, class... Ts,
            template<class> class Pred,
            template<class...> class L2, class... Us >
  struct remove_if_impl_shortcut<L1<T, Ts...>, Pred, L2<Us...>, false>
  {
    using type = typename remove_if_impl<L1<Ts...>, Pred, L2<Us..., T>>::type;
  };

  template< template<class...> class L1, class T, class... Ts,
            template<class> class Pred, class L2 >
  struct remove_if_impl<L1<T, Ts...>, Pred, L2>
  : remove_if_impl_shortcut<L1<T, Ts...>, Pred, L2, bool(Pred<T>::value)>
  {};

  template< template<class...> class L1,
            template<class> class Pred, class L2 >
  struct remove_if_impl<L1<>, Pred, L2>
  {
    using type = L2;
  };
}

  template<class L, template<class> class Pred = not_>
  using remove_if = typename detail::remove_if_impl<L, Pred>::type;

  template<class L, class T>
  using remove = typename detail::remove_if_impl<L, unary_compose<std::is_same, T>::template type>::type;
}
