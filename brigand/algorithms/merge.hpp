/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/functions/comparison/less.hpp>
#include <brigand/functions/lambda/apply.hpp>
#include <brigand/sequences/append.hpp>
#include <brigand/sequences/clear.hpp>
#include <type_traits>

namespace brigand
{
  namespace detail
  {
    template<class L, class Seq1, class Seq2, class Comp>
    struct merge_impl;

    template<bool, class L, class Seq1, class Seq2, class Comp>
    struct merge_insert;

    template<class... R, template<class...> class L1, class T0, class T1, class... Ts, template<class...> class L2, class U, class... Us, class Comp>
    struct merge_insert<true, L1<R...>, L1<T0,T1,Ts...>, L2<U,Us...>, Comp>
    : merge_insert<::brigand::apply<Comp,T1,U>::value, L1<R...,T0>, L1<T1,Ts...>, L2<U,Us...>, Comp>
    {};

    template<class... R, template<class...> class L1, class T, template<class...> class L2, class U, class... Us, class Comp>
    struct merge_insert<true, L1<R...>, L1<T>, L2<U,Us...>, Comp>
    {
      using list = L1<R...,T>;
      using left = L1<>;
      using right = L2<U,Us...>;
    };

    template<class... R, template<class...> class L1, class T, class... Ts, template<class...> class L2, class U0, class U1, class... Us, class Comp>
    struct merge_insert<false, L1<R...>, L1<T,Ts...>, L2<U0,U1,Us...>, Comp>
    : merge_insert<::brigand::apply<Comp,T,U1>::value, L1<R...,U0>, L1<T,Ts...>, L2<U1,Us...>, Comp>
    {};

    template<class... R, template<class...> class L1, class T, class... Ts, template<class...> class L2, class U, class Comp>
    struct merge_insert<false, L1<R...>, L1<T,Ts...>, L2<U>, Comp>
    {
      using list = L1<R...,U>;
      using left = L1<T,Ts...>;
      using right = L2<>;
    };

    template<
      class... R,
      template<class...> class L1, class T0, class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class... Ts,
      template<class...> class L2, class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class... Us, class Comp>
    struct merge_impl<L1<R...>, L1<T0,T1,T2,T3,T4,T5,T6,T7,T8,T9,Ts...>, L2<U0,U1,U2,U3,U4,U5,U6,U7,U8,U9,Us...>, Comp>
    {
      using sub = merge_insert<::brigand::apply<Comp,T0,U0>::value, L1<>, L1<T0,T1,T2,T3,T4,T5,T6,T7,T8,T9>, L1<U0,U1,U2,U3,U4,U5,U6,U7,U8,U9>, Comp>;
      using type = typename merge_impl<
        append<L1<R...>, typename sub::list>,
        append<typename sub::left, L1<Ts...>>,
        append<typename sub::right, L2<Us...>>,
        Comp
      >::type;
    };

    template<class... R, template<class...> class L1, class T, class... Ts, template<class...> class L2, class U, class... Us, class Comp>
    struct merge_impl<L1<R...>, L1<T,Ts...>, L2<U,Us...>, Comp>
    : std::conditional<
        ::brigand::apply<Comp,T,U>::value,
        merge_impl<L1<R...,T>, L1<Ts...>, L2<U,Us...>, Comp>,
        merge_impl<L1<R...,U>, L1<T,Ts...>, L2<Us...>, Comp>
    >::type
    {};

    template<class... R, template<class...> class L1, class... Ts, template<class...> class L2, class Comp>
    struct merge_impl<L1<R...>, L1<Ts...>, L2<>, Comp>
    {
      using type = L1<R..., Ts...>;
    };

    template<class... R, template<class...> class L1, template<class...> class L2, class... Us, class Comp>
    struct merge_impl<L1<R...>, L1<>, L2<Us...>, Comp>
    {
      using type = L1<R..., Us...>;
    };

    template<class... R, template<class...> class L1, template<class...> class L2, class Comp>
    struct merge_impl<L1<R...>, L1<>, L2<>, Comp>
    {
      using type = L1<R...>;
    };
  }

  template<class Seq1, class Seq2, class Comp = less<_1,_2>>
  using merge = typename detail::merge_impl<clear<Seq1>, Seq1, Seq2, Comp>::type;
}
