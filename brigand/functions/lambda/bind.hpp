/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/types/has_placeholders.hpp>
#include <type_traits>

namespace brigand
{
  namespace detail
  {
    template<typename X, typename Us, typename If = void>
    struct bind_impl
    {
      using type = X;
    };

    template<typename X, template<class...> class L, typename... Us>
    struct bind_impl<X,L<Us...>, typename std::enable_if<has_placeholders<X>::value>::type>
    {
      using type = brigand::apply<X,Us...>;
    };

    template<typename X, typename L> using bind_impl_t = typename bind_impl<X,L>::type;
  }

  template<typename MetafunctionClass, typename... Args> struct bind
  {
    template<typename... Us> struct apply
    {
      using type = brigand::apply < detail::bind_impl_t<MetafunctionClass,list<Us...>>
                                  , detail::bind_impl_t<Args,list<Us...>>...
                                  >;
    };
  };
}
