
#include <brigand/brigand.hpp>

namespace {
/// [create_empty_list]
#include <brigand/sequences/list.hpp>
using empty_list = brigand::list<>;
/// [create_empty_list]
} // namespace

namespace {
/// [create_nonempty_list]
#include <brigand/sequences/list.hpp>

using my_list = brigand::list<bool, int, char *>;
/// [create_nonempty_list]
}

namespace {
/// [get_front_and_back_list]
#include <brigand/sequences/list.hpp>
#include <brigand/sequences/back.hpp>
#include <brigand/sequences/front.hpp>

using my_list = brigand::list<bool, int, char *>;

// head is 'bool'
using head = brigand::front<my_list>;

// last is 'char *'
using last = brigand::back<my_list>;
/// [get_front_and_back_list]
} // namespace

namespace {
/// [retrieve_from_typelist_at]
#include <brigand/sequences/list.hpp>
#include <brigand/sequences/at.hpp>
#include <brigand/types/integer.hpp>

using my_list = brigand::list<bool, int, char *>;

// element 1 is 'int'
using e1 = brigand::at<my_list, brigand::int32_t<1>>;

// you might want to use the convenience function at_c
using e1bis = brigand::at_c<my_list, 1>;
/// [retrieve_from_typelist_at]
} // namespace
