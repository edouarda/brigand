/*!
@file Example of using brigand::flatten

@copyright Edouard Alligand and Joel Falcou 2015-2017
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/

/// [flatten_simple_example]
#include <brigand/brigand.hpp>

using list1 = brigand::list<double, int, char>;
using list2 = brigand::list<long, unsigned char>;
using flat_list = brigand::flatten<
    brigand::list<list1, list2, short, brigand::list<brigand::list<unsigned long>>>>;

static_assert(
    std::is_same<flat_list,
                 brigand::list<double, int, char, long, unsigned char, short, unsigned long>>::value,
    "failed to compile brigand::flatten example");
/// [flatten_simple_example]
