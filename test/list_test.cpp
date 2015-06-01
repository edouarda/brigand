
#include <qdb/mpl/list.hpp>
#include <qdb/mpl/size.hpp>
#include <qdb/mpl/append.hpp>
#include <qdb/mpl/back.hpp>
#include <qdb/mpl/front.hpp>
#include <qdb/mpl/at.hpp>

// list tests
using empty_list = qdb::mpl::list<>;

static_assert(qdb::mpl::size<empty_list>::value == 0, "invalid empty list size");

using single_int_list = qdb::mpl::list<int>;

static_assert(qdb::mpl::size<single_int_list>::value == 1, "invalid single list size");

static_assert(std::is_same<qdb::mpl::push_back<empty_list, int>, single_int_list>::value, "invalid push back int");
static_assert(std::is_same<qdb::mpl::push_front<empty_list, int>, single_int_list>::value, "invalid push back int");

using int_bool_list = qdb::mpl::list<int, bool>;

using single_bool_list = qdb::mpl::list<bool>;

static_assert(std::is_same<qdb::mpl::push_back<single_int_list, bool>, int_bool_list>::value, "invalid push back result");
static_assert(std::is_same<qdb::mpl::push_front<single_bool_list, int>, int_bool_list>::value, "invalid push front result");

using int_bool_bool_int_list = qdb::mpl::list<int, bool, bool, int>;

static_assert(std::is_same<qdb::mpl::front<int_bool_list>, int>::value, "invalid front result");
static_assert(std::is_same<qdb::mpl::back<int_bool_list>, bool>::value, "invalid front result");

static_assert(std::is_same<qdb::mpl::front<int_bool_bool_int_list>, int>::value, "invalid front result");
static_assert(std::is_same<qdb::mpl::back<int_bool_bool_int_list>, int>::value, "invalid front result");

static_assert(std::is_same<qdb::mpl::pop_front<int_bool_list>, qdb::mpl::list<bool>>::value, "invalid pop front result");
static_assert(std::is_same<qdb::mpl::pop_front<int_bool_bool_int_list>, qdb::mpl::list<bool, bool, int>>::value, "invalid pop front result");
static_assert(std::is_same<qdb::mpl::pop_front<single_int_list>, empty_list>::value, "invalid pop front result");

static_assert(std::is_same<qdb::mpl::pop_back<int_bool_list>, qdb::mpl::list<int>>::value, "invalid pop back result");
static_assert(std::is_same<qdb::mpl::pop_back<int_bool_bool_int_list>, qdb::mpl::list<int, bool, bool>>::value, "invalid pop back result");
static_assert(std::is_same<qdb::mpl::pop_back<single_int_list>, empty_list>::value, "invalid pop back result");

static_assert(std::is_same<qdb::mpl::at_c<int_bool_bool_int_list, 0>, int>::value,  "invalid at result");
static_assert(std::is_same<qdb::mpl::at_c<int_bool_bool_int_list, 1>, bool>::value, "invalid at result");
static_assert(std::is_same<qdb::mpl::at_c<int_bool_bool_int_list, 2>, bool>::value, "invalid at result");
static_assert(std::is_same<qdb::mpl::at_c<int_bool_bool_int_list, 3>, int>::value,  "invalid at result");

static_assert(std::is_same<qdb::mpl::at<int_bool_bool_int_list, std::integral_constant<int, 0>>, int>::value,  "invalid at result");
static_assert(std::is_same<qdb::mpl::at<int_bool_bool_int_list, std::integral_constant<int, 1>>, bool>::value, "invalid at result");
static_assert(std::is_same<qdb::mpl::at<int_bool_bool_int_list, std::integral_constant<int, 2>>, bool>::value, "invalid at result");
static_assert(std::is_same<qdb::mpl::at<int_bool_bool_int_list, std::integral_constant<int, 3>>, int>::value,  "invalid at result");

using bool_int_list = qdb::mpl::list<bool, int>;

static_assert(std::is_same<qdb::mpl::append<int_bool_list, bool_int_list>, int_bool_bool_int_list>::value, "invalid append result");
