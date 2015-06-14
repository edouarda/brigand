/*==================================================================================================
  Copyright (c) 2015 QuasarDB
  Copyright (c) 2015 NumScale

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/apply.hpp>
#include <brigand/no_such_type.hpp>

namespace brigand
{
  template <typename... T>
  struct pair_wrapper
  {
    static_assert (sizeof...(T) == 2
                  , "as_pair requires a type list of exactly two types"
                  );

    // type need to be defined or the error becomes a hard, non-static assert error
    using type = no_such_type_;
  };

  template <typename T, typename U>
  struct pair_wrapper<T,U>
  {
      using type = typename std::pair<T,U>;
  };

  template <typename L>
  using as_pair = apply<L, pair_wrapper>;
}
