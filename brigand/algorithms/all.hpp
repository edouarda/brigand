/*==================================================================================================
Copyright (c) 2015 Edouard Alligand and Joel Falcou

Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/algorithms/detail/non_null.hpp>
#include <brigand/functions/lambda/apply.hpp>
#include <brigand/config.hpp>
#include <type_traits>
#include <initializer_list>

namespace brigand
{
#ifdef BRIGAND_COMP_MSVC_2013
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
	}
#else
	namespace detail
	{
		struct all_same
		{
			const bool value = false;
			constexpr all_same(...) {}
			template <typename T>
			constexpr all_same(std::initializer_list<T *>) : value{ true }
			{
			}
		};

		template <typename Sequence, typename Predicate>
		struct all_impl : bool_<true>{};

		template <template <class...> class Sequence, typename Predicate, typename T, typename... Ts>
		struct all_impl<Sequence<T,Ts...>, Predicate>
		{
			static constexpr all_same tester{ static_cast<::brigand::apply<Predicate, T> *>(nullptr),
				static_cast<::brigand::apply<Predicate, Ts> *>(nullptr)... };
			using type = bool_<(::brigand::apply<Predicate, T>::value != 0 && tester.value)>;
		};

		template <template <class...> class Sequence, template <typename...> class F, typename T,
			typename... Ts>
			struct all_impl<Sequence<T, Ts...>, bind<F, _1>>
		{
			static constexpr all_same tester{ static_cast<F<T> *>(nullptr),
				static_cast<F<Ts> *>(nullptr)... };
			using type = bool_<(F<T>::value != 0 && tester.value)>;
		};

		template <template <class...> class Sequence, template <typename...> class F, typename T,
			typename... Ts>
			struct all_impl<Sequence<T, Ts...>, F<_1>>
		{
			static constexpr all_same tester{ static_cast<typename F<T>::type *>(nullptr),
				static_cast<typename F<Ts>::type *>(nullptr)... };
			using type = bool_<(F<T>::type::value != 0 && tester.value)>;
		};
	}
#endif

	// Is a predicate true for every type ?
	template <typename Sequence, typename Predicate = detail::non_null>
	using all = typename detail::all_impl<Sequence, Predicate>::type;
}
