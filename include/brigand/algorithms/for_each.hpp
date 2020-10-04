/*!
@file

@copyright Edouard Alligand and Joel Falcou 2015-2017
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
#ifndef BOOST_BRIGAND_ALGORITHMS_FOR_EACH_HPP
#define BOOST_BRIGAND_ALGORITHMS_FOR_EACH_HPP
#include <brigand/algorithms/for_each_args.hpp>
#include <brigand/types/type.hpp>
#include <utility>

namespace brigand
{
  namespace detail
  {
    template<template<class...> class List, typename... Elements, typename Functor>
    Functor for_each_impl( type_<List<Elements...>>&&, Functor f )
    {
      return for_each_args( std::move(f), type_<Elements>()... );
    }
  }

  template<typename List, typename Functor> Functor for_each( Functor f )
  {
    return detail::for_each_impl( type_<List>{}, std::move(f) );
  }
}
#endif
