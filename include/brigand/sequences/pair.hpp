/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

namespace brigand
{
    template <typename First, typename Second>
    struct pair
    {
        using first_type = First;
        using second_type = Second;
    };

}
