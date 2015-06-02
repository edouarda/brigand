
#pragma once

#include <brigand/for_each_args.hpp>

namespace brigand
{
  namespace detail
  {
    template<template<class...> class List, typename... Elements, typename Functor>
    Functor for_each_impl( List<Elements...>&&, Functor f )
    {
      return for_each_args( f, Elements()... );
    }
  }

  template<typename List, typename Functor> Functor for_each( Functor f )
  {
    return detail::for_each_impl( List{}, f );
  }
}
