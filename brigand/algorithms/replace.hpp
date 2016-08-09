/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/functions/lambda/apply.hpp>
#include <brigand/sequences/list.hpp>
#include <type_traits>

namespace brigand
{
//comment in when brigand compiler detection is working
//#ifdef BRIGAND_COMP_MSVC
	namespace detail
	{
		template <typename T, typename Pred, typename NewType>
		struct replacer : std::conditional<::brigand::apply<Pred, T>::value, NewType, T>
		{
		};
		template <typename T, template <typename...> class F, typename NewType>
		struct replacer<T, bind<F, _1>, NewType> : std::conditional<F<T>::value, NewType, T>
		{
		};
		template <typename T, template <typename...> class F, typename NewType>
		struct replacer<T, F<_1>, NewType> : std::conditional<F<T>::type::value, NewType, T>
		{
		};
	}
//#endif
namespace lazy
{

    template <typename Sequence, typename Predicate, typename NewType>
    struct replace_if;
//#ifdef BRIGAND_COMP_MSVC
	template <template <typename...> class S, typename... Ts, typename Predicate, typename NewType>
	struct replace_if<S<Ts...>, Predicate, NewType>
	{
		using type = S<typename detail::replacer<Ts, Predicate, NewType>::type...>;
	};
//#else
//    template <template <typename...> class S, typename... Ts, typename Predicate, typename NewType>
//    struct replace_if<S<Ts...>, Predicate, NewType>
//    {
//        using type =
//            S<typename std::conditional<apply<Predicate, Ts>::value, NewType, Ts>::type...>;
//    };
//    template <template <typename...> class S, typename... Ts, template <typename...> class F,
//              typename NewType>
//    struct replace_if<S<Ts...>, bind<F, _1>, NewType>
//    {
//        using type = S<typename std::conditional<F<Ts>::value, NewType, Ts>::type...>;
//    };
//    template <template <typename...> class S, typename... Ts, template <typename...> class F,
//              typename NewType>
//    struct replace_if<S<Ts...>, F<_1>, NewType>
//    {
//        using type = S<typename std::conditional<F<Ts>::type::value, NewType, Ts>::type...>;
//    };
//#endif

    template <typename Sequence, typename OldType, typename NewType>
    using replace = replace_if<Sequence, std::is_same<_1, pin<OldType>>, NewType>;
}

template <typename Sequence, typename Predicate, typename NewType>
using replace_if = typename ::brigand::lazy::replace_if<Sequence, Predicate, NewType>::type;

template <typename Sequence, typename OldType, typename NewType>
using replace = typename ::brigand::lazy::replace<Sequence, OldType, NewType>::type;
}
