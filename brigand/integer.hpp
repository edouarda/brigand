/*==================================================================================================
  Copyright (c) 2015 QuasarDB
  Copyright (c) 2015 NumScale

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once
#include <type_traits>
#include <cstddef>

namespace brigand
{
  template<char V>      using char_       = std::integral_constant<char     , V>;
  template<short V>     using short_      = std::integral_constant<short    , V>;
  template<int V>       using int_        = std::integral_constant<int      , V>;
  template<long V>      using long_       = std::integral_constant<long     , V>;
  template<long long V> using long_long_  = std::integral_constant<long long, V>;

  template<unsigned char V>      using uchar_       = std::integral_constant<unsigned char     , V>;
  template<unsigned short V>     using ushort_      = std::integral_constant<unsigned short    , V>;
  template<unsigned int V>       using uint_        = std::integral_constant<unsigned int      , V>;
  template<unsigned long V>      using ulong_       = std::integral_constant<unsigned long     , V>;
  template<unsigned long long V> using ulong_long_  = std::integral_constant<unsigned long long, V>;

  template<std::size_t V>     using size_t    = std::integral_constant<std::size_t, V>;
  template<std::ptrdiff_t V>  using ptrdiff_t = std::integral_constant<std::ptrdiff_t, V>;
}
