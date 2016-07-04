/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/algorithms/fold.hpp>
#include <brigand/types/empty_base.hpp>

namespace brigand
{
  namespace lazy
  {
	  template< typename Types
		  , typename Node
		  , typename Root = brigand::empty_base
	  >
		  struct inherit_linearly;
	template< typename Types
		  , template<typename...> class Node, typename...Ts
		  , typename Root
	  >
	struct inherit_linearly<Types,Node<Ts...>,Root>
    {
      // TODO: change after lazy-fication
      using type = brigand::fold<Types,Root,bind<Node,Ts...>>;
    };
  }

  template< typename Types
            , typename Node
            , typename Root = brigand::empty_base
            >
  using inherit_linearly = typename lazy::inherit_linearly<Types,Node,Root>::type;
}
