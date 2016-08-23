/*==================================================================================================
Copyright (c) 2015 Edouard Alligand and Joel Falcou

Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/algorithms/detail/fold.hpp>

namespace brigand
{
namespace lazy
{
    template <class Sequence, class State, class Functor>
    using fold = typename detail::fold_impl<Functor, State, Sequence>;
    template <class Sequence, class State, class Functor>
    using reverse_fold = typename detail::reverse_fold_impl<Functor, State, Sequence>;
}

// Main fold entry point
template <class Sequence, class State, class Functor>
using fold = typename ::brigand::lazy::fold<Sequence, State, Functor>::type;
template <class Sequence, class State, class Functor>
using reverse_fold = typename ::brigand::lazy::reverse_fold<Sequence, State, Functor>::type;
}
