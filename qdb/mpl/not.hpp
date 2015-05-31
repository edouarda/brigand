
#pragma once

#include <type_traits>

namespace qdb
{
namespace mpl
{

    template <typename T>
    using not = std::integral_constant<typename T::value_type, !T::value>;

}
}