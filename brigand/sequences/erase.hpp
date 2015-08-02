/*==================================================================================================
  Copyright (c) 2015 Edouard Alligan and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once
#include <brigand/sequences/clear.hpp>

namespace brigand
{
namespace detail
{
  template<int Index, class L1, class L2>
  struct erase_c_impl;

  template< int Index,
            template<class...> class L1, class First, class... T,
	    template<class...> class L2, class... U >
  struct erase_c_impl<Index, L1<First, T...>, L2<U...>>
  {
    using type = typename erase_c_impl<Index-1, L1<T...>, L2<U..., First>>::type;
  };

  template< template<class...> class L1, class First, class... T,
            template<class...> class L2, class... U >
  struct erase_c_impl<0, L1<First, T...>, L2<U...>>
  {
    using type = L2<U..., T...>;
  };
}

  template< class L, int Index >
  using erase_c = typename detail::erase_c_impl<Index, L, clear<L>>::type;

namespace detail
{
  template< class L, class Index >
  struct erase_impl
  {
    using type = erase_c<L, Index::value>;
  };

  template< class L1, template<class> class Pred, class L2 >
  struct erase_if_impl;

  template< class L1, template<class> class Pred, class L2, bool >
  struct erase_if_shortcut;

  template< template<class...> class L1, class T, class... Ts,
            template<class> class Pred,
            template<class...> class L2, class... Us >
  struct erase_if_shortcut<L1<T, Ts...>, Pred, L2<Us...>, true>
  {
    using type = L2<Us..., Ts...>;
  };

  template< template<class...> class L1, class T, class... Ts,
            template<class> class Pred,
            template<class...> class L2, class... Us >
  struct erase_if_shortcut<L1<T, Ts...>, Pred, L2<Us...>, false>
  : erase_if_impl<L1<Ts...>, Pred, L2<Us..., T>>
  {};

  template< template<class...> class L1, class T, class... Ts,
            template<class> class Pred, class L2 >
  struct erase_if_impl<L1<T, Ts...>, Pred, L2>
  : erase_if_shortcut<L1<T, Ts...>, Pred, L2, bool(Pred<T>::value)>
  {};

  template< template<class...> class L1,
            template<class> class Pred,
            class L2 >
  struct erase_if_impl<L1<>, Pred, L2>
  {
    using type = L2;
  };

  template<class T, class U>
  struct has_erase_method
  {
    template<class C, class P>
    static decltype(void(C::erase(type_<P>())), std::true_type()) test(P*);

    template<class, class>
    static std::false_type test(...);

    static const bool value = std::is_same<std::true_type, decltype(test<T, U>(nullptr))>::value;
  };

  template<class L, class I, bool = has_erase_method<L, I>::value>
  struct erase_dispatch
  {
    using type = typename erase_impl<L, I>::type;
  };

  template<class C, class K>
  struct erase_dispatch<C, K, true>
  {
    using type = decltype(C::erase(type_<K>{}));
  };
}

  template<class L, class K>
  using erase = typename detail::erase_dispatch<L, K>::type;
}
