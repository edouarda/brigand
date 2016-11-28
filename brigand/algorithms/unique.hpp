/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/adapted/pair.hpp>
#include <brigand/algorithms/remove.hpp>
#include <brigand/algorithms/transform.hpp>
#include <brigand/sequences/back.hpp>
#include <brigand/sequences/front.hpp>
#include <brigand/sequences/keys_as_sequence.hpp>
#include <brigand/sequences/values_as_sequence.hpp>
#include <brigand/types/no_such_type.hpp>
#include <type_traits>

namespace brigand
{
  namespace detail
  {
    // Use no_such_type_ as a marker for an element beyond the end of the list
    template <class L>
    using unique_impl_shifted = push_back<pop_front<L>, no_such_type_>;

    template <class L>
    using unique_impl_shifted_pairs = ::brigand::transform<L,
      unique_impl_shifted<L>, pair_wrapper_<_1, _2>>;

    template <class L>
    using unique_impl_filtered_pairs = remove_if<unique_impl_shifted_pairs<L>,
      std::is_same<detail::get_first<_1>, detail::get_second<_1>>>;

    template <class L>
    struct unique_impl;

    template <template<class...> class L>
    struct unique_impl<L<>>
      : public type_<L<>>
    {};

    template <class L>
    struct unique_impl
      : public type_<::brigand::transform<unique_impl_filtered_pairs<L>,
        detail::get_first<_1>>>
    {};
  }

  namespace lazy
  {
      template <typename L>
      using unique = detail::unique_impl<L>;
  }

  // Implements analogue of std::unique
  template <typename L>
  using unique = typename lazy::unique<L>::type;
}
