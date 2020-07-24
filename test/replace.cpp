#include <brigand/algorithms/replace.hpp>
#include <type_traits>

brigand::replace<brigand::list<>, int, float> replace_on_empty_list = brigand::list<>{};

brigand::replace<brigand::list<double, float>, int, float> replace_no_op =
brigand::list<double, float>{};

brigand::replace<brigand::list<int>, int, float> replace_test1 = brigand::list<float>{};

brigand::replace<brigand::list<double>, int, float> replace_test2 = brigand::list<double>{};

brigand::replace<brigand::list<int, float>, int, float> replace_test3 =
brigand::list<float, float>{};

brigand::replace<brigand::list<int, float, char, double, int, unsigned int>, int, float>
replace_test4 = brigand::list<float, float, char, double, float, unsigned int>{};

using pred_int = std::is_integral<brigand::_1>;

brigand::replace_if<brigand::list<int, float, char, double, int, unsigned int>, pred_int, float>
replace_test5 = brigand::list<float, float, float, double, float, float>{};

using pred_fp = std::is_floating_point<brigand::_1>;

brigand::replace_if<brigand::list<int, float, char, double, int, unsigned int>, pred_fp, long>
replace_test6 = brigand::list<int, long, char, long, int, unsigned int>{};

namespace custom
{
  template <class...>
  class custom_list
  {
  };

  brigand::replace<custom_list<>, int, float> replace_on_empty_list = custom_list<>{};

  brigand::replace<custom_list<double, float>, int, float> replace_no_op =
    custom_list<double, float>{};

  brigand::replace<custom_list<int>, int, float> replace_test1 = custom_list<float>{};

  brigand::replace<custom_list<double>, int, float> replace_test2 = custom_list<double>{};

  brigand::replace<custom_list<int, float>, int, float> replace_test3 = custom_list<float, float>{};

  brigand::replace<custom_list<int, float, char, double, int, unsigned int>, int, float>
    replace_test4 = custom_list<float, float, char, double, float, unsigned int>{};

  brigand::replace_if<custom_list<int, float, char, double, int, unsigned int>, pred_int, float>
    replace_test5 = custom_list<float, float, float, double, float, float>{};

  brigand::replace_if<custom_list<int, float, char, double, int, unsigned int>, pred_fp, long>
    replace_test6 = custom_list<int, long, char, long, int, unsigned int>{};
}

brigand::apply<brigand::lazy::replace<brigand::pin<brigand::list<int>>, int, float>>
replace_lazy_test1 = brigand::list<float>{};
