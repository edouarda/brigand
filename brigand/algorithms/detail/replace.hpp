/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou
  Author: Marek Kurdej

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/types/bool.hpp>
#include <brigand/functions/lambda/apply.hpp>
#include <type_traits>

#ifdef _MSC_VER
#  define BRIGAND_DEDUCED_TEMPLATE template
#else
#  define BRIGAND_DEDUCED_TEMPLATE
#endif

namespace brigand { namespace detail
{
  // By default, consider we replace nothing
  template< class Sequence, typename Predicate, typename NewType>
  struct replace_if_impl
  {
    using type = Sequence;
  };

  template <typename Predicate, typename T, typename NewType>
  struct predicate_test {
    using type = typename std::conditional<
      /*B=*/brigand::BRIGAND_DEDUCED_TEMPLATE apply<Predicate, T>::type::value,
      /*T=*/NewType,
      /*F=*/T>::type;
  };

  template<template<class...> class Sequence, typename Predicate, typename NewType, typename... T>
  struct replace_if_impl<Sequence<T...>, Predicate, NewType>
  {
    using type = Sequence<typename predicate_test<Predicate, T, NewType>::type...>;
  };

} }
