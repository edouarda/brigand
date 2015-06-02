Brigand Meta-programming library
================================

Because we don't need everything Boost.MPL has and want faster compilation speed!

Based on Eric Niebler's Tiny Metaprogramming Library and Peter Dimov's Simple C++11 metaprogramming articles.

And now behold the most complete documentation ever written:

# Sequences

 * `brigand::list`

# Types

 * `brigand::bool_`

# Metafunctions

 * `brigand::size<Sequence> -> IntegralConstant`
 * `brigand::count<Sequence> -> IntegralConstant`
 * `brigand::at<Sequence> -> Element`
 * `brigand::at_c<Sequence> -> Element`
 * `brigand::front<Sequence> -> Element`
 * `brigand::push_front<Sequence> -> Sequence`
 * `brigand::pop_front<Sequence> -> Sequence`
 * `brigand::back<Sequence> -> Element`
 * `brigand::push_back<Sequence> -> Sequence`
 * `brigand::pop_back<Sequence> -> Sequence`
 * `brigand::plus<IntegralConstant, IntegralConstant> -> IntegralConstant`
 * `brigand::minus<IntegralConstant, IntegralConstant> -> IntegralConstant`
 * `brigand::times<IntegralConstant, IntegralConstant> -> IntegralConstant`
 * `brigand::divides<IntegralConstant, IntegralConstant> -> IntegralConstant`
 * `brigand::modulo<IntegralConstant, IntegralConstant> -> IntegralConstant`
 * `brigand::complement<IntegralConstant> -> IntegralConstant`
 * `brigand::negate<IntegralConstant> -> IntegralConstant`
 * `brigand::not_<IntegralConstant> -> IntegralConstant`
 * `brigand::and_<IntegralConstant, IntegralConstant> -> IntegralConstant`
 * `brigand::or_<IntegralConstant, IntegralConstant> -> IntegralConstant`
 * `brigand::xor_<IntegralConstant, IntegralConstant> -> IntegralConstant`

# Algorithms

 * `brigand::apply<Function, Function> -> Function`
 * `brigand::append<Sequence, Sequence> -> Sequence`

TODO :

 * `brigand::for_each<Sequence, Functor> -> Sequence`
 * `brigand::sort<Sequence, Functor> -> Sequence`
 * `make_variant_over<Sequence> -> Boost.Variant`
