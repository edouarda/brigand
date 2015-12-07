/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/algorithms/detail/replace.hpp>
#include <brigand/functions/lambda/bind.hpp>
#include <brigand/functions/lambda/quote.hpp>
#include <brigand/sequences/list.hpp>

namespace brigand
{
namespace lazy
{

    template<typename Sequence, typename Predicate, typename NewType>
    using replace_if = typename detail::replace_if_impl<Sequence, Predicate, NewType>;

    template<typename Sequence, typename OldType, typename NewType>
    using replace = typename detail::replace_if_impl<Sequence,
        brigand::bind<brigand::quote<std::is_same>, OldType, brigand::_1>,
        NewType>;

}

template<typename Sequence, typename Predicate, typename NewType>
using replace_if = typename ::brigand::lazy::replace_if<Sequence, Predicate, NewType>::type;

template<typename Sequence, typename OldType, typename NewType>
using replace = typename ::brigand::lazy::replace<Sequence, OldType, NewType>::type;

}
