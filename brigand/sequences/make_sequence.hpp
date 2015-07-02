/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/sequences/list.hpp>
#include <brigand/functions/next.hpp>

namespace brigand
{
namespace detail
{
  template<class Start, unsigned N, template<class> class Next, class List, bool = (N > 8)>
  struct make_sequence_impl;

  template<class Start, template<class> class Next, template<class...> class List, class... E>
  struct make_sequence_impl<Start, 0, Next, List<E...>, false>
  {
    using type = List<E...>;
  };

  template<class Start, template<class> class Next, template<class...> class List, class... E>
  struct make_sequence_impl<Start, 1, Next, List<E...>, false>
  {
    using type = List<E..., Start>;
  };

  template<class Start, template<class> class Next, template<class...> class List, class... E>
  struct make_sequence_impl<Start, 2, Next, List<E...>, false>
  {
    using type = List<E..., Start, Next<Start>>;
  };

  template<class Start, template<class> class Next, template<class...> class List, class... E>
  struct make_sequence_impl<Start, 3, Next, List<E...>, false>
  {
    using t1 = Next<Start>;
    using type = List<E..., Start, t1, Next<t1>>;
  };

  template<class Start, template<class> class Next, template<class...> class List, class... E>
  struct make_sequence_impl<Start, 4, Next, List<E...>, false>
  {
    using t1 = Next<Start>;
    using t2 = Next<t1>;
    using type = List<E..., Start, t1, t2, Next<t2>>;
  };

  template<class Start, template<class> class Next, template<class...> class List, class... E>
  struct make_sequence_impl<Start, 5, Next, List<E...>, false>
  {
    using t1 = Next<Start>;
    using t2 = Next<t1>;
    using t3 = Next<t2>;
    using type = List<E..., Start, t1, t2, t3, Next<t3>>;
  };

  template<class Start, template<class> class Next, template<class...> class List, class... E>
  struct make_sequence_impl<Start, 6, Next, List<E...>, false>
  {
    using t1 = Next<Start>;
    using t2 = Next<t1>;
    using t3 = Next<t2>;
    using t4 = Next<t3>;
    using type = List<E..., Start, t1, t2, t3, t4, Next<t4>>;
  };

  template<class Start, template<class> class Next, template<class...> class List, class... E>
  struct make_sequence_impl<Start, 7, Next, List<E...>, false>
  {
    using t1 = Next<Start>;
    using t2 = Next<t1>;
    using t3 = Next<t2>;
    using t4 = Next<t3>;
    using t5 = Next<t4>;
    using type = List<E..., Start, t1, t2, t3, t4, t5, Next<t5>>;
  };

  template<class Start, template<class> class Next, template<class...> class List, class... E>
  struct make_sequence_impl<Start, 8, Next, List<E...>, false>
  {
    using t1 = Next<Start>;
    using t2 = Next<t1>;
    using t3 = Next<t2>;
    using t4 = Next<t3>;
    using t5 = Next<t4>;
    using t6 = Next<t5>;
    using type = List<E..., Start, t1, t2, t3, t4, t5, t6, Next<t6>>;
  };

  template<class Start, unsigned N, template<class> class Next, template<class...> class List, class... E>
  struct make_sequence_impl<Start, N, Next, List<E...>, true>
  {
    using t1 = Next<Start>;
    using t2 = Next<t1>;
    using t3 = Next<t2>;
    using t4 = Next<t3>;
    using t5 = Next<t4>;
    using t6 = Next<t5>;
    using t7 = Next<t6>;
    using type = typename make_sequence_impl<Next<t7>, N-8, Next, List<E..., Start, t1, t2, t3, t4, t5, t6, t7>>::type;
  };
}

  template<class Start, unsigned N, template<class> class Next = next, template<class...> class List = list>
  using make_sequence = typename detail::make_sequence_impl<Start, N, Next, List<>>::type;
}
