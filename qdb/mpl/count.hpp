
#pragma once

#include <type_traits>

namespace qdb
{
namespace mpl
{

    template<class... T>
    using count = std::integral_constant<std::size_t, sizeof...(T)>;

}
}