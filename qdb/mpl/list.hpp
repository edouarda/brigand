
#pragma once

namespace qdb
{
namespace mpl
{

    template <class... T> struct list {};

    using empty_list = qdb::mpl::list<>;

}
}