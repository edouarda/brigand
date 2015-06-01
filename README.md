quasardb mpl library
====================

Because we don't need everything Boost.MPL has and want faster compilation speed!

Based on Eric Niebler's Tiny Metaprogramming Library and Peter Dimov's Simple C++11 metaprogramming articles.

And now behold the most complete documentation ever written:

# Sequences

 * `qdb::mpl::list`

# Metafunctions

 * `qdb::mpl::size<Sequence> -> IntegralConstant`
 * `qdb::mpl::count<Sequence> -> IntegralConstant`
 * `qdb::mpl::at<Sequence> -> Element`
 * `qdb::mpl::at_c<Sequence> -> Element`
 * `qdb::mpl::front<Sequence> -> Element`
 * `qdb::mpl::push_front<Sequence> -> Sequence`
 * `qdb::mpl::pop_front<Sequence> -> Sequence`
 * `qdb::mpl::back<Sequence> -> Element`
 * `qdb::mpl::push_back<Sequence> -> Sequence`
 * `qdb::mpl::pop_back<Sequence> -> Sequence`
 * `qdb::mpl::plus<IntegralConstant, IntegralConstant> -> IntegralConstant`
 * `qdb::mpl::minus<IntegralConstant, IntegralConstant> -> IntegralConstant`
 * `qdb::mpl::not<IntegralConstant> -> IntegralConstant`

# Algorithms

 * `qdb::mpl::apply<Function, Function> -> Function`
 * `qdb::mpl::append<Sequence, Sequence> -> Sequence`

TODO :

 * `qdb::mpl::for_each<Sequence, Functor> -> Sequence`
 * `make_variant_over<Sequence> -> Boost.Variant`