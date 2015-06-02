
#include <brigand/list.hpp>

namespace brigand
{
  // at
  template <int Index, class First, class... T>
  struct element_at
  {
    using type = typename element_at<Index - 1, T...>::type;
  };

  template <class First, class... T>
  struct element_at<0, First, T...>
  {
    using type = First;
  };

  template <int Index, class L> struct at_impl;

  template<int Index, template<class...> class L, class... U>
  struct at_impl<Index, L<U...>>
  {
    using type = typename element_at<Index, U...>::type;
  };

  template <class L, int Index>
  using at_c = typename at_impl<Index, L>::type;

  template <class L, typename Index>
  using at = at_c<L, Index::value>;
}
