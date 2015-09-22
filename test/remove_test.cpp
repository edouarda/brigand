#include <brigand/algorithms/remove.hpp>
#include <brigand/sequences/list.hpp>
#include <brigand/functions/not.hpp>
#include <brigand/types/integer.hpp>
#include <brigand/types/placeholders.hpp>

using remove_test_list = brigand::list<int, bool, int, char, float, double>;
using remove_test_int_list = brigand::integral_list<int,1,0,0,2>;

static_assert ( std::is_same< brigand::remove_element<remove_test_int_list, brigand::int_<2>>
                            , brigand::integral_list<int,1,0,0>
                            >::value
              , "invalid remove result"
              );

static_assert ( std::is_same< brigand::remove<remove_test_int_list, brigand::not_<brigand::_1>>
                            , brigand::list<brigand::int_<1>, brigand::int_<2>>
                            >::value
              , "invalid remove result"
              );

static_assert ( std::is_same< brigand::remove < remove_test_int_list
                                              , std::is_same<brigand::_1, brigand::int_<2>>
                                              >
                            , brigand::integral_list<int,1,0,0>
                            >::value
              , "invalid remove_if result"
              );

static_assert ( std::is_same< brigand::remove_element<remove_test_list, int>
                            , brigand::list<bool, char, float, double>
                            >::value
              , "invalid remove result"
              );

static_assert ( std::is_same<brigand::remove_element<remove_test_list, double>
                            , brigand::list<int, bool, int, char, float>
                            >::value
              , "invalid remove result"
              );

static_assert ( std::is_same< brigand::remove<remove_test_list, std::is_same<double, brigand::_1>>
                            , brigand::list<int, bool, int, char, float>
                            >::value
              , "invalid remove_if result"
              );

