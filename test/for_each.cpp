
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

struct evil
{
  template< typename U > evil const& operator()(U ) const {  return *this;  }

  evil& operator, (int) { return *this; } // evel operator coma
};

void for_each_test()
{
  // test regular cases
  auto r = brigand::for_each< brigand::list<char,short,int,double> >( value_printer{} );
  assert(r.res == 64);
  assert(r.i   ==  4);

  // test issues with comma operator
  brigand::for_each< brigand::list<char,short,int,double> >( evil{} );

  r = brigand::for_each< brigand::list<evil,evil,evil> >( value_printer{} );
  assert(r.res ==  1);
  assert(r.i   ==  3);
}
