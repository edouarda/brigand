
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
}
}