# What is a compile time algorithm? {#tutorials_what_is_algorithm}

The standard library comes with runtime algorithms such `std::for_each`, 
`std::transform`, `std::find`... These algorithms operate on containers at
*runtime*.

Brigand comes out of the box with a complete suite of algorithm to operate on a
list of types at *compile time*. The Brigand algorithms enable you to apply
transformations or queries list of types and output a type.

# An introductory example

Imagine you'd like to make a static assertion if a list of types contain the
type `bool`. At *runtime* to look for an entry within, say, a `std::vector` you
would probably use `std::find`. With brigand, it's almost the same!

The main difference is that `brigand::find` works more like `std::find_if`. In
addition, `brigand::find` returns the collection pointing to the first matching
element (or an empty collection if no match is found). This might sound weird at
first, but you will see later it has a lot of advantages.

> In other words, algorithms in Brigand are range based, not iterator based.

Let's first look for bool inside `my_list`:

```cpp
#include <brigand/sequences/list.hpp>
#include <brigand/algorithms/find.hpp>
#include <type_traits>

using my_list = brigand::list<int, bool, char>;

// find_result will be 'bool, char'
using find_result = brigand::find<my_list, std::is_same<brigand::_1, bool>>;
```

Not unlike `std::find_if`, `brigand::find` requires a meta function to
perform the lookup. We wrote in that case a simple lambda that may remind you
`std::bind` in the way it works.

But what we want is to do a static assert if the type is present, how to do
that? We have the `brigand::found` helper function for that effect.

```cpp
#include <brigand/sequences/list.hpp>
#include <brigand/algorithms/find.hpp>
#include <type_traits>

using my_list = brigand::list<int, bool, char>;

// bool_found will be std::true_type
using bool_found = brigand::found<brigand::find<my_list, std::is_same<brigand::_1, bool>>>;
```

And you can now write the following static assertion:

```
static_assert(!bool_found::value, "A bool was found and I don't want bools!");
```

Note that the `brigand::not_found` helper function is also available.

# A different lambda

What if we don't want to look for a `bool` but for any floating type? We
just need a different lambda!

```cpp
#include <brigand/sequences/list.hpp>
#include <brigand/algorithms/find.hpp>
#include <type_traits>

using my_list = brigand::list<int, bool, char>;

// find_result will be empty because no float is in the list
using find_result = brigand::find<my_list, std::is_floating_point<brigand::_1>>;
```

There is no practical limit to what find takes as a parameter, it may be a very
complex meta function.

# Working on something other than a brigand list

In the introductory tutorial we told you that Brigand works on any variadic
type, not just brigand list. This means that you can directly look for types
in, let's say, a `std::tuple`:

```cpp
#include <brigand/algorithms/find.hpp>
#include <tuple>
#include <type_traits>

using my_tuple = std::tuple<bool, float, int>;

// find_result will be std::tuple<float, int>
using find_result = brigand::find<my_tuple , std::is_floating_point<brigand::_1>>;

// float_found will be std::true_type
using float_found = brigand::found<find_result>;
```

This prevents you from transforming types and directly apply algorithms on the
types you are working on.

# Transforming a list of types

We saw how to look for types within types, what about we transform a list of
types into another list of types?

Imagine we have a list of `char, bool, int` and we would like to have a list
of `char *, bool *, int *`. The `brigand::transform` algorithm is what
you are looking for!

```cpp
#include <brigand/sequences/list.hpp>
#include <brigand/algorithms/transform.hpp>
#include <type_traits>

using brigand::_1;
using vanilla_list = brigand::list<char, bool, int>;
// ptr list will be 'char *, bool *, int *'
using ptr_list = brigand::transform<vanilla_list, std::add_pointer<_1>>;
```

As you can see we made sure Brigand interfaces well with the existing C++ 11
type utilities but what about the C++ 14 `std::add_pointer_t`? First lets look
at some terminology: 
* `std::add_pointer<>` is a *lazy* metafunction because we have to look at its
member alias `type` in order to "call" the function and get its result, `using
a = std::add_pointer<char>` is different than 
`using b = std::add_pointer<char>::type`, a is an alias to the metafunction
including parameters (essentially a meta closure) and b is an alias to `char*`,
the result.  
* `std::add_pointer_t<>` is an *eager* metafunction because it is an alias to
the "return type" directly, in other words one cannot alias the metafunction
with parameters in the same way. 
In brigand most functions have an eager version which can be found in
`brigand::` and a lazy version which can be found in `brigand::lazy::`. 

