
#include <brigand/list.hpp>
#include <brigand/fold.hpp>
#include <brigand/integer.hpp>
#include <brigand/next.hpp>
#include <type_traits>
#include <utility>

using list0    = brigand::list<>;
using list1y   = brigand::list<float>;
using list1n   = brigand::list<int*>;
using list6    = brigand::list<int,float,double,long,char,float>;
using list12   = brigand::list<float,double,float,double,float,double,float,double,float,double,float,double>;

using zero_ = brigand::int_<0>;
using c88   = brigand::int_<88>;
using leet_ = brigand::int_<1337>;

// local functor to apply
template<class State,class Element>
using f_ = typename  std::conditional < std::is_floating_point<Element>::value
                                      , typename brigand::next<State>::type
                                      , State
                                      >::type;

static_assert(brigand::fold<f_,leet_,list0>::type::value  == 1337 , "invalid fold on empty list"    );
static_assert(brigand::fold<f_,zero_,list1y>::type::value == 1    , "invalid fold on 1 element list");
static_assert(brigand::fold<f_,zero_,list1n>::type::value == 0    , "invalid fold on 1 element list");
static_assert(brigand::fold<f_,zero_,list6>::type::value  == 3    , "invalid fold on list"          );
static_assert(brigand::fold<f_,c88,list12>::type::value   == 100  , "invalid fold with state"       );
