
#include <brigand/sequences/list.hpp>
#include <brigand/types/placeholders.hpp>
#include <brigand/algorithms/transform.hpp>
#include <brigand/functions/arithmetic/identity.hpp>
#include <brigand/functions/if.hpp>
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
using expect2c  = brigand::list<float*,double*,int*,char*,void*>;

// local functors to apply
using ptr_t  = std::add_pointer<brigand::_1>;
using pair_t = std::pair<brigand::_1,brigand::_2>;

static_assert ( std::is_same< brigand::transform<std::add_pointer<brigand::_1>,list0>
                            , list0
                            >::value
              , "invalid unary transform on empty list"
              );

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


static_assert ( std::is_same< brigand::transform<std::add_pointer<brigand::_1>,list1>
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

static_assert ( std::is_same< brigand::transform<pair_t,list2,list2>
                            , expect2b
                            >::value
              , "invalid binary transform on list"
              );

static_assert (std::is_same < brigand::transform < std::add_pointer<std::add_pointer<std::add_pointer<brigand::_1>>>,
			brigand::list<void, char, int>>,
			brigand::list<void ***, char ***, int ***>>::value
, "invalid transform on list"
);


static_assert ( std::is_same< brigand::transform< brigand::if_< std::is_pointer<brigand::_1>
                                                              , brigand::identity<brigand::_1>
                                                              , std::add_pointer < brigand::_1 >
                                                              >
                                                , list2
                                                >
                            , expect2c
                            >::value
              , "invalid binary transform on list"
              );
