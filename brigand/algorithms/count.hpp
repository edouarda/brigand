/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once
#include <type_traits>
#include <brigand/types/integer.hpp>
#include <brigand/functions/lambda.hpp>

namespace brigand
{
	namespace detail {
		constexpr std::size_t count_bools(bool const *const begin, bool const *const end,
			std::size_t n)
		{
			return begin == end ? n : detail::count_bools(begin + 1, end, n + *begin);
		}
	}
namespace lazy
{
    template <typename List, typename Pred>
    struct count_if
    {
    };

    template <template<typename...> class S, typename Pred>
    struct count_if<S<>, Pred>
    {
        using type = ::brigand::size_t<0>;
    };

	template <template<typename...> class S, typename... Ts, typename Pred>
	struct count_if<S<Ts...>, Pred>
	{
		static constexpr bool s_v[] = { ::brigand::apply<Pred, Ts>::type::value... };
		using type = brigand::size_t<::brigand::detail::count_bools(s_v, s_v + sizeof...(Ts), 0u)>;
	};

	template <template<typename...> class S, typename... Ts, template<typename...> class F>
	struct count_if<S<Ts...>, bind<F,_1>>
	{
		static constexpr bool s_v[] = { F<Ts>::value... };
		using type = brigand::size_t<::brigand::detail::count_bools(s_v, s_v + sizeof...(Ts), 0u)>;
	};

	template <template<typename...> class S, typename... Ts, template<typename...> class F>
	struct count_if<S<Ts...>, F<_1>>
	{
		static constexpr bool s_v[] = { F<Ts>::type::value... };
		using type = brigand::size_t<::brigand::detail::count_bools(s_v, s_v + sizeof...(Ts), 0u)>;
	};
}

template <typename List, typename Pred>
using count_if = typename lazy::count_if<List, Pred>::type;
template <class... T>
using count = std::integral_constant<std::size_t, sizeof...(T)>;
}
