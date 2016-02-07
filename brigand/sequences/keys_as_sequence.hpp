#pragma once

#include <brigand/adapted/list.hpp>
#include <brigand/algorithms/transform.hpp>
#include <brigand/functions/lambda/quote.hpp>
#include <brigand/sequences/set.hpp>

namespace brigand
{
namespace detail
{
    template <typename Pair>
    using get_first = typename Pair::first_type;
} // namespace detail

template <typename Map, template <class...> class Sequence = brigand::set>
using keys_as_sequence = transform<as_sequence<Map, Sequence>, quote<detail::get_first>>;

} // namespace brigand
