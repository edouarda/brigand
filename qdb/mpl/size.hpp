
#pragma once

#include <qdb/mpl/apply.hpp>
#include <qdb/mpl/count.hpp>

namespace qdb
{
namespace mpl
{

    template<class L> 
    using size = apply<L, count>;

}
}