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
//select args from one layer higher in cascading lambdas
template <typename T>
struct parent
{
};
namespace detail
{
    template <typename T, typename... Ts>
    struct packaged_lcall		//this is used in ourder to propagate args from super lambdas to sub lambdas
    {
    };
    template <typename Void, typename T, typename Args, typename... Ls>
	struct apply {
		using type = T;  //default is interpreted as if it were a pin<T>
	};

	//eager call case
	template <template<typename...> class Lambda, typename... Args, typename...Ls>
	struct apply<void,call<Lambda>, list<Args...>, Ls...>
	{
		using type = Lambda<Args...>;
	};

	//lazy call cases
	//lambda case (more specialized but SFINAE)
	template <template <typename...> class Lambda, typename... Ts, typename...LTs, typename... Ls>
	struct apply<typename has_type<typename Lambda<typename apply<void, Ts, list<LTs...>, Ls...>::type...>::type>::type, Lambda<Ts...>, list<LTs...>, Ls...> : Lambda<typename apply<void, Ts, list<LTs...>, Ls...>::type...>
	{
	};
	//wrapper case (less specialized)
	template <template <typename...> class Lambda, typename... Ts, typename... Ls, typename V>
	struct apply<V, Lambda<Ts...>, Ls...>  
	{
		using type = Lambda<typename apply<void, Ts, Ls...>::type...>;
	};
    //pin case
	template <typename T, typename... Args, typename...Ls>
	struct apply<void,pin<T>, list<Args...>, Ls...>
	{
		using type = T;
	};
	//arg case
	template <std::size_t N, typename L, typename...Ls>
	struct apply<void, args<N>, L, Ls...>
	{
		using type = at_c<L, N>;
	};
	//arg fast track
	template <typename T, typename...Ts, typename...Ls>
	struct apply<void, args<0>, list<T,Ts...>, Ls...>
	{
		using type = T;
	};
	//parent case
	template <typename T, typename L, typename...Ls>
	struct apply<void,parent<T>, L, Ls...> : apply<void,T,Ls...>
	{
	};
	//lcall case
	template <typename Lambda, typename L, typename...Ls>
	struct apply<void,lcall<Lambda>, L, Ls...>
	{
		using type = packaged_lcall<Lambda, L, Ls...>;
	};
	//packaged_lcall case
	template <template <typename...> class Lambda, typename... Ts, typename... PLs, typename L, typename...Ls>
	struct apply<void,packaged_lcall<Lambda<Ts...>,PLs...>, L, Ls...> : Lambda<typename apply<void, Ts, L, Ls..., PLs...>::type...>
	{
	};


}

template <typename Lambda, typename... Args>
using apply = typename detail::apply<void, Lambda, brigand::list<Args...>>::type;
}
