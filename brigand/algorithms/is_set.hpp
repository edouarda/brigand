/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/sequences/range.hpp>
#include <brigand/types/type.hpp>

namespace brigand
{
namespace detail
{
  template<class, class T> struct unique_x_t
#ifdef BRIGAND_COMP_MSVC_2013
  { operator T (); };
#elif defined(BRIGAND_COMP_GCC)
  : type_<T> // better with gcc, very bad with clang when the list contains many same elements
  {};
#else
  { operator type_<T> (); };
#endif

  template<class Ints, class... Ts>
  struct is_set_impl;

  template<>
  struct is_set_impl<list<>>
  {
    using type = std::true_type;
  };

  inline std::true_type true_fn(...);

  template<class... Ints, class... Ts>
  struct is_set_impl<list<Ints...>, Ts...>
  {
    struct Pack : unique_x_t<Ints, Ts>... {};

    template<class... Us>
    static auto is_set(Us...) -> decltype(true_fn(static_cast<Us>(Pack())...));
    static std::false_type is_set(...);

#ifdef BRIGAND_COMP_MSVC_2013
    using type = decltype(is_set(Ts()...));
#else
    using type = decltype(is_set(type_<Ts>()...));
#endif
  };

#ifdef BRIGAND_COMP_MSVC_2013
  template<class> struct qrref {};
  template<class> struct qref {};
  template<class> struct qnoref {};

  template<class T>
  struct msvc_quali_ref
  {
    using type = qnoref<T>;
  };

  template<class T>
  struct msvc_quali_ref<T&>
  {
    using type = qref<T>;
  };

  template<class T>
  struct msvc_quali_ref<T&&>
  {
    using type = qrref<T>;
  };
#endif
}

  template<class... Ts>
#ifdef BRIGAND_COMP_MSVC_2013
  using is_set = typename detail::is_set_impl<range<int, 0, sizeof...(Ts)>, detail::msvc_quali_ref<Ts>...>::type;
#else
  using is_set = typename detail::is_set_impl<range<int, 0, sizeof...(Ts)>, Ts...>::type;
#endif
}
