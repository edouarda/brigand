/*==================================================================================================
Copyright (c) 2015 Edouard Alligand and Joel Falcou

Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/types/bool.hpp>
#include <brigand/functions/less.hpp>
#include <brigand/algorithms/partition.hpp>

namespace brigand
{
  namespace detail
  {
    template < template<class, class> class Pred
             , typename Seq
             >
    struct sort_impl;

    template < template<class, class> class Pred
             , template<class...> class Seq
             >
    struct sort_impl<Pred, Seq<> > {
      using type = Seq<>;
    };

    template < template<class, class> class Pred
             , template<class...> class Seq
             , typename T
             >
    struct sort_impl<Pred, Seq<T> > {
      using type = Seq<T>;
    };

    template < template<class, class> class Pred
             , template<class...> class Seq
             , typename Pivot
             , typename... Ts
             >
    struct sort_impl<Pred, Seq<Pivot, Ts...> > {
      template <typename Ls, typename P, typename Rs> struct concat;

      template<template<class...> class Seq, typename... Ls, typename P, typename... Rs>
      struct concat<Seq<Ls...>, P, Seq<Rs...> >
      {
        using type = Seq<Ls..., P, Rs...>;
      };

      template <typename T>
      struct lambda : bool_<!!Pred<Pivot, T>::value>
      {};

      using p = brigand::partition<Seq<Ts...>, lambda>;
      using type = typename concat< typename sort_impl<Pred, typename p::second_type>::type
                                  , Pivot
                                  , typename sort_impl<Pred, typename p::first_type >::type
                                  >::type;
    };
  }

  template < typename Seq
           , template<class, class> class Pred = less
           >
  using sort = typename detail::sort_impl<Pred, Seq>::type;
}
