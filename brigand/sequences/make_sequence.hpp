/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/functions/arithmetic/next.hpp>
#include <brigand/functions/lambda/apply.hpp>
#include <brigand/functions/lambda/quote.hpp>
#include <brigand/sequences/list.hpp>

namespace brigand
{
namespace detail
{
  template<class Start, unsigned N, class Next, class List>
  struct make_sequence_impl;

  template<class Start, class Next, template<class...> class List, class... E>
  struct make_sequence_impl<Start, 0, Next, List<E...>>
  {
    using type = List<E...>;
  };

  template<class Start, class Next, template<class...> class List, class... E>
  struct make_sequence_impl<Start, 1, Next, List<E...>>
  {
    using type = List<E..., Start>;
  };

  template<class Start, class Next, template<class...> class List, class... E>
  struct make_sequence_impl<Start, 2, Next, List<E...>>
  {
    using t1 = brigand::apply<Next, Start>;
    using type = List<E..., Start, t1>;
  };

  template<class Start, class Next, template<class...> class List, class... E>
  struct make_sequence_impl<Start, 3, Next, List<E...>>
  {
    using t1 = brigand::apply<Next, Start>;
    using t2 = brigand::apply<Next, t1>;
    using type = List<E..., Start, t1, t2>;
  };

  template<class Start, class Next, template<class...> class List, class... E>
  struct make_sequence_impl<Start, 4, Next, List<E...>>
  {
    using t1 = brigand::apply<Next, Start>;
    using t2 = brigand::apply<Next, t1>;
    using t3 = brigand::apply<Next, t2>;
    using type = List<E..., Start, t1, t2, t3>;
  };

  template<class Start, class Next, template<class...> class List, class... E>
  struct make_sequence_impl<Start, 5, Next, List<E...>>
  {
    using t1 = brigand::apply<Next, Start>;
    using t2 = brigand::apply<Next, t1>;
    using t3 = brigand::apply<Next, t2>;
    using t4 = brigand::apply<Next, t3>;
    using type = List<E..., Start, t1, t2, t3, t4>;
  };

  template<class Start, class Next, template<class...> class List, class... E>
  struct make_sequence_impl<Start, 6, Next, List<E...>>
  {
    using t1 = brigand::apply<Next, Start>;
    using t2 = brigand::apply<Next, t1>;
    using t3 = brigand::apply<Next, t2>;
    using t4 = brigand::apply<Next, t3>;
    using t5 = brigand::apply<Next, t4>;
    using type = List<E..., Start, t1, t2, t3, t4, t5>;
  };

  template<class Start, class Next, template<class...> class List, class... E>
  struct make_sequence_impl<Start, 7, Next, List<E...>>
  {
    using t1 = brigand::apply<Next, Start>;
    using t2 = brigand::apply<Next, t1>;
    using t3 = brigand::apply<Next, t2>;
    using t4 = brigand::apply<Next, t3>;
    using t5 = brigand::apply<Next, t4>;
    using t6 = brigand::apply<Next, t5>;
    using type = List<E..., Start, t1, t2, t3, t4, t5, t6>;
  };

  template<class Start, class Next, template<class...> class List, class... E>
  struct make_sequence_impl<Start, 8, Next, List<E...>>
  {
    using t1 = brigand::apply<Next, Start>;
    using t2 = brigand::apply<Next, t1>;
    using t3 = brigand::apply<Next, t2>;
    using t4 = brigand::apply<Next, t3>;
    using t5 = brigand::apply<Next, t4>;
    using t6 = brigand::apply<Next, t5>;
    using t7 = brigand::apply<Next, t6>;
    using type = List<E..., Start, t1, t2, t3, t4, t5, t6, t7>;
  };

  template<class Start, class Next, template<class...> class List, class... E>
  struct make_sequence_impl<Start, 9, Next, List<E...>>
  {
    using t1 = brigand::apply<Next, Start>;
    using t2 = brigand::apply<Next, t1>;
    using t3 = brigand::apply<Next, t2>;
    using t4 = brigand::apply<Next, t3>;
    using t5 = brigand::apply<Next, t4>;
    using t6 = brigand::apply<Next, t5>;
    using t7 = brigand::apply<Next, t6>;
    using t8 = brigand::apply<Next, t7>;
    using type = List<E..., Start, t1, t2, t3, t4, t5, t6, t7, t8>;
  };

  template<class Start, class Next, template<class...> class List, class... E>
  struct make_sequence_impl<Start, 10, Next, List<E...>>
  {
    using t1 = brigand::apply<Next, Start>;
    using t2 = brigand::apply<Next, t1>;
    using t3 = brigand::apply<Next, t2>;
    using t4 = brigand::apply<Next, t3>;
    using t5 = brigand::apply<Next, t4>;
    using t6 = brigand::apply<Next, t5>;
    using t7 = brigand::apply<Next, t6>;
    using t8 = brigand::apply<Next, t7>;
    using t9 = brigand::apply<Next, t8>;
    using type = List<E..., Start, t1, t2, t3, t4, t5, t6, t7, t8, t9>;
  };

  template<class Start, class Next, template<class...> class List, class... E>
  struct make_sequence_impl<Start, 11, Next, List<E...>>
  {
    using t1 = brigand::apply<Next, Start>;
    using t2 = brigand::apply<Next, t1>;
    using t3 = brigand::apply<Next, t2>;
    using t4 = brigand::apply<Next, t3>;
    using t5 = brigand::apply<Next, t4>;
    using t6 = brigand::apply<Next, t5>;
    using t7 = brigand::apply<Next, t6>;
    using t8 = brigand::apply<Next, t7>;
    using t9 = brigand::apply<Next, t8>;
    using t10 = brigand::apply<Next, t9>;
    using type = List<E..., Start, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10>;
  };

