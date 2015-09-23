
#include <boost/fusion/include/vector.hpp>
#include <boost/fusion/include/deque.hpp>
#include <boost/fusion/include/list.hpp>
#include <boost/fusion/include/set.hpp>

#include <brigand/sequences/list.hpp>
#include <brigand/adapted/fusion.hpp>

using test_list  = brigand::list<int, bool, char>;

static_assert ( std::is_same< boost::fusion::vector<int, bool, char>
                            , brigand::as_fusion_vector<test_list>
                            >::value
              , "error in brigand::as_fusion_vector"
              );

static_assert ( std::is_same< boost::fusion::list<int, bool, char>
                            , brigand::as_fusion_list<test_list>
                            >::value
              , "error in brigand::as_fusion_list"
              );

static_assert ( std::is_same< boost::fusion::deque<int, bool, char>
                            , brigand::as_fusion_deque<test_list>
                            >::value
              , "error in brigand::as_fusion_deque"
              );

static_assert ( std::is_same< boost::fusion::deque<int, bool, char>
                            , brigand::as_fusion_deque<test_list>
                            >::value
              , "error in brigand::as_fusion_set"
              );
