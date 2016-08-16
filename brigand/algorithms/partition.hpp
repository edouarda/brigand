/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/algorithms/remove.hpp>
#include <brigand/functions/lambda/apply.hpp>
#include <brigand/sequences/pair.hpp>

namespace brigand
{
template <class Seq, class Pred>
using partition = pair<filter<Seq, Pred>, remove_if<Seq, Pred>>;
}
