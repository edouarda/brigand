# Crossing the chasm {#tutorials_compile_to_runtime}

You often want the list of types you manipulate to produce effects at *runtime*.
Yes, writing static assertions is nice and useful, but what about doing
something at *runtime* which is based on a list of types generated at
*compile time*?

In this tutorial we will see how you can execute code at runtime based on a list
of types.

# Printing the list of types

The ```brigand::for_each``` algorithm takes a list of types and execute a
functor for each of them. The difference with other compile time algorithms is
that ```brigand::for_each``` takes a regular runtime functor.

Let's  see how we could print the list of types:

```cpp
#include <iostream>

#include <brigand/algorithms/for_each.hpp>
#include <brigand/sequences/list.hpp>

using my_list = brigand::list<char, int, bool>;

struct f
{
    template <typename T>
    void operator()(brigand::type_<T>)
    {
        std::cout << typeid(T).name() << std::endl;
    }
};

int main(int, char **)
{
    // will print the types at runtime
    brigand::for_each<my_list>(f{});

    return 0;
}
```

> As you can see, the lambda will receive a `brigand::type_<T>` type and not directly a `T` type. Without that indirection, it would not be possible to iterate on a list that contains the `void` type.

In C++ 14 you can even write:

```cpp
#include <iostream>

#include <brigand/algorithms/for_each.hpp>
#include <brigand/sequences/list.hpp>

using my_list = brigand::list<char, int, bool>;

int main(int, char **)
{
    // will print the types at runtime
    brigand::for_each<brigand::list<char, int, bool>>([](auto x)
    {
        std::cout << typeid(decltype(x)::type).name() << std::endl;
    });

    return 0;
}
```

# What does for_each return?

`brigand::for_each` returns the updated functor of the operation, not unlike
`std::for_each`. 

For example:

```cpp
#include <brigand/algorithms/for_each.hpp>
#include <brigand/sequences/list.hpp>

struct f
{
    template <typename U>
    void operator(brigand::type_<U>)
    {
        acc += sizeof(U);
        std::cout << typeid(T).name() << std::endl;
    }

    int acc{0};
};

int main(int, char **)
{
    // will print the types at runtime
    // r contains the updated f
    auto r = brigand::for_each<my_list>(f{});

    std::cout << r.acc << std::endl;

    return 0;
}
```
