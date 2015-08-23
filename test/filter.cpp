
#include <brigand/types/bool.hpp>
#include <brigand/types/integer.hpp>
#include <brigand/functions/plus.hpp>
#include <brigand/sequences/list.hpp>
#include <brigand/algorithms/filter.hpp>
#include <brigand/algorithms/fold.hpp>
#include <brigand/algorithms/reverse.hpp>
#include <boost/mpl/identity.hpp>
#include <limits>
#include <type_traits>
#include <cstddef>
#include <cstdint>

template<typename UpperBound>
struct generate_fibonacci_sequence;

template<typename T, T UpperBound>
struct generate_fibonacci_sequence<std::integral_constant<T, UpperBound> >
{
  template<T B, T A, T... Ns>
  struct apply
       : std::conditional< (A + B > B && A + B <= UpperBound)
                         , apply<A + B, B, A, Ns...>
                         , boost::mpl::identity<
                             brigand::reverse<
                               brigand::integral_list<T, B, A, Ns...>
                             >
                           >
                         >::type
    {};

    using type = typename apply<2, 1>::type;
};

template<typename T>
struct generate_fibonacci_sequence<std::integral_constant<T, 1> >
{
  using type = brigand::integral_list<T, 1>;
};

template<typename T>
struct generate_fibonacci_sequence<std::integral_constant<T, 0> >
{
  using type = brigand::empty_list;
};

template< typename T   = std::uintmax_t
        , T UpperBound = std::numeric_limits<T>::max()
        >
using fibonacci_sequence = typename generate_fibonacci_sequence<
  std::integral_constant<T, UpperBound>
>::type;

template<typename T>
using is_even = brigand::bool_<!(T::value & 1)>;

using project_euler_problem_2_answer =
  brigand::fold< brigand::plus
               , brigand::uint_<0>
               , brigand::filter< fibonacci_sequence<unsigned, 4000000U>
                                , is_even
                                >
               >;

static_assert( project_euler_problem_2_answer::value == 4613732U
             , "filter test invaild (calculating answer to project euler #2)"
             );
