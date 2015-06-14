
#include <brigand/algorithms/for_each.hpp>
#include <brigand/sequences/list.hpp>
#include <cassert>

struct value_printer
{
  value_printer() : i{0}, res{1} {}

  template< typename U > void operator()(U x)
  {
    res *= sizeof(x);
    i++;
  }

  int i,res;
};

void for_each_test()
{
  auto r = brigand::for_each< brigand::list<char,short,int,double> >( value_printer{} );
  assert(r.res == 64);
  assert(r.i   ==  4);
}
