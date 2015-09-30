#include <brigand/functions.hpp>
#include <type_traits>
#include <utility>

template<typename T0,typename T1>
struct f2
{
  using type = std::pair<T1,T0>;
};

template<typename T0,typename T1,typename T2,typename T3>
struct f4
{};

static_assert ( std::is_same < brigand::apply< brigand::quote<std::add_pointer>, int>
                            , int*
                            >::value
              , "Invalid quote result"
              );

static_assert ( std::is_same < brigand::apply< brigand::quote<f2>, int, void*>
                            , std::pair<void*,int>
                            >::value
              , "Invalid quote result"
              );

static_assert ( std::is_same < brigand::apply < brigand::quote<f4>
                                              , char, short, int, float
                                              >
                            , f4<char, short, int, float>
                            >::value
              , "Invalid quote result"
              );
