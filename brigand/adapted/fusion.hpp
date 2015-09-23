/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/algorithms/wrap.hpp>
#include <boost/fusion/container/vector/vector_fwd.hpp>
#include <boost/fusion/container/deque/deque_fwd.hpp>
#include <boost/fusion/container/list/list_fwd.hpp>
#include <boost/fusion/container/set/set_fwd.hpp>

namespace brigand
{
  template <typename... T>
  using fusion_vector_wrapper = boost::fusion::vector<T...>;

  template <typename... T>
  using fusion_list_wrapper = boost::fusion::list<T...>;

  template <typename... T>
  using fusion_deque_wrapper = boost::fusion::deque<T...>;

  template <typename... T>
  using fusion_set_wrapper = boost::fusion::set<T...>;

  template <typename L> using as_fusion_vector = wrap<L, fusion_vector_wrapper>;
  template <typename L> using as_fusion_deque  = wrap<L, fusion_deque_wrapper>;
  template <typename L> using as_fusion_list   = wrap<L, fusion_list_wrapper>;
  template <typename L> using as_fusion_set    = wrap<L, fusion_set_wrapper>;
}
