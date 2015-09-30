/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once
#include <brigand/sequences/append.hpp>
#include <brigand/sequences/clear.hpp>

#include <brigand/types/type.hpp>

namespace brigand
{
namespace detail
{
    template<int Index, class L1, class L2>
    struct erase_c_impl;

    template< int Index,
            template<class...> class L1, class First, class... T,
	    template<class...> class L2, class... U >
    struct erase_c_impl<Index, L1<First, T...>, L2<U...>>
    {
        using type = typename erase_c_impl<Index-1, L1<T...>, L2<U..., First>>::type;
    };

    template< template<class...> class L1, class First, class... T,
            template<class...> class L2, class... U >
    struct erase_c_impl<0, L1<First, T...>, L2<U...>>
    {
        using type = L2<U..., T...>;
    };
}

namespace detail
{

    template <class... U>
    struct exact_eraser;

    template <>
    struct exact_eraser<>
    {
        template <typename K>
        static exact_eraser<> erase(type_<K>);
    };

    template <class U0>
    struct exact_eraser<U0>
    {
        static exact_eraser<> erase(type_<U0>);

        template <typename K>
        static exact_eraser<U0> erase(type_<K>);
    };

    template <class U0, class... U>
    struct exact_eraser<U0, U...>
    {
        static exact_eraser<U...> erase(type_<U0>);

        template <typename K>
        using recursive_exact_erase = decltype(exact_eraser<U...>::erase(type_<K>{}));

        template <typename K>
        static append<exact_eraser<U0>, recursive_exact_erase<K>> erase(type_<K>);
    };

    // fastlanes
    template <class U0, class U1, class... U>
    struct exact_eraser<U0, U1, U...>
    {
        static exact_eraser<U1, U...> erase(type_<U0>);
        static exact_eraser<U0, U...> erase(type_<U1>);

        template <typename K>
        using recursive_exact_erase = decltype(exact_eraser<U...>::erase(type_<K>{}));

        template <typename K>
        static append<exact_eraser<U0, U1>, recursive_exact_erase<K>> erase(type_<K>);
    };

    template <class U0, class U1, class U2, class... U>
    struct exact_eraser<U0, U1, U2, U...>
    {
        static exact_eraser<U1, U2, U...> erase(type_<U0>);
        static exact_eraser<U0, U2, U...> erase(type_<U1>);
        static exact_eraser<U0, U1, U...> erase(type_<U2>);

        template <typename K>
        using recursive_exact_erase = decltype(exact_eraser<U...>::erase(type_<K>{}));

        template <typename K>
        static append<exact_eraser<U0, U1, U2>, recursive_exact_erase<K>> erase(type_<K>);
    };

    template <class U0, class U1, class U2, class U3, class... U>
    struct exact_eraser<U0, U1, U2, U3, U...>
    {
        static exact_eraser<U1, U2, U3, U...> erase(type_<U0>);
        static exact_eraser<U0, U2, U3, U...> erase(type_<U1>);
        static exact_eraser<U0, U1, U3, U...> erase(type_<U2>);
        static exact_eraser<U0, U1, U2, U...> erase(type_<U3>);

        template <typename K>
        using recursive_exact_erase = decltype(exact_eraser<U...>::erase(type_<K>{}));

        template <typename K>
        static append<exact_eraser<U0, U1, U2, U3>, recursive_exact_erase<K>> erase(type_<K>);
    };

    template <class U0, class U1, class U2, class U3, class U4, class... U>
    struct exact_eraser<U0, U1, U2, U3, U4, U...>
    {
        static exact_eraser<U1, U2, U3, U4, U...> erase(type_<U0>);
        static exact_eraser<U0, U2, U3, U4, U...> erase(type_<U1>);
        static exact_eraser<U0, U1, U3, U4, U...> erase(type_<U2>);
        static exact_eraser<U0, U1, U2, U4, U...> erase(type_<U3>);
        static exact_eraser<U0, U1, U2, U3, U...> erase(type_<U4>);

        template <typename K>
        using recursive_exact_erase = decltype(exact_eraser<U...>::erase(type_<K>{}));

        template <typename K>
        static append<exact_eraser<U0, U1, U2, U3, U4>, recursive_exact_erase<K>> erase(type_<K>);
    };

}

 template< class L, int Index >
  using erase_c = typename detail::erase_c_impl<Index, L, clear<L>>::type;

namespace detail
{
    template< class L, class Index >
    struct erase_impl
    {
        using type = erase_c<L, Index::value>;
    };

    template< class L1, template<class> class Pred, class L2 >
    struct erase_if_impl;

    template< class L1, template<class> class Pred, class L2, bool >
    struct erase_if_shortcut;

    template< template<class...> class L1, class T, class... Ts,
            template<class> class Pred,
            template<class...> class L2, class... Us >
    struct erase_if_shortcut<L1<T, Ts...>, Pred, L2<Us...>, true>
    {
        using type = L2<Us..., Ts...>;
    };

    template< template<class...> class L1, class T, class... Ts,
            template<class> class Pred,
            template<class...> class L2, class... Us >
    struct erase_if_shortcut<L1<T, Ts...>, Pred, L2<Us...>, false>
    : erase_if_impl<L1<Ts...>, Pred, L2<Us..., T>>
    {};

    template< template<class...> class L1, class T, class... Ts,
            template<class> class Pred, class L2 >
    struct erase_if_impl<L1<T, Ts...>, Pred, L2>
    : erase_if_shortcut<L1<T, Ts...>, Pred, L2, bool(Pred<T>::value)>
    {};

    template< template<class...> class L1,
            template<class> class Pred,
            class L2 >
    struct erase_if_impl<L1<>, Pred, L2>
    {
        using type = L2;
    };

    template <typename T>
    struct has_erase_method
    {
        struct dummy {};

        template <typename C, typename P>
        static auto test(P * p) -> decltype(C::erase(type_<P>{}), std::true_type());

        template <typename, typename>
        static std::false_type test(...);

        static const bool value = std::is_same<std::true_type, decltype(test<T, dummy>(nullptr))>::value;
    };


    template<class L, class I, bool>
    struct erase_dispatch
    {
        using type = typename erase_impl<L, I>::type;
    };

    template<class C, class K>
    struct erase_dispatch<C, K, true>
    {
        using type = decltype(C::erase(type_<K>{}));
    };
}

    template<class L, class K>
    using erase = typename detail::erase_dispatch<L, K, detail::has_erase_method<L>::value>::type;
}
