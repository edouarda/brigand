#pragma once

#include <brigand/sequences/list.hpp>
#include <brigand/sequences/pair.hpp>
#include <brigand/sequences/append.hpp>

namespace brigand
{

  namespace detail
  {
    template < typename Seq
             , template<class> class Pred
             , typename... Ts
             >
    struct partition_impl;

    // for empty-list
    template < template<class> class Pred
             >
    struct partition_impl<brigand::empty_list, Pred> {
      using type = brigand::pair<brigand::empty_list, brigand::empty_list>;
    };

    // for non empty-list
    template < template<class...> class Seq
             , template<class> class Pred
             , typename... Ts
             >
    struct partition_impl<Seq<Ts...>, Pred> {

      private:
      template <typename T, bool Value = Pred<T>::value>
      struct state;

      template <typename...>
      struct partition_dispatch_impl;

      // fast-lane for 1: (2^1)
      // ---------------
      // 1 0
      template <typename T0>
      struct partition_dispatch_impl<state<T0, true>> {
        using first  = brigand::list<>;
        using second = brigand::list<T0>;
      };

      template <typename T0>
      struct partition_dispatch_impl<state<T0, false>> {
        using first  = brigand::list<T0>;
        using second = brigand::list<>;
      };

      // fast-lane for 2: (2^2)
      // ---------------
      // 11 01
      // 10 00
      template <typename T0, typename T1>
      struct partition_dispatch_impl<state<T0, true>, state<T1, true>> {
        using first  = brigand::list<>;
        using second = brigand::list<T0, T1>;
      };

      template <typename T0, typename T1>
      struct partition_dispatch_impl<state<T0, true>, state<T1, false>> {
        using first  = brigand::list<T1>;
        using second = brigand::list<T0>;
      };

      template <typename T0, typename T1>
      struct partition_dispatch_impl<state<T0, false>, state<T1, true>> {
        using first  = brigand::list<T0>;
        using second = brigand::list<T1>;
      };

      template <typename T0, typename T1>
      struct partition_dispatch_impl<state<T0, false>, state<T1, false>> {
        using first  = brigand::list<T1, T0>;
        using second = brigand::list<>;
      };

      // fast-lane for 3: (2^3)
      // ---------------
      // 111 000 101
      // 110 001 010
      // 100 011
      template <typename T0, typename T1, typename T2>
      struct partition_dispatch_impl<state<T0, true>, state<T1, true>, state<T2, true>> {
        using first  = brigand::list<>;
        using second = brigand::list<T0, T1, T2>;
      };

      template <typename T0, typename T1, typename T2>
      struct partition_dispatch_impl<state<T0, true>, state<T1, true>, state<T2, false>> {
        using first  = brigand::list<T2>;
        using second = brigand::list<T0, T1>;
      };

      template <typename T0, typename T1, typename T2>
      struct partition_dispatch_impl<state<T0, true>, state<T1, false>, state<T2, false>> {
        using first  = brigand::list<T1, T2>;
        using second = brigand::list<T0>;
      };

      template <typename T0, typename T1, typename T2>
      struct partition_dispatch_impl<state<T0, false>, state<T1, false>, state<T2, false>> {
        using first  = brigand::list<T0, T1, T2>;
        using second = brigand::list<>;
      };

      template <typename T0, typename T1, typename T2>
      struct partition_dispatch_impl<state<T0, false>, state<T1, false>, state<T2, true>> {
        using first  = brigand::list<T0, T1>;
        using second = brigand::list<T2>;
      };

      template <typename T0, typename T1, typename T2>
      struct partition_dispatch_impl<state<T0, false>, state<T1, true>, state<T2, true>> {
        using first  = brigand::list<T0>;
        using second = brigand::list<T1, T2>;
      };

      template <typename T0, typename T1, typename T2>
      struct partition_dispatch_impl<state<T0, true>, state<T1, false>, state<T2, true>> {
        using first  = brigand::list<T1>;
        using second = brigand::list<T0, T2>;
      };

      template <typename T0, typename T1, typename T2>
      struct partition_dispatch_impl<state<T0, false>, state<T1, true>, state<T2, false>> {
        using first  = brigand::list<T0, T2>;
        using second = brigand::list<T1>;
      };

      // TODO: add more fast-lanes

      template <typename T0, typename T1, typename T2, typename... R>
      struct partition_dispatch_impl<T0, T1, T2, R...> {
        using head = partition_dispatch_impl<T0, T1, T2>;
        using tail = partition_dispatch_impl<R...>;

        using first   = brigand::append<typename head::first,  typename tail::first>;
        using second  = brigand::append<typename head::second, typename tail::second>;
      };

      using states = partition_dispatch_impl<state<Ts>...>;

      public:
      using type = brigand::pair<typename states::first, typename states::second>;
    };

  } // !namespace detail

  template < typename Seq
           , template<class> class Pred
           >
  using partition = typename detail::partition_impl<Seq, Pred>::type;

} // !namespace brigand
