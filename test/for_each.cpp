
#include <brigand/algorithms/for_each.hpp>
#include <brigand/sequences/list.hpp>
#include <cassert>

struct value_printer
{
  value_printer() : i{0}, res{1} {}

  template< typename U > void operator()(brigand::type_<U>)
  {
    res *= sizeof(U);
    i++;
  }

  int i,res;
};

struct evil
{
  template< typename U > evil const& operator()(brigand::type_<U>) const {  return *this;  }

  evil& operator, (int) { return *this; } // evil operator comma
};

void for_each_test()
{
  // test regular cases
  auto r = brigand::for_each< brigand::list<char,short,int,double> >( value_printer{} );
  assert(r.res == 64);
  assert(r.i   ==  4);

  // test issues with comma operator
  brigand::for_each< brigand::list<char,void,int,double> >( evil{} );

  r = brigand::for_each< brigand::list<evil,evil,evil> >( value_printer{} );
  assert(r.res ==  1);
  assert(r.i   ==  3);
}
