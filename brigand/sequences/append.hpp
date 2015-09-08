/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/sequences/list.hpp>

namespace brigand
{
  namespace detail
  {
    template <typename... Ls> struct append_impl;

    template <>
    struct append_impl<>
    {
      using type = empty_list;
    };

    template< template<class...> class L
            , typename... Ts
            >
    struct  append_impl<L<Ts...> >
    {
      using type = L<Ts...>;
    };

    template< template<class...> class L1, typename... Ts1
            , template<class...> class L2, typename... Ts2
            , typename... Ls>
    struct  append_impl<L1<Ts1...>, L2<Ts2...>, Ls...>
         :  append_impl<L1<Ts1..., Ts2...>, Ls...>
    {};
  }

  template<typename... L>
  using append = typename detail::append_impl<L...>::type;
}
