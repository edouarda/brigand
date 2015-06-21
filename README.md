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

# Documentation

The documentation is available [here](https://github.com/edouarda/brigand/wiki/Brigand-documentation)
