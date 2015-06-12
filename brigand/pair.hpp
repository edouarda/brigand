
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