In order for brigand to support eager metafunctions as lambdas we must use a
helper function to bind together an eager metafunction and a list of parameters
and placeholders. To do this we use `brigand::bind<>`, as its first parameter it
takes an eager metafunction and the rest of its parameters are a variadic pack
of fixed values and placeholders. 

The same example as above but using the eager `std::add_pointer_t` would look
like this:
```cpp
#include <brigand/sequences/list.hpp>
#include <brigand/algorithms/transform.hpp>
#include <type_traits>

using brigand::_1;
using vanilla_list = brigand::list<char, bool, int>;
// ptr list will be 'char *, bool *, int *'
using ptr_list = brigand::transform<vanilla_list, brigand::bind<std::add_pointer_t,_1>>;
```

There are many other algorithms in brigand, the [reference](reference) contains
the complete list. All algorithms work with the following logic:

 * Algorithms work on a list of types
 * Algorithms expect a lambda
 * Algorithms return a range, not an iterator

# Sorting a list of types

Sorting types might sound like a peculiar idea at first, but the day you will
need it, you will be glad it exists!

Like `std::sort`, `brigand::sort` will apply `brigand::less` on your
types collection. You can use it to order an integral list:

```cpp
#include <brigand/algorithms/sort.hpp>
#include <brigand/functions/comparison/less.hpp>

using my_list = brigand::integral_list<int, 3, 1, 4, 1, 5, 9, 2, 6, 5, 3>;

// sorted_list will be '1, 1, 2, 3, 3, 4, 5, 5, 6, 9' 
using sorted_list = brigand::sort<my_list>;
```

What if you want to store in reverse order? We have you covered.

```cpp
#include <brigand/algorithms/sort.hpp>
#include <brigand/functions/comparison/greater.hpp>
using brigand::_1;
using brigand::_2;

using my_list = std::integral_list<int, 3, 1, 4, 1, 5, 9, 2, 6, 5, 3>;

// sorted_list will be '9, 6, 5, 5, 4, 3, 3, 2, 1, 1' 
using sorted_list = brigand::sort<my_list, brigand::greater<_1,_2>>;
```
# A more beefy sort

What about sorting types by their ascending size? Sounds crazy? Perfect.

```cpp
#include <brigand/sequences/list.hpp>
#include <brigand/algorithms/sort.hpp>
#include <brigand/functions/misc/sizeof.hpp>
using brigand::_1;
using brigand::_2;

using type_list = brigand::list<double, short, char, int>;

// sorted_list will be 'char, short, int, double'
using sorted_list = brigand::sort<type_list,
    brigand::less<brigand::sizeof_<_1>, brigand::sizeof_<_2>>>;
```

# An even beefier sort

What about sorting types based on the value of a member?

```cpp
#include <brigand/sequences/list.hpp>
#include <brigand/algorithms/sort.hpp>
#include <type_traits>

using brigand::_1;
using brigand::_2;
struct type_one
{
	using id = std::integral_constant<int, 1>;
};

struct type_two
{
	using id = std::integral_constant<int, 2>;
};

struct type_three
{

	using id = std::integral_constant<int, 3>;
};

using my_list = brigand::list<type_three, type_one, type_two>;

template <typename Left, typename Right>
using compare_ids = brigand::bool_<(Left::id::value < Right::id::value)>;

using sorted_list = brigand::sort<my_list, brigand::bind<compare_ids, _1, _2>>;
```

You can notice that we've done something a bit different here. Because the
comparison meta function is non-trivial, we wrote a custom meta-function. Since
this particular metafunction is trivial enough we can implement it as a simple
templated alias, however since aliases are eager we must use `brigand::bind<>`
as explained above.

Brigand is a template metaprogramming library and as such it may make your
compiler sweat a lot in most complex cases. Writing custom meta-functions will
make your code easier for the programmer and the compiler!