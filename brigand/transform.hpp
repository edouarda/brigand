
#pragma once

namespace brigand
{
  namespace detail
  {
    template< template<class...> class Functor, class... Sequence>
    struct transform_impl;

    // Unary transform implementation
    template< template<class> class Functor
            , template<class...> class Sequence, class... T
            >
    struct transform_impl<Functor, Sequence<T...>>
    {
      using type = Sequence< Functor<T>... >;
    };

    // Binary transform implementation
    template< template<class,class> class Functor
            , template<class...> class Sequence1, class... T1
            , template<class...> class Sequence2, class... T2
            >
    struct transform_impl<Functor, Sequence1<T1...>, Sequence2<T2...>>
    {
      static_assert ( sizeof...(T1) == sizeof...(T2)
                    , "The arguments of transform should be of the same size"
                    );

      using type = Sequence1< Functor<T1,T2>... >;
    };
  }

  // Main transform entry point
  template<template<class...> class Functor, class... Sequence >
  using transform = typename detail::transform_impl<Functor, Sequence...>::type;
}
