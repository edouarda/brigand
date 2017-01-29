
#include <brigand/algorithms/split.hpp>
#include <type_traits>

static_assert(
    std::is_same<brigand::split<brigand::empty_sequence, void>, brigand::empty_sequence>::value,
    "invalid split on empty sequence");

using no_delim_seq = brigand::list<char, bool, int>;

static_assert(std::is_same<brigand::split<no_delim_seq, void>, brigand::list<no_delim_seq>>::value,
              "invalid split on sequence with no delim");

using one_delim = brigand::list<char, bool, int, void, char, char>;

static_assert(
    std::is_same<brigand::split<one_delim, void>,
                 brigand::list<brigand::list<char, bool, int>, brigand::list<char, char>>>::value,
    "invalid flatten on one level sequence");
namespace custom
{
template <class...>
class custom_list
{
};
static_assert(std::is_same<brigand::split<custom_list<>, void>, custom_list<>>::value,
              "invalid split on empty sequence");

using no_delim_seq = custom_list<char, bool, int>;

static_assert(std::is_same<brigand::split<no_delim_seq, void>, custom_list<no_delim_seq>>::value,
              "invalid split on sequence with no delim");

using one_delim = custom_list<char, bool, int, void, char, char>;

static_assert(
    std::is_same<brigand::split<one_delim, void>,
                 custom_list<custom_list<char, bool, int>, custom_list<char, char>>>::value,
    "invalid flatten on one level sequence");
}
