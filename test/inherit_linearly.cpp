#include <brigand/sequences/list.hpp>
#include <brigand/types/args.hpp>
#include <brigand/types/inherit_linearly.hpp>
#include <type_traits>

template <typename F, typename T>
struct f : T
{
    F field;
};

template <class...>
class custom_list
{
};

using l1 = brigand::list<int, char const *, bool>;
using eb = brigand::empty_base;

static_assert(
    std::is_same<f<bool, f<char const *, f<int, eb>>>,
                 brigand::inherit_linearly<l1, f<brigand::_element, brigand::_state>>>::value,
    "invalid inherit_linearly");

using l2 = custom_list<int, char const *, bool>;
using eb2 = brigand::empty_base;

static_assert(
    std::is_same<f<bool, f<char const *, f<int, eb2>>>,
                 brigand::inherit_linearly<l2, f<brigand::_element, brigand::_state>>>::value,
    "invalid inherit_linearly");
