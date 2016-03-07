/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/sequences/list.hpp>
#include <brigand/sequences/append.hpp>

namespace brigand
{
namespace detail
{
  template<
    class T, template<class...> class List,
    class L1, class L2, class L3, class L4, class L5, class L6,
    class L7, class L8, class L9, class L10, class L11, class L12,
    class L13, class L14, class L15, class L16, class L17, class L18,
    class L19, class L20, class L21, class L22, class L23, class L24
  >
  struct filled_list_cat;

  template<class T, class U>
  struct type_adapt
  {
    using type = U;
  };

  template<
    class T, template<class...> class List,
    class... Ts1, class... Ts2, class... Ts3, class... Ts4, class... Ts5,
    class... Ts6, class... Ts7, class... Ts8, class... Ts9, class... Ts10,
    class... Ts11, class... Ts12, class... Ts13, class... Ts14, class... Ts15,
    class... Ts16, class... Ts17, class... Ts18, class... Ts19, class... Ts20,
    class... Ts21, class... Ts22, class... Ts23, class... Ts24
  >
  struct filled_list_cat<
    T, List,
    list<Ts1...>, list<Ts2...>, list<Ts3...>, list<Ts4...>, list<Ts5...>,
    list<Ts6...>, list<Ts7...>, list<Ts8...>, list<Ts9...>, list<Ts10...>,
    list<Ts11...>, list<Ts12...>, list<Ts13...>, list<Ts14...>, list<Ts15...>,
    list<Ts16...>, list<Ts17...>, list<Ts18...>, list<Ts19...>, list<Ts20...>,
    list<Ts21...>, list<Ts22...>, list<Ts23...>, list<Ts24...>
  >
  {
    using type = List<
      typename type_adapt<Ts1,T>::type..., typename type_adapt<Ts2,T>::type...,
      typename type_adapt<Ts3,T>::type..., typename type_adapt<Ts4,T>::type...,
      typename type_adapt<Ts5,T>::type..., typename type_adapt<Ts6,T>::type...,
      typename type_adapt<Ts7,T>::type..., typename type_adapt<Ts8,T>::type...,
      typename type_adapt<Ts9,T>::type..., typename type_adapt<Ts10,T>::type...,
      typename type_adapt<Ts11,T>::type..., typename type_adapt<Ts12,T>::type...,
      typename type_adapt<Ts13,T>::type..., typename type_adapt<Ts14,T>::type...,
      typename type_adapt<Ts15,T>::type..., typename type_adapt<Ts16,T>::type...,
      typename type_adapt<Ts17,T>::type..., typename type_adapt<Ts18,T>::type...,
      typename type_adapt<Ts19,T>::type..., typename type_adapt<Ts20,T>::type...,
      typename type_adapt<Ts21,T>::type..., typename type_adapt<Ts22,T>::type...,
      typename type_adapt<Ts23,T>::type..., typename type_adapt<Ts24,T>::type...
    >;
  };

  template<
    template<class...> class List,
    class... Ts1, class... Ts2, class... Ts3, class... Ts4, class... Ts5,
    class... Ts6, class... Ts7, class... Ts8, class... Ts9, class... Ts10,
    class... Ts11, class... Ts12, class... Ts13, class... Ts14, class... Ts15,
    class... Ts16, class... Ts17, class... Ts18, class... Ts19, class... Ts20,
    class... Ts21, class... Ts22, class... Ts23, class... Ts24
  >
  struct filled_list_cat<
    int, List,
    list<Ts1...>, list<Ts2...>, list<Ts3...>, list<Ts4...>, list<Ts5...>,
    list<Ts6...>, list<Ts7...>, list<Ts8...>, list<Ts9...>, list<Ts10...>,
    list<Ts11...>, list<Ts12...>, list<Ts13...>, list<Ts14...>, list<Ts15...>,
    list<Ts16...>, list<Ts17...>, list<Ts18...>, list<Ts19...>, list<Ts20...>,
    list<Ts21...>, list<Ts22...>, list<Ts23...>, list<Ts24...>
  >
  {
    using type = List<
      Ts1..., Ts2..., Ts3..., Ts4..., Ts5..., Ts6...,
      Ts7..., Ts8..., Ts9..., Ts10..., Ts11..., Ts12...,
      Ts13..., Ts14..., Ts15..., Ts16..., Ts17..., Ts18...,
      Ts19..., Ts20..., Ts21..., Ts22..., Ts23..., Ts24...
    >;
  };

  template<unsigned N, class... E>
  struct filled_list_p2
  {
    using type = typename filled_list_p2<N/2, E..., E...>::type;
  };

  template<>
  struct filled_list_p2<0>
  {
    using type = list<>;
  };

  template<>
  struct filled_list_p2<1>
  {
    using type = list<int>;
  };

  template<>
  struct filled_list_p2<2>
  {
    using type = list<int, int>;
  };

  template<>
  struct filled_list_p2<4>
  {
    using type = list<int, int, int, int>;
  };

  template<>
  struct filled_list_p2<8>
  {
    using type = list<int, int, int, int, int, int, int, int>;
  };

  template<unsigned N>
  struct filled_list_p2<N>
  {
    using type = typename filled_list_p2<
      N/2, int, int, int, int, int, int, int, int
    >::type;
  };

  template<class... E>
  struct filled_list_p2<8, E...>
  {
    using type = list<E..., E...>;
  };
}

  template<class T, unsigned N, template<class...> class List = list>
  using filled_list = typename detail::filled_list_cat<
    T, List,
    typename detail::filled_list_p2<N & (1 << 0)>::type,
    typename detail::filled_list_p2<N & (1 << 1)>::type,
    typename detail::filled_list_p2<N & (1 << 2)>::type,
    typename detail::filled_list_p2<N & (1 << 3)>::type,
    typename detail::filled_list_p2<N & (1 << 4)>::type,
    typename detail::filled_list_p2<N & (1 << 5)>::type,
    typename detail::filled_list_p2<N & (1 << 6)>::type,
    typename detail::filled_list_p2<N & (1 << 7)>::type,
    typename detail::filled_list_p2<N & (1 << 8)>::type,
    typename detail::filled_list_p2<N & (1 << 9)>::type,
    typename detail::filled_list_p2<N & (1 << 10)>::type,
    typename detail::filled_list_p2<N & (1 << 11)>::type,
    typename detail::filled_list_p2<N & (1 << 12)>::type,
    typename detail::filled_list_p2<N & (1 << 13)>::type,
    typename detail::filled_list_p2<N & (1 << 14)>::type,
    typename detail::filled_list_p2<N & (1 << 15)>::type,
    typename detail::filled_list_p2<N & (1 << 16)>::type,
    typename detail::filled_list_p2<N & (1 << 17)>::type,
    typename detail::filled_list_p2<N & (1 << 18)>::type,
    typename detail::filled_list_p2<N & (1 << 19)>::type,
    typename detail::filled_list_p2<N & (1 << 20)>::type,
    typename detail::filled_list_p2<N & (1 << 21)>::type,
    typename detail::filled_list_p2<N & (1 << 22)>::type,
    typename detail::filled_list_p2<N & (1 << 23)>::type
  >::type;
}
