/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/algorithms/detail/non_null.hpp>
#include <brigand/functions/lambda/apply.hpp>
#include <type_traits>

namespace brigand
{
  namespace detail
  {
    template <bool...> struct bools_ {};
    template< typename Sequence, typename Predicate, typename... Ts> struct all_impl;

	template< template<class...> class Sequence, typename Predicate, typename... Ts>
	struct  all_impl<Sequence<Ts...>, Predicate>
		: std::is_same< bools_<true, ::brigand::apply<Predicate, Ts>::value...>
		, bools_<::brigand::apply<Predicate, Ts>::value..., true>
		>
	{};

	template< template<class...> class Sequence, template<typename...> class F, typename... Ts>
	struct  all_impl<Sequence<Ts...>, bind<F,_1>>
		: std::is_same< bools_<true, F<Ts>::value...>
		, bools_<F<Ts>::value..., true>
		>
	{};

	template< template<class...> class Sequence, template<typename...> class F, typename... Ts>
	struct  all_impl<Sequence<Ts...>, F<_1>>
		: std::is_same< bools_<true, F<Ts>::type::value...>
		, bools_<F<Ts>::type::value..., true>
		>
	{};
  }

  // Is a predicate true for every type ?
  template<typename Sequence, typename Predicate = detail::non_null>
  using all = typename detail::all_impl<Sequence,Predicate>::type;
}
