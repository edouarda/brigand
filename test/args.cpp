
#include <brigand/types/args.hpp>
#include <brigand/functions/lambda/apply.hpp>
#include <type_traits>

static_assert( std::is_same<float, brigand::apply<brigand::_1,float> >::value, "invalid args");
static_assert( std::is_same<float, brigand::apply<brigand::_1,float,void>>::value, "invalid args");
static_assert( std::is_same<void , brigand::apply<brigand::_2,float,void>>::value, "invalid args");
static_assert( std::is_same<float, brigand::apply<brigand::_1,float,void,int>>::value, "invalid args");
static_assert( std::is_same<void , brigand::apply<brigand::_2,float,void,int>>::value, "invalid args");
static_assert( std::is_same<int  , brigand::apply<brigand::_3,float,void,int>>::value, "invalid args");
static_assert( std::is_same<float, brigand::apply<brigand::_1,float,void,int,char>>::value, "invalid args");
static_assert( std::is_same<void , brigand::apply<brigand::_2,float,void,int,char>>::value, "invalid args");
static_assert( std::is_same<int  , brigand::apply<brigand::_3,float,void,int,char>>::value, "invalid args");
static_assert( std::is_same<char , brigand::apply<brigand::_4,float,void,int,char>>::value, "invalid args");
static_assert( std::is_same<int& , brigand::apply<brigand::_5,float,void,int,char,int&>>::value, "invalid args");
