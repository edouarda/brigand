/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/types/bool.hpp>
#include <brigand/types/args.hpp>

namespace brigand
{
namespace detail
{
    // Default find-like predicate

    template <typename Args>
  struct non_null_impl : bool_<Args::value != 0>{};
    using non_null = non_null_impl<_1>;
}
}
