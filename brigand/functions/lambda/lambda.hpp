/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/sequences/list.hpp>
#include <brigand/types/has_type.hpp>
#include <brigand/types/has_placeholders.hpp>
#include <brigand/functions/substitute.hpp>

namespace brigand
{
  namespace detail
  {
    template<typename T, typename If = void> struct eval_;

    template<typename T> struct recurse { using type = T; };

    template<template<class...> class U, typename... T> struct recurse<U<T...>>
    {
      template<typename X> using get = typename eval_<X>::type;
      using type = U<get<T>...>;
    };

    template<typename T, typename If> struct eval_
    {
      using type = typename recurse<T>::type;
    };

    template<typename T> struct eval_<T,typename has_type<typename T::type>::type>
    {
      using type = typename recurse<T>::type::type;
    };

    template<typename F, typename Xs, typename If = void> struct lambda_impl;
    template<typename F, typename Xs> struct lambda_base;
    template<typename F, typename... Xs> struct lambda_apply;

    // If one template argument is a placeholder, substitute
    template< template<class...> class F, typename... An
            , template<class...> class L, typename... X
            >
    struct lambda_base< F<An...>, L<X...>>
    {
      using type = F<substitute<An,L<X...>>...>;
    };

    template< typename F
            , template<class...> class L, typename... X
            >
    struct lambda_base< F, L<X...>>
    {
      using type = substitute<F,L<X...>>;
    };

    template<typename F, template<class...> class L, typename... X>
    struct lambda_impl< F, L<X...>
                      , typename std::enable_if<has_placeholders<F>::value>::type
                      >
    {
      using base = typename lambda_base<F,L<X...>>::type;
      using type = typename eval_<base>::type;
    };

    // If not, just call apply directly
    template<typename F, typename... X>
    struct lambda_apply
    {
      using type = typename F::template apply<X...>::type;
    };

    template<template<class...> class F, typename... An, typename... X>
    struct lambda_apply<F<An...>,X...>
    {
      using type = typename F<An...>::template apply<X...>::type;
    };

    template<typename F, template<class...> class L, typename... X, typename If>
    struct lambda_impl<F, L<X...>, If>
    {
      using type = typename lambda_apply<F,X...>::type;
    };
  }

  template<typename F> struct lambda
  {
    template<typename... X> struct apply : detail::lambda_impl<F, brigand::list<X...>> {};
  };
}
