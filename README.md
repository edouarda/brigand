Brigand Meta-programming library
================================

[![Build Status](https://travis-ci.org/edouarda/brigand.svg?branch=master)](https://travis-ci.org/edouarda/brigand)

# Introduction

Brigand is a light-weight, fully fonctional, instant-compile time C++ 11 meta-programming library.

It provides a sequence called brigand::list (but will work with any MPL sequence) and a solid amount of meta-algorithms and meta-functions to work fully functional MPL programs.

This library is still a work in progress and we welcome your feedback.

# History

Brigand was born out of the need to replace the venerable, but aging, [Boost.MPL](http://www.boost.org/doc/libs/1_58_0/libs/mpl/doc/) in [quasardb](https://www.quasardb.net).

Because we may not have on all platforms a compiler capable of supporting [Hana](https://github.com/ldionne/hana), and after reading Peter Dimov's [Simple C++ 11 metaprogramming article](http://pdimov.com/cpp2/simple_cxx11_metaprogramming.html) (as well as Eric Niebler's [Tiny Metaprogramming Library](http://ericniebler.com/2014/11/13/tiny-metaprogramming-library/)) I realized the amount of work to write a fully-functionnal MPL was manageable.

Joel told me that, at [Numscale](http://www.numscale.com/), they had exactly the same problem than us and Brigand was born.

Quel canaillou ce brigand.

# Awesome documentation is awesome

## Sequences

 * `brigand::pair`
 * `brigand::list`
 * `brigand::integral_list`
 * `brigand::map`

## Types

 * `brigand::bool_`
 * `brigand::char_`
 * `brigand::short_`
 * `brigand::long_`
 * `brigand::long_long_`
 * `brigand::uchar_`
 * `brigand::ushort_`
 * `brigand::ulong_`
 * `brigand::ulong_long_`
 * `brigand::size_t`
 * `brigand::ptrdiff_t`

## Metafunctions

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

## Algorithms

 * `brigand::apply<Function, Function> -> Function`
 * `brigand::append<Sequence, Sequence> -> Sequence`
 * `brigand::for_each<Sequence, Functor> -> Sequence`
 * `brigand::transform<Functor, Sequence...> -> Sequence`
 * `brigand::find<Sequence, [Predicate]> -> Sequence`
 * `brigand::found<Sequence, [Predicate]> -> bool_`
 * `brigand::not_found<Sequence, [Predicate]> -> bool_`

## Adapters

 * `as_pair<Sequence> -> std.pair`
 * `as_tuple<Sequence> -> std.tuple`
 * `as_variant<Sequence> -> Boost.Variant`

TODO :

 * `brigand::sort<Sequence, Functor> -> Sequence`

