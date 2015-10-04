/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/types/bool.hpp>
#include <brigand/functions/lambda/apply.hpp>

namespace brigand { namespace detail
{
  // By default, consider we found nothing
  template< typename Predicate, class Sequence>
  struct find_if_impl
  {
    using type = Sequence;
  };

  // Use Predicate result in Status to stop recursion when something was found
  template<typename Status, typename Predicate, class Sequence>
  struct find_if_shortcut;

  // Try to see if we found something and try to short-cut
  template< typename Predicate
          , template<class...> class Sequence
          , typename H, typename... T
          >
  struct  find_if_impl<Predicate,Sequence<H,T...>>
        : find_if_shortcut<brigand::apply<Predicate,H>, Predicate, Sequence<H,T...> >
  {};

  // Stop ! We found it
  template<typename Predicate, class Sequence>
  struct find_if_shortcut<true_,Predicate,Sequence>
  {
    using type = Sequence;
  };

  // Consume head and go forward
  template< typename Predicate
          , template<class...> class Sequence
          , typename H, typename... T
          >
  struct  find_if_shortcut<false_,Predicate, Sequence<H,T...>>
        : find_if_impl<Predicate,Sequence<T...>>
  {};
} }
