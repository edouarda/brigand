/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/functions/lambda/lambda.hpp>
#include <brigand/sequences/list.hpp>

namespace brigand
{
	//greedy call
template <template <typename...> class F>
struct call
{
};
//lazy call
template <typename T>
struct lcall
{
};
//mark a parameter as a type (as in not a lambda)
template <typename T>
struct pin
{
};
namespace detail
{
    template <typename T, typename Args, typename... Ls>
	struct apply {
		using type = T;  //default is interpreted as if it were a pin<T>
	};

	//eager call case
	template <template<typename...> class Lambda, typename... Args, typename...Ls>
	struct apply<call<Lambda>, list<Args...>, Ls...>
	{
		using type = Lambda<Args...>;
	};

	//lazy call cases
	//lambda case
    template <template <typename...> class Lambda, typename... Ts, typename L, typename... Ls>
    struct apply<Lambda<Ts...>, L, Ls...> : Lambda<typename apply<Ts, L, Ls...>::type...>
    {
    };
    //pin case
	template <typename T, typename... Args, typename...Ls>
	struct apply<pin<T>, list<Args...>, Ls...>
	{
		using type = T;
	};
	//arg case
	template <std::size_t N, typename L, typename...Ls>
	struct apply<args<N>, L, Ls...>
	{
		using type = at_c<L, N>;
	};

}

template <typename Lambda, typename... Args>
using apply = typename detail::apply<Lambda, brigand::list<Args...>>::type;
}
