
#include <brigand/types/inherit.hpp>
#include <type_traits>

struct udt1 { int n; };
struct udt2 {};
struct udt3 { virtual void f() =0; };

using eb = brigand::empty_base;

static_assert( std::is_base_of<udt1, brigand::inherit<udt1,udt2>::type>::value, "invalid inherit");
static_assert( std::is_base_of<udt2, brigand::inherit<udt1,udt2>::type>::value, "invalid inherit");

static_assert( std::is_same<udt1, brigand::inherit<udt1,eb  >::type>::value, "invalid inherit");
static_assert( std::is_same<udt2, brigand::inherit<eb  ,udt2>::type>::value, "invalid inherit");
static_assert( std::is_same<  eb, brigand::inherit<eb  ,eb  >::type>::value, "invalid inherit");

static_assert( std::is_base_of<udt1, brigand::inherit<eb, udt1, eb ,udt2, eb, udt3>::type>::value, "invalid inherit");
static_assert( std::is_base_of<udt2, brigand::inherit<eb, udt1, eb ,udt2, eb, udt3>::type>::value, "invalid inherit");
static_assert( std::is_base_of<udt3, brigand::inherit<eb, udt1, eb ,udt2, eb, udt3>::type>::value, "invalid inherit");

static_assert( std::is_same<udt1, brigand::inherit<eb, udt1, eb>::type>::value, "invalid inherit");
static_assert( std::is_same<udt1, brigand::inherit<eb, udt1, eb, eb>::type>::value, "invalid inherit");
static_assert( std::is_base_of<udt1, brigand::inherit<eb, udt1, eb, eb,udt2>::type>::value, "invalid inherit");
static_assert( std::is_base_of<udt2, brigand::inherit<eb, udt1, eb, eb,udt2>::type>::value, "invalid inherit");
static_assert( std::is_same<  eb, brigand::inherit<eb,eb,eb,eb,eb,eb>::type>::value, "invalid inherit");
