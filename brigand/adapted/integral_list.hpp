/*==================================================================================================
Copyright (c) 2015 Edouard Alligand and Joel Falcou

Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/algorithms/transform.hpp>

namespace brigand
{

	template <typename T>
	struct make_integral : std::integral_constant < typename T::value_type, T::value > {};
	
	template <typename L>
	using as_integral_list = transform <L, make_integral<brigand::_1>> ;

}