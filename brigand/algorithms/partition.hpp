/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/functions/lambda/protect.hpp>
#include <brigand/functions/lambda/apply.hpp>
#include <brigand/algorithms/remove.hpp>
#include <brigand/sequences/pair.hpp>
#include <brigand/types/bool.hpp>

namespace brigand
{
  namespace detail
  {
    template<class ProtectedPred>
    struct not_pred
    {
      template<class... Ts>
      struct apply
      {
        using type = bool_<!brigand::apply<typename ProtectedPred::type, Ts...>::value>;
      };
    };
  }

  template<class Seq, class Pred>
  using partition = pair<remove_if<Seq, detail::not_pred<protect<Pred>>>, remove_if<Seq, Pred>>;
}
