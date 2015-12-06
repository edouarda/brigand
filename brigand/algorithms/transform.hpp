/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/functions/lambda/apply.hpp>

namespace brigand
{
  namespace detail
  {

  template <typename Functor, typename Sequence>
  struct unary_transform_impl;

    // Unary transform implementation
    template< typename Functor
            , template<class...> class Sequence, typename... T
            >
  struct unary_transform_impl<Functor, Sequence<T...>>
    {
      using type = Sequence< brigand::apply<Functor,T>... >;
    };

  template<typename Functor, typename Sequence1, typename Sequence2>
  struct binary_transform_impl;

    // Binary transform implementation
    template< typename Functor
            , template<class...> class Sequence1, typename... T1
            , template<class...> class Sequence2, typename... T2
            >
  struct binary_transform_impl<Functor, Sequence1<T1...>, Sequence2<T2...>>
    {
      static_assert ( sizeof...(T1) == sizeof...(T2)
                    , "The arguments of transform should be of the same size"
                    );

      using type = Sequence1< brigand::apply<Functor,T1,T2>... >;
  };

  template <std::size_t Selector, typename Sequence1, typename Functor, typename Sequence2 = void>
  struct transform_selector;

  template <typename Sequence1, typename Functor>
  struct transform_selector <0, Sequence1, Functor, void>
  {
    using type = typename unary_transform_impl<Functor, Sequence1>::type;
  };

  template <typename Sequence1, typename Sequence2, typename Functor>
  struct transform_selector<1, Sequence1, Sequence2, Functor>
  {
    using type = typename binary_transform_impl<Functor, Sequence1, Sequence2>::type;
  };

  }

namespace lazy
{
    template<typename Sequence1, typename OpSeq1, typename... OpSeq2>
    using transform = typename detail::transform_selector<sizeof...(OpSeq2), Sequence1, OpSeq1, OpSeq2...>;
}

  // Main transform entry point
  template<typename Sequence1, typename OpSeq1, typename... OpSeq2>
  using transform = typename detail::transform_selector<sizeof...(OpSeq2), Sequence1, OpSeq1, OpSeq2...>::type;

}
