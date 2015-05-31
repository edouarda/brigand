
#pragma once

#include <type_traits>

namespace qdb
{
namespace mpl
{

    template <typename A, typename B>
    using minus = std::integral_constant<typename A::value_type, A::value - B::value>;


}
}