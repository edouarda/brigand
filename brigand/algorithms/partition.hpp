/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/functions/lambda/apply.hpp>
#include <brigand/algorithms/remove.hpp>
#include <brigand/sequences/pair.hpp>
#include <brigand/types/bool.hpp>

namespace brigand
{
  namespace detail
  {
    template<typename T>
    struct not_pred
    {
		using type = std::integral_constant<bool,(!T::value)>;
    };
  }

  template<class Seq, class Pred>
  using partition = pair<remove_if<Seq, detail::not_pred<Pred>>, remove_if<Seq, Pred>>;
}
