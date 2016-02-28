/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/sequences/list.hpp>

namespace brigand
{
namespace detail
{
  template<class T, unsigned N, class List>
  struct filled_list_impl;

  template<class T, template<class...> class List, class... E>
  struct filled_list_impl<T, 0, List<E...>>
  {
    using type = List<E...>;
  };

  template<class T, template<class...> class List, class... E>
  struct filled_list_impl<T, 1, List<E...>>
  {
    using type = List<E..., T>;
  };

  template<class T, template<class...> class List, class... E>
  struct filled_list_impl<T, 2, List<E...>>
  {
    using type = List<E..., T, T>;
  };

  template<class T, template<class...> class List, class... E>
  struct filled_list_impl<T, 3, List<E...>>
  {
    using type = List<E..., T, T, T>;
  };

  template<class T, template<class...> class List, class... E>
  struct filled_list_impl<T, 4, List<E...>>
  {
    using type = List<E..., T, T, T, T>;
  };

  template<class T, template<class...> class List, class... E>
  struct filled_list_impl<T, 5, List<E...>>
  {
    using type = List<E..., T, T, T, T, T>;
  };

  template<class T, template<class...> class List, class... E>
  struct filled_list_impl<T, 6, List<E...>>
  {
    using type = List<E..., T, T, T, T, T, T>;
  };

  template<class T, template<class...> class List, class... E>
  struct filled_list_impl<T, 7, List<E...>>
  {
    using type = List<E..., T, T, T, T, T, T, T>;
  };

  template<class T, template<class...> class List, class... E>
  struct filled_list_impl<T, 8, List<E...>>
  {
    using type = List<E..., T, T, T, T, T, T, T, T>;
  };

  template<class T, template<class...> class List, class... E>
  struct filled_list_impl<T, 9, List<E...>>
  {
    using type = List<E..., T, T, T, T, T, T, T, T, T>;
  };

  template<class T, template<class...> class List, class... E>
  struct filled_list_impl<T, 10, List<E...>>
  {
    using type = List<E..., T, T, T, T, T, T, T, T, T, T>;
  };

  template<class T, template<class...> class List, class... E>
  struct filled_list_impl<T, 11, List<E...>>
  {
    using type = List<E..., T, T, T, T, T, T, T, T, T, T, T>;
  };

  template<class T, template<class...> class List, class... E>
  struct filled_list_impl<T, 12, List<E...>>
  {
    using type = List<E..., T, T, T, T, T, T, T, T, T, T, T, T>;
  };

  template<class T, template<class...> class List, class... E>
  struct filled_list_impl<T, 13, List<E...>>
  {
    using type = List<E..., T, T, T, T, T, T, T, T, T, T, T, T, T>;
  };

  template<class T, template<class...> class List, class... E>
  struct filled_list_impl<T, 14, List<E...>>
  {
    using type = List<E..., T, T, T, T, T, T, T, T, T, T, T, T, T, T>;
  };

  template<class T, template<class...> class List, class... E>
  struct filled_list_impl<T, 15, List<E...>>
  {
    using type = List<E..., T, T, T, T, T, T, T, T, T, T, T, T, T, T, T>;
  };

  template<class T, template<class...> class List, class... E>
  struct filled_list_impl<T, 16, List<E...>>
  {
    using type = List<E..., T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T>;
  };

  template<class T, unsigned N, template<class...> class List, class... E>
  struct filled_list_impl<T, N, List<E...>>
  {
    using type = typename filled_list_impl<T, N-16, List<E..., T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T>>::type;
  };
}

  template<class T, unsigned N, template<class...> class List = list>
  using filled_list = typename detail::filled_list_impl<T, N, List<>>::type;
}
