#pragma once

#include <brigand/adapted/list.hpp>
#include <brigand/algorithms/transform.hpp>
#include <brigand/functions/lambda/quote.hpp>

namespace brigand
{
namespace detail
{
    template <typename Pair>
    using get_second = typename Pair::second_type;
} // namespace detail

template <typename Map, template <class...> class Sequence = brigand::list>
using values_as_sequence = transform<as_sequence<Map, Sequence>, quote<detail::get_second>>;

} // namespace brigand
