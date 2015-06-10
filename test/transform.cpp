
#include <brigand/list.hpp>
#include <brigand/transform.hpp>
#include <type_traits>
#include <utility>

using list0    = brigand::list<>;

using list1    = brigand::list<int>;
using expect1  = brigand::list<int*>;
using expect1b = brigand::list<std::pair<int,int>>;

using list2     = brigand::list<float,double,int,char,void*>;
using expect2   = brigand::list<float*,double*,int*,char*,void**>;
using expect2b  = brigand::list < std::pair<float,float>
                                , std::pair<double,double>
                                , std::pair<int,int>
                                , std::pair<char,char>
                                , std::pair<void*,void*>
                                >;

// local functors to apply
template<class T>         using ptr_t = T*;
template<class U,class V> using pair_t = std::pair<U,V>;

static_assert ( std::is_same< brigand::transform<ptr_t,list0>
                            , list0
                            >::value
              , "invalid unary transform on empty list"
              );

static_assert ( std::is_same< brigand::transform<pair_t,list0,list0>
                            , list0
                            >::value
              , "invalid binary transform on empty list"
              );

static_assert ( std::is_same< brigand::transform<ptr_t,list1>
                            , expect1
                            >::value
              , "invalid unary transform on list"
              );

static_assert ( std::is_same< brigand::transform<pair_t,list1,list1>
                            , expect1b
                            >::value
              , "invalid binary transform on list"
              );

static_assert ( std::is_same< brigand::transform<ptr_t,list2>
                            , expect2
                            >::value
              , "invalid unary transform on list"
              );

static_assert ( std::is_same< brigand::transform<pair_t,list2,list2>
                            , expect2b
                            >::value
              , "invalid binary transform on list"
              );