  template<class Start, class Next, template<class...> class List, class... E>
  struct make_sequence_impl<Start, 12, Next, List<E...>>
  {
    using t1 = brigand::apply<Next, Start>;
    using t2 = brigand::apply<Next, t1>;
    using t3 = brigand::apply<Next, t2>;
    using t4 = brigand::apply<Next, t3>;
    using t5 = brigand::apply<Next, t4>;
    using t6 = brigand::apply<Next, t5>;
    using t7 = brigand::apply<Next, t6>;
    using t8 = brigand::apply<Next, t7>;
    using t9 = brigand::apply<Next, t8>;
    using t10 = brigand::apply<Next, t9>;
    using t11 = brigand::apply<Next, t10>;
    using type = List<E..., Start, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11>;
  };

  template<class Start, class Next, template<class...> class List, class... E>
  struct make_sequence_impl<Start, 13, Next, List<E...>>
  {
    using t1 = brigand::apply<Next, Start>;
    using t2 = brigand::apply<Next, t1>;
    using t3 = brigand::apply<Next, t2>;
    using t4 = brigand::apply<Next, t3>;
    using t5 = brigand::apply<Next, t4>;
    using t6 = brigand::apply<Next, t5>;
    using t7 = brigand::apply<Next, t6>;
    using t8 = brigand::apply<Next, t7>;
    using t9 = brigand::apply<Next, t8>;
    using t10 = brigand::apply<Next, t9>;
    using t11 = brigand::apply<Next, t10>;
    using t12 = brigand::apply<Next, t11>;
    using type = List<E..., Start, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12>;
  };

  template<class Start, class Next, template<class...> class List, class... E>
  struct make_sequence_impl<Start, 14, Next, List<E...>>
  {
    using t1 = brigand::apply<Next, Start>;
    using t2 = brigand::apply<Next, t1>;
    using t3 = brigand::apply<Next, t2>;
    using t4 = brigand::apply<Next, t3>;
    using t5 = brigand::apply<Next, t4>;
    using t6 = brigand::apply<Next, t5>;
    using t7 = brigand::apply<Next, t6>;
    using t8 = brigand::apply<Next, t7>;
    using t9 = brigand::apply<Next, t8>;
    using t10 = brigand::apply<Next, t9>;
    using t11 = brigand::apply<Next, t10>;
    using t12 = brigand::apply<Next, t11>;
    using t13 = brigand::apply<Next, t12>;
    using type = List<E..., Start, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13>;
  };

  template<class Start, class Next, template<class...> class List, class... E>
  struct make_sequence_impl<Start, 15, Next, List<E...>>
  {
    using t1 = brigand::apply<Next, Start>;
    using t2 = brigand::apply<Next, t1>;
    using t3 = brigand::apply<Next, t2>;
    using t4 = brigand::apply<Next, t3>;
    using t5 = brigand::apply<Next, t4>;
    using t6 = brigand::apply<Next, t5>;
    using t7 = brigand::apply<Next, t6>;
    using t8 = brigand::apply<Next, t7>;
    using t9 = brigand::apply<Next, t8>;
    using t10 = brigand::apply<Next, t9>;
    using t11 = brigand::apply<Next, t10>;
    using t12 = brigand::apply<Next, t11>;
    using t13 = brigand::apply<Next, t12>;
    using t14 = brigand::apply<Next, t13>;
    using type = List<E..., Start, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14>;
  };

  template<class Start, class Next, template<class...> class List, class... E>
  struct make_sequence_impl<Start, 16, Next, List<E...>>
  {
    using t1 = brigand::apply<Next, Start>;
    using t2 = brigand::apply<Next, t1>;
    using t3 = brigand::apply<Next, t2>;
    using t4 = brigand::apply<Next, t3>;
    using t5 = brigand::apply<Next, t4>;
    using t6 = brigand::apply<Next, t5>;
    using t7 = brigand::apply<Next, t6>;
    using t8 = brigand::apply<Next, t7>;
    using t9 = brigand::apply<Next, t8>;
    using t10 = brigand::apply<Next, t9>;
    using t11 = brigand::apply<Next, t10>;
    using t12 = brigand::apply<Next, t11>;
    using t13 = brigand::apply<Next, t12>;
    using t14 = brigand::apply<Next, t13>;
    using t15 = brigand::apply<Next, t14>;
    using type = List<E..., Start, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15>;
  };

  template<class Start, unsigned N, class Next, template<class...> class List, class... E>
  struct make_sequence_impl<Start, N, Next, List<E...>>
  {
    using t1 = brigand::apply<Next, Start>;
    using t2 = brigand::apply<Next, t1>;
    using t3 = brigand::apply<Next, t2>;
    using t4 = brigand::apply<Next, t3>;
    using t5 = brigand::apply<Next, t4>;
    using t6 = brigand::apply<Next, t5>;
    using t7 = brigand::apply<Next, t6>;
    using t8 = brigand::apply<Next, t7>;
    using t9 = brigand::apply<Next, t8>;
    using t10 = brigand::apply<Next, t9>;
    using t11 = brigand::apply<Next, t10>;
    using t12 = brigand::apply<Next, t11>;
    using t13 = brigand::apply<Next, t12>;
    using t14 = brigand::apply<Next, t13>;
    using t15 = brigand::apply<Next, t14>;
    using t16 = brigand::apply<Next, t15>;
    using type = typename make_sequence_impl<t16, N-16, Next, List<E..., Start, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15>>::type;
  };
}

  template<class Start, unsigned N, class Next = quote<next>, template<class...> class List = list>
  using make_sequence = typename detail::make_sequence_impl<Start, N, Next, List<>>::type;
}
