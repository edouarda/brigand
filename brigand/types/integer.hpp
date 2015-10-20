/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once
#include <type_traits>
#include <cstdint>
#include <cstddef>

namespace brigand
{
  template <std::int8_t V>
  using int8_t = std::integral_constant<std::int8_t, V>;

  template <std::uint8_t V>
  using uint8_t = std::integral_constant<std::uint8_t, V>;

  template <std::int16_t V>
  using int16_t = std::integral_constant<std::int16_t, V>;

  template <std::uint16_t V>
  using uint16_t = std::integral_constant<std::uint16_t, V>;

  template <std::int32_t V>
  using int32_t = std::integral_constant<std::int32_t, V>;

  template <std::uint32_t V>
  using uint32_t = std::integral_constant<std::uint32_t, V>;

  template <std::int64_t V>
  using int64_t = std::integral_constant<std::int64_t, V>;

  template <std::uint64_t V>
  using uint64_t = std::integral_constant<std::uint64_t, V>;

  template<std::size_t V>
  using size_t    = std::integral_constant<std::size_t, V>;

  template<std::ptrdiff_t V>
  using ptrdiff_t = std::integral_constant<std::ptrdiff_t, V>;
}
