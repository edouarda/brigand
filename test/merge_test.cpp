#include <brigand/algorithms/merge.hpp>
#include <brigand/algorithms/wrap.hpp>
#include <brigand/sequences/list.hpp>
#include <brigand/sequences/range.hpp>

template <int n>
using i = brigand::integral_constant<int, n>;
template <class...>
struct custom_list
{
};

void test_merge()
{

    using brigand::merge;
    using brigand::range;
    using brigand::list;
    using brigand::wrap;

    using l1 = range<int, 0, 12>;
    using l2 = range<int, 8, 20>;

    merge<l1, l1>{} =
        list<i<0>, i<0>, i<1>, i<1>, i<2>, i<2>, i<3>, i<3>, i<4>, i<4>, i<5>, i<5>, i<6>, i<6>,
             i<7>, i<7>, i<8>, i<8>, i<9>, i<9>, i<10>, i<10>, i<11>, i<11>>{};
    merge<l1, l2>{} =
        list<i<0>, i<1>, i<2>, i<3>, i<4>, i<5>, i<6>, i<7>, i<8>, i<8>, i<9>, i<9>, i<10>, i<10>,
             i<11>, i<11>, i<12>, i<13>, i<14>, i<15>, i<16>, i<17>, i<18>, i<19>>{};

    using custom_l1 = wrap<l1, custom_list>;
    merge<custom_l1, custom_l1>{} = wrap<merge<l1, l1>, custom_list>{};
}
