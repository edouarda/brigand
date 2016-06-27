/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/functions/lambda/lambda.hpp>
#include <brigand/sequences/list.hpp>

namespace brigand
{
template <template <typename...> class F>
struct call
{
};

namespace detail
{
    template <typename Lambda, typename Args>
    struct apply;

    template <typename Lambda, template <class...> class List, typename... Args>
    struct apply<Lambda, List<Args...>>
    {
        using type = typename Lambda::template apply<Args...>::type;
    };
    template <template <class...> class F, template <class...> class List, typename... Args>
    struct apply<lambda<call<F>>, List<Args...>>
    {
        using type = F<Args...>;
    };
}

template <typename Lambda, typename... Args>
using apply = typename detail::apply<lambda<Lambda>, brigand::list<Args...>>::type;
}
