/*!
@file join.cpp
Example of using brigand::join

@copyright Edouard Alligand and Joel Falcou 2015-2017
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/

/// [join_simple_example]
#include <brigand/brigand.hpp>

using list1 = brigand::list<double, int, char>;
using list2 = brigand::list<long, unsigned char>;
using joined_list =
    brigand::join<brigand::list<list1, list2, brigand::list<brigand::list<unsigned long>>>>;

static_assert(std::is_same<joined_list, brigand::list<double, int, char, long, unsigned char,
                                                      brigand::list<unsigned long>>>::value,
              "failed to compile brigand::append example");
/// [join_simple_example]

/// [join_lazy_example]
using list3 = brigand::list<double, int, char>;
using list4 = brigand::list<long, unsigned char>;
using lazy_joined_list =
    brigand::lazy::join<brigand::list<list3, list4, brigand::list<brigand::list<unsigned long>>>>;

static_assert(std::is_same<typename lazy_joined_list::type,
                           brigand::list<double, int, char, long, unsigned char,
                                         brigand::list<unsigned long>>>::value,
              "failed to compile brigand::join example");
/// [join_lazy_example]
