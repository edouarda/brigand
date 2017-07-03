![A brigand](https://raw.githubusercontent.com/wiki/edouarda/brigand/brigand_small.jpg)

# What is Brigand?

Brigand is a light-weight, fully functional, instant-compile time C++ 11
meta-programming library.

Meta-programming libraries are extremely useful to library authors as they
enable them to deliver more features with less code. They also find application
in projects where performance and productivity are important.

# What can you do with brigand?

Here are a couple of ideas:

 * Create a tuple from a list of types and then transform it into a variant
 * Look for the presence of a type in a tuple and get its index
 * Sort a list of types
 * Advanced static assertion with arithmetics and complex functions
 * Go through a list of types and perform a runtime action for each type
 * And much more

Long story short: everything you could do with Boost.MPL, you can do with
Brigand, except it requires less code and compiles much faster.

# Tutorials {#brigand_tutorials}

 * [Introduction](tutorials_introduction.html)
 * [Compile time algorithms](tutorials_what_is_algorithm.html)
 * [From compile time to runtime](tutorials_compile_to_runtime.html)

# Objectives {#brigand_objectives}

 * Simple, focused and powerful
 * Supports a wide range of compilers and platforms, including the two latest
   release of Visual Studio
 * Instant-compilation, no more excuse for getting an espresso!

# Compatibility {#brigand_compatibility}

Brigand **requires** a C++ 11 compiler.

Brigand is built and tested before each release against clang, gcc and Visual
Studio. We have tested that Brigand  currently supports:

 * clang 3.4 and upward
 * GCC 4.8 and upward
 * Partial Visual Studio 2013 Update 4 support
 * Visual Studio 2015 Update 3 and upward
 * Visual Studio 2017

# History {#brigand_history}

Brigand was born out of the need to replace the venerable, but aging,
[Boost.MPL](http://www.boost.org/doc/libs/1_58_0/libs/mpl/doc/) in
[quasardb](https://www.quasardb.net).

Because on all platforms we may not have a compiler capable of supporting
[Hana](https://github.com/ldionne/hana), and after reading Peter Dimov's
[Simple C++ 11 metaprogramming article](http://pdimov.com/cpp2/simple_cxx11_metaprogramming.html)
(as well as Eric Niebler's [Tiny Metaprogramming Library](http://ericniebler.com/2014/11/13/tiny-metaprogramming-library/))
I realized the amount of work to write a fully-functional MPL was manageable.

Joel told me that, at [Numscale](http://www.numscale.com/), they had exactly the
same problem. Brigand was born.

Quel canaillou ce brigand.

# Contributors {#brigand_contributors}

We'd like to thank the following contributors:

 * Odin Holmes
 * Marek Kurdej
 * Jonathan Poelen

# License

Brigand is copyright Edouard Alligand and Joel Falcou and distributed under the
[Boost Software License version 1.0](http://boost.org/LICENSE_1_0.txt).
