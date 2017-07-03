
# How to use {#tutorials_introduction}

Brigand is a header-only library.

To use it in your project you need but to specify the path to the Brigand
include directory, there is no linking step.

For convenience purposes we wrote a tool that assembles all the Brigand include
files into a single file. The Python script is available
[here](https://github.com/edouarda/brigand/blob/master/script/embed.py).

Brigand **requires** a C++ 11 compiler, the list of supported compilers is
available [here](index.html#brigand_compatibility).

# Let's get started

## How do I create a list of types?

A list of types has no runtime footprint and is your basic tool for most
metaprogramming tasks. We provide you with a sequence named `brigand::list`
that supports all basic operations you expect from a sequence.

Let's start simple, with an empty list:

\snippet tutorials/introduction.cpp create_empty_list

We predefined for you an empty list for clarity: `brigand::empty_sequence`.

We will now create a list of type that contains a bool, an integer and a pointer
to a string of characters.

\snippet tutorials/introduction.cpp create_nonempty_list

Thanks to the usage of variadic templates, Brigand has no practical limit to
the number of items in a list. There is also no restriction to the type that
may go in a list, as long as it's properly defined. Gentlemen: start your
compilers!

## Accessing elements in a list

You can access the front and back element with convenience functions:

\snippet tutorials/introduction.cpp get_front_and_back_list

Lists in Brigand also support efficient random access:

\snippet tutorials/introduction.cpp retrieve_from_typelist_at

## Adding and removing elements in a list of types

You may want to declare a list of types somewhere in your code, just to modify
it later on. It's possible to add entries to the end and the beginning of a
list.

We will add a char to the end of the list and another bool to the beginning.

```cpp
#include <brigand/sequences/list.hpp>
#include <brigand/sequences/back.hpp>
#include <brigand/sequences/front.hpp>

using my_list = brigand::list<bool, int, char *>;

// somwhere else

using my_list2 = brigand::push_back<my_list, char>;
using my_list3 = brigand::push_front<my_list2, bool>;
```

The resulting list will be `bool, bool, int, char *, char`.

It's important to understand that in template metaprogramming, types are never
updated in place. A meta function will return the result of your operation and
you may want to "save" that result in another type.

You could also write:

```cpp
using my_list2 = brigand::push_front<brigand::push_back<my_list, char>, bool>;
```

You may also remove elements at the beginning and the end of a list:

```cpp
#include <brigand/sequences/list.hpp>
#include <brigand/sequences/back.hpp>
#include <brigand/sequences/front.hpp>

using my_list = brigand::list<bool, int, char *>;

// my_list2 is int, char *
using my_list2 = brigand::pop_front<my_list>;

// my_list 3 is int
using my_list3 = brigand::pop_back<my_list2>;
```

All these meta functions support multiple parameters, you can therefore write:

```cpp
#include <brigand/sequences/list.hpp>
#include <brigand/sequences/back.hpp>
#include <brigand/sequences/front.hpp>

using my_list = brigand::list<bool, int, char *>;

// my_list2 is 'bool, int, char*, short, long'
using my_list2 = brigand::push_back<my_list, short, long>;

// my_list3 is 'bool, int, char *'
using my_list3 = brigand::pop_back<my_list2, std::integral_constant<int, 2>>;
```

## Merging two lists

If you have two lists, don't do complex manipulations! 

There is a meta function perfectly suited for the job:

```cpp
#include <brigand/sequences/list.hpp>
#include <brigand/sequences/append.hpp>

struct proton {};
struct neutron {};

using deuterium = brigand::list<proton, neutron>;
using tritium = brigand::list<proton, neutron, neutron>;

// omg will contain 'proton, neutron, proton, neutron, neutron'
using omg = brigand::append<deuterium, tritium>;
```

## Transforming a list of types

You may find list of types to have limited usage in themselves, we will see
later more advanced manipulations. However, you may right away transform your
list into a tuple.

```cpp
#include <brigand/sequences/list.hpp>
#include <brigand/adapted/tuple.hpp>
#include <string>

using my_list = brigand::list<bool, int, std::string>;
using my_tuple = brigand::as_tuple<my_list>;

// the type of t is std::tuple<bool, int, std::string>
my_tuple t;
```

Combined with the possibility to add (and remove) types from a list, this
enables you to create and validate the list of types that go in a tuple at
compile time.

Brigand also supports conversion to other types such as Boost.Variant:

```cpp
#include <brigand/sequences/list.hpp>
#include <brigand/adapted/variant.hpp>
#include <string>

using my_list = brigand::list<bool, int, std::string>;
using my_variant = brigand::as_variant<my_list>;

// the type of v is boost::variant<bool, int, std::string>
my_variant v;
```

# Everything we saw, works on any type

One of the greatest strength of Brigand is that it works on list of types. We
give you the `brigand::list` but anything which is a list of types will
work with our meta functions and algorithms...

...and this story shall also be told.
