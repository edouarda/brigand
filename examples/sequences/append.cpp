/*!
@file append.cpp
Example of using brigand::append

@copyright Edouard Alligand and Joel Falcou 2015-2017
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/

/// [append_simple_example]
#include <brigand/brigand.hpp>

using list1 = brigand::list<double, int, char>;
using list2 = brigand::list<long, unsigned char>;
using appended_list = brigand::append<
    list1, list2, brigand::list<brigand::list<unsigned long>>>;

static_assert(std::is_same<appended_list, brigand::list<double, int, char, long, unsigned char,
                                                        brigand::list<unsigned long>>>::value,
              "failed to compile brigand::append example");
/// [append_simple_example]

/// [append_lazy_example]
using list3 = brigand::list<double, int, char>;
using list4 = brigand::list<long, unsigned char>;
using lazy_appended_list =
    brigand::lazy::append<list3, list4, brigand::list<brigand::list<unsigned long>>>;

static_assert(std::is_same<typename lazy_appended_list::type,
                           brigand::list<double, int, char, long, unsigned char,
                                         brigand::list<unsigned long>>>::value,
              "failed to compile brigand::append example");
/// [append_lazy_example]
