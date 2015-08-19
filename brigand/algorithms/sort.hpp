#pragma once

#include <brigand/sequences/front.hpp>
#include <brigand/algorithms/partition.hpp>

namespace brigand
{
  namespace detail
  {
    // tail (FIXME: should be in brigand/sequences ?)
    template < typename Seq >
    struct tail_impl;

    template < template<class...> class Seq
             , typename Hd
             , typename... Tl
             >
    struct tail_impl<Seq<Hd, Tl...>> {
      using type = Seq<Tl...>;
    };

    template < template<class...> class Seq
             , typename Hd
             >
    struct tail_impl<Seq<Hd>> {
      using type = brigand::empty_list;
    };

    template <typename Seq>
    using tail = typename tail_impl<Seq>::type;

    // sort
    template < typename Seq
             , template<class, class> class Pred
             , typename... Ts
             >
    struct sort_impl;

    template < template<class...> class Seq
             , template<class, class> class Pred
             , typename T
             >
    struct sort_impl<Seq<T>, Pred> {
      using type = brigand::list<T>;
    };

    template < template<class, class> class Pred
             >
    struct sort_impl<brigand::empty_list, Pred> {
      using type = brigand::empty_list;
    };

    template < template<class...> class Seq
             , template<class, class> class Pred
             , typename... Ts
             >
    struct sort_impl<Seq<Ts...>, Pred> {
      using seq = Seq<Ts...>;
      using pivot  = brigand::front<seq>;
      using subseq = tail<seq>;

      template <typename T>
      struct lambda {
        enum {
          value = Pred<pivot, T>::value
        };
      };

      using p = brigand::partition<subseq, lambda>;

      using lhs = typename sort_impl<typename p::first_type,  Pred>::type;
      using rhs = typename sort_impl<typename p::second_type, Pred>::type;
      using type = brigand::append<lhs, brigand::list<pivot>, rhs>;
    };

  } // !namespace detail

  template < typename Seq
           , template<class, class> class Pred
           >
  using sort = typename detail::sort_impl<Seq, Pred>::type;

} // !namespace brigand
