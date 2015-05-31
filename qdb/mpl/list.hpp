
#pragma once

namespace qdb
{
namespace mpl
{

    template <class... T> struct list {};

    using empty_list = qdb::mpl::list<>;

    // push_front
    template<class L, class... T> struct push_front_impl;

    template<template<class...> class L, class... U, class... T>
    struct push_front_impl<L<U...>, T...>
    {
        using type = L<T..., U...>;
    };

    template<class L, class... T>
    using push_front = typename push_front_impl<L, T...>::type;

    // push_back
    template<class L, class... T> struct push_back_impl;

    template<template<class...> class L, class... U, class... T>
    struct push_back_impl<L<U...>, T...>
    {
        using type = L<U..., T...>;
    };

    template<class L, class... T>
    using push_back = typename push_back_impl<L, T...>::type;

    // front
    template <class First, class...> 
    struct first_element
    {
        using type = First;
    };

    template<class L> struct front_impl;

    template<template<class...> class L, class... U>
    struct front_impl<L<U...>>
    {
        using type = typename first_element<U...>::type;
    };

    template <class L>
    using front = typename front_impl<L>::type;

    // back

    // mmm no other way than recursion to get the last? I think there must...
    template <class First, class... R> 
    struct last_element
    {
        using type = typename last_element<R...>::type;
    };

    template <class Last>
    struct last_element<Last>
    {
        using type = Last;
    };

    template<class L> struct back_impl;

    template<template<class...> class L, class... U>
    struct back_impl<L<U...>>
    {
        using type = typename last_element<U...>::type;
    };

    template <class L>
    using back = typename back_impl<L>::type;
}
}