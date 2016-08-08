/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/types/bool.hpp>
#include <brigand/functions/lambda/apply.hpp>
#include <brigand/algorithms/detail/non_null.hpp>
#include <brigand/algorithms/all.hpp>

namespace brigand
{
  namespace detail
  {
    template<typename Sequence, typename Pred> struct none_impl
    {
		template<typename T>
      struct nope
      {
          using that = brigand::apply<Pred,T>;
          using type = bool_<!that::value>;
      };

      using type = all<Sequence,nope<_1>>;
    };
  }

  // Is a predicate true for no type ?
  template< typename Sequence, typename Predicate = detail::non_null>
  using none = typename detail::none_impl<Sequence,Predicate>::type;
}
