#include <brigand/algorithms/select.hpp>
#include <brigand/types/bool.hpp>
#include <cassert>

struct M
{
  M() {}
  M(M&&) {}
  M& operator=(M&&) { return *this; }

  M(M const&) = delete;
  M& operator=(M const&) = delete;
};

struct C
{
  C() {}
  C(C const&) {}
  C& operator=(C const&) { return *this; }

  C(C&&) = delete;
  C& operator=(C&&) = delete;
};

void select_test()
{
  // test regular cases
  auto ri = brigand::select<brigand::true_>( 14, 3.6f);
  assert(ri == 14);

  auto rf = brigand::select<brigand::false_>( 14, 3.6f);
  assert(rf == 3.6f);

  // test with move-only types
  M x;
  x = brigand::select<brigand::true_>( M{}, x );

  // test with copy-only types
  C a;
  a = brigand::select<brigand::true_>( a, C{} );
}
