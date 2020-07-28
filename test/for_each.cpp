
#include <brigand/algorithms/for_each.hpp>
#include <brigand/sequences/list.hpp>
#include <cassert>

struct value_printer
{
    value_printer() : i{0}, res{1} {}
    value_printer(const value_printer&) = delete;
    value_printer(value_printer&&) = default;
    value_printer& operator=(const value_printer&) = delete;
    value_printer& operator=(value_printer&&) = default;

    template <typename U>
    void operator()(brigand::type_<U>)
    {
        res *= sizeof(U);
        i++;
    }

    int i, res;
};

struct evil
{
    template <typename U>
    evil const & operator()(brigand::type_<U>) const
    {
        return *this;
    }

    evil & operator,(int) { return *this; } // evil operator comma
};

struct base10 {
    base10() = default;
    base10(const base10&) = delete;
    base10(base10&&) = default;
    base10& operator=(const base10&) = delete;
    base10& operator=(base10&&) = default;

    int result = 0;

    void operator()(int x) {
        result *= 10;
        result += x;
    }
};

template <class...>
class custom_list
{
};

void for_each_test()
{
    // test regular cases
    auto r = brigand::for_each<brigand::list<char, short, int, double>>(value_printer{});
    assert(r.res == 64);
    assert(r.i == 4);

    // test with custom list
    auto r2 = brigand::for_each<custom_list<char, short, int, double>>(value_printer{});
    assert(r2.res == 64);
    assert(r2.i == 4);

    // test issues with comma operator
    brigand::for_each<brigand::list<char, void, int, double>>(evil{});

    r = brigand::for_each<brigand::list<evil, evil, evil>>(value_printer{});
    assert(r.res == 1);
    assert(r.i == 3);

    // Test for_each_args separately
    auto base10_result = brigand::for_each_args(base10{}, 1, 2, 3, 4).result;
    assert(base10_result == 1234);
}
