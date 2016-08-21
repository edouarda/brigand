/*==================================================================================================
Copyright (c) 2015 Edouard Alligand and Joel Falcou

Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/algorithms/wrap.hpp>
#include <brigand/algorithms/split_at.hpp>
#include <brigand/algorithms/merge.hpp>
#include <brigand/functions/comparison/less.hpp>
#include <brigand/functions/lambda/apply.hpp>
#include <brigand/sequences/append.hpp>
#include <brigand/sequences/front.hpp>
#include <brigand/sequences/size.hpp>

namespace brigand
{
namespace detail
{
    template <class P, typename Out, typename In, bool Tag, bool FTag, typename... Ts>
    struct insert;

    // next is not less than insert, no more ins, terminate
    template <class P, typename... Os, typename In, typename... Ts>
    struct insert<P, list<Os...>, list<In>, false, false, Ts...>
    {
        using type = list<Os..., In, Ts...>;
    };

    // next is less than insert, next is end, terminate
    template <class P, typename... Os, typename... Ins, typename T>
    struct insert<P, list<Os...>, list<Ins...>, true, false, T>
    {
        using type = list<Os..., T, Ins...>;
    };

    // next is not less than insert, have more next and have more ins, can't fast track
    template <class P, typename... Os, typename In1, typename In2, typename... Ins, typename T,
              typename... Ts>
    struct insert<P, list<Os...>, list<In1, In2, Ins...>, false, false, T, Ts...>
        : insert<P, list<Os..., In1>, list<In2, Ins...>, brigand::apply<P, T, In2>::value, false, T, Ts...>
    {
    };
    // next is not less than insert, have more next and have more ins, can fast track
    template <class P, typename... Os, typename In1, typename In2, typename... Ins, typename T1,
              typename T2, typename T3, typename T4, typename T5, typename T6, typename T7,
              typename T8, typename... Ts>
    struct insert<P, list<Os...>, list<In1, In2, Ins...>, false, false, T1, T2, T3, T4, T5, T6, T7,
                  T8, Ts...>
        : insert<P, list<Os..., In1>, list<In2, Ins...>, brigand::apply<P, T1, In2>::value,
                 brigand::apply<P, T8, In2>::value, T1, T2, T3, T4, T5, T6, T7, T8, Ts...>
    {
    };
    // next is less than insert, next is not end
    template <class P, typename... Os, typename In, typename... Ins, typename T1, typename T2,
              typename... Ts>
    struct insert<P, list<Os...>, list<In, Ins...>, true, false, T1, T2, Ts...>
        : insert<P, list<Os..., T1>, list<In, Ins...>, brigand::apply<P, T2, In>::value, false, T2, Ts...>
    {
    };
    // fast track is less than insert, no more
    template <class P, typename... Os, typename In, typename... Ins, typename T1, typename T2,
              typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
    struct insert<P, list<Os...>, list<In, Ins...>, true, true, T1, T2, T3, T4, T5, T6, T7, T8>
    {
        using type = list<Os..., T1, T2, T3, T4, T5, T6, T7, T8, In, Ins...>;
    };

    // fast track is less than insert, not enough to fast track again
    template <class P, typename... Os, typename In, typename... Ins, typename T1, typename T2,
              typename T3, typename T4, typename T5, typename T6, typename T7, typename T8,
              typename T9, typename... Ts>
    struct insert<P, list<Os...>, list<In, Ins...>, true, true, T1, T2, T3, T4, T5, T6, T7, T8, T9,
                  Ts...> : insert<P, list<Os..., T1, T2, T3, T4, T5, T6, T7, T8>, list<In, Ins...>,
                                  brigand::apply<P, T9, In>::value, false, T9, Ts...>
    {
    };
    // fast track is less than insert, can fast track again
    template <class P, typename... Os, typename In, typename... Ins, typename T1, typename T2,
              typename T3, typename T4, typename T5, typename T6, typename T7, typename T8,
              typename T9, typename T10, typename T11, typename T12, typename T13, typename T14,
              typename T15, typename T16, typename... Ts>
    struct insert<P, list<Os...>, list<In, Ins...>, true, true, T1, T2, T3, T4, T5, T6, T7, T8, T9,
                  T10, T11, T12, T13, T14, T15, T16, Ts...>
        : insert<P, list<Os..., T1, T2, T3, T4, T5, T6, T7, T8>, list<In, Ins...>,
                 brigand::apply<P, T9, In>::value, brigand::apply<P, T16, In>::value, T9, T10, T11, T12, T13, T14, T15,
                 T16, Ts...>
    {
    };

    template <class P, typename Out, typename In>
    struct insert_helper;

    // cant fast track
    template <class P, typename O, typename... Os, typename In, typename... Ins>
    struct insert_helper<P, list<O, Os...>, list<In, Ins...>>
        : insert<P, list<>, list<In, Ins...>, brigand::apply<P, O, In>::value, false, O, Os...>
    {
    };
    // can fast track
    template <class P, typename O1, typename O2, typename O3, typename O4, typename O5, typename O6,
              typename O7, typename O8, typename... Os, typename In, typename... Ins>
    struct insert_helper<P, list<O1, O2, O3, O4, O5, O6, O7, O8, Os...>, list<In, Ins...>>
        : insert<P, list<>, list<In, Ins...>, brigand::apply<P, O1, In>::value, brigand::apply<P, O8, In>::value, O1, O2, O3,
                 O4, O5, O6, O7, O8, Os...>
    {
    };

    template <class P, typename Out, typename... Ts>
    struct sort_loop
    {
        using type = Out; // in is empty
    };
    // cant fast track
    template <class P, typename Out, typename In, typename... Ts>
    struct sort_loop<P, Out, In, Ts...>
        : sort_loop<P, typename insert_helper<P, Out, list<In>>::type, Ts...>
    {
    };
    // can fast track
    template <class P, typename Out, typename T1, typename T2, typename T3, typename T4, typename T5,
              typename T6, typename T7, typename T8, typename T9, typename T10, typename T11,
              typename T12, typename T13, typename T14, typename T15, typename T16,
              typename... Ts>
    struct sort_loop<P, Out, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16,
                     Ts...>
        : sort_loop<P, typename insert_helper<P,
                        Out, typename sort_loop<P, list<T1>, T2, T3, T4, T5, T6, T7, T8, T9, T10,
                                                T11, T12, T13, T14, T15, T16>::type>::type,
                    Ts...>
    {
    };

    // Sort
    template <typename Seq, typename Comp>
    struct sort_impl;
    // empty input case
    template <template <class...> class Seq, typename Comp>
    struct sort_impl<Seq<>, Comp>
    {
        using type = Seq<>;
    };
    // one element case
    template <template <class...> class Seq, typename T, typename Comp>
    struct sort_impl<Seq<T>, Comp>
    {
        using type = Seq<T>;
    };
    // two or more elements case
    template <template <class...> class Seq, typename T, typename U, typename... Ts, typename Comp>
    struct sort_impl<Seq<T, U, Ts...>, Comp>
    {
        using type =
            brigand::wrap<typename sort_loop<Comp, list<T>, U, Ts...>::type, Seq>;
    };
    // 255 or more elements case
    template <template <class...> class Seq, class T0, class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11, class T12, class T13, class T14, class T15, class T16, class T17, class T18, class T19, class T20, class T21, class T22, class T23, class T24, class T25, class T26, class T27, class T28, class T29, class T30, class T31, class T32, class T33, class T34, class T35, class T36, class T37, class T38, class T39, class T40, class T41, class T42, class T43, class T44, class T45, class T46, class T47, class T48, class T49, class T50, class T51, class T52, class T53, class T54, class T55, class T56, class T57, class T58, class T59, class T60, class T61, class T62, class T63, class T64, class T65, class T66, class T67, class T68, class T69, class T70, class T71, class T72, class T73, class T74, class T75, class T76, class T77, class T78, class T79, class T80, class T81, class T82, class T83, class T84, class T85, class T86, class T87, class T88, class T89, class T90, class T91, class T92, class T93, class T94, class T95, class T96, class T97, class T98, class T99, class T100, class T101, class T102, class T103, class T104, class T105, class T106, class T107, class T108, class T109, class T110, class T111, class T112, class T113, class T114, class T115, class T116, class T117, class T118, class T119, class T120, class T121, class T122, class T123, class T124, class T125, class T126, class T127, class T128, class T129, class T130, class T131, class T132, class T133, class T134, class T135, class T136, class T137, class T138, class T139, class T140, class T141, class T142, class T143, class T144, class T145, class T146, class T147, class T148, class T149, class T150, class T151, class T152, class T153, class T154, class T155, class T156, class T157, class T158, class T159, class T160, class T161, class T162, class T163, class T164, class T165, class T166, class T167, class T168, class T169, class T170, class T171, class T172, class T173, class T174, class T175, class T176, class T177, class T178, class T179, class T180, class T181, class T182, class T183, class T184, class T185, class T186, class T187, class T188, class T189, class T190, class T191, class T192, class T193, class T194, class T195, class T196, class T197, class T198, class T199, class T200, class T201, class T202, class T203, class T204, class T205, class T206, class T207, class T208, class T209, class T210, class T211, class T212, class T213, class T214, class T215, class T216, class T217, class T218, class T219, class T220, class T221, class T222, class T223, class T224, class T225, class T226, class T227, class T228, class T229, class T230, class T231, class T232, class T233, class T234, class T235, class T236, class T237, class T238, class T239, class T240, class T241, class T242, class T243, class T244, class T245, class T246, class T247, class T248, class T249, class T250, class T251, class T252, class T253, class T254, class T255, typename... Ts, typename Comp>
    struct sort_impl<Seq<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29, T30, T31, T32, T33, T34, T35, T36, T37, T38, T39, T40, T41, T42, T43, T44, T45, T46, T47, T48, T49, T50, T51, T52, T53, T54, T55, T56, T57, T58, T59, T60, T61, T62, T63, T64, T65, T66, T67, T68, T69, T70, T71, T72, T73, T74, T75, T76, T77, T78, T79, T80, T81, T82, T83, T84, T85, T86, T87, T88, T89, T90, T91, T92, T93, T94, T95, T96, T97, T98, T99, T100, T101, T102, T103, T104, T105, T106, T107, T108, T109, T110, T111, T112, T113, T114, T115, T116, T117, T118, T119, T120, T121, T122, T123, T124, T125, T126, T127, T128, T129, T130, T131, T132, T133, T134, T135, T136, T137, T138, T139, T140, T141, T142, T143, T144, T145, T146, T147, T148, T149, T150, T151, T152, T153, T154, T155, T156, T157, T158, T159, T160, T161, T162, T163, T164, T165, T166, T167, T168, T169, T170, T171, T172, T173, T174, T175, T176, T177, T178, T179, T180, T181, T182, T183, T184, T185, T186, T187, T188, T189, T190, T191, T192, T193, T194, T195, T196, T197, T198, T199, T200, T201, T202, T203, T204, T205, T206, T207, T208, T209, T210, T211, T212, T213, T214, T215, T216, T217, T218, T219, T220, T221, T222, T223, T224, T225, T226, T227, T228, T229, T230, T231, T232, T233, T234, T235, T236, T237, T238, T239, T240, T241, T242, T243, T244, T245, T246, T247, T248, T249, T250, T251, T252, T253, T254, T255, Ts...>, Comp>
    {
        using type = merge<
            brigand::wrap<typename sort_loop<Comp, list<T0>, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29, T30, T31, T32, T33, T34, T35, T36, T37, T38, T39, T40, T41, T42, T43, T44, T45, T46, T47, T48, T49, T50, T51, T52, T53, T54, T55, T56, T57, T58, T59, T60, T61, T62, T63, T64, T65, T66, T67, T68, T69, T70, T71, T72, T73, T74, T75, T76, T77, T78, T79, T80, T81, T82, T83, T84, T85, T86, T87, T88, T89, T90, T91, T92, T93, T94, T95, T96, T97, T98, T99, T100, T101, T102, T103, T104, T105, T106, T107, T108, T109, T110, T111, T112, T113, T114, T115, T116, T117, T118, T119, T120, T121, T122, T123, T124, T125, T126, T127, T128, T129, T130, T131, T132, T133, T134, T135, T136, T137, T138, T139, T140, T141, T142, T143, T144, T145, T146, T147, T148, T149, T150, T151, T152, T153, T154, T155, T156, T157, T158, T159, T160, T161, T162, T163, T164, T165, T166, T167, T168, T169, T170, T171, T172, T173, T174, T175, T176, T177, T178, T179, T180, T181, T182, T183, T184, T185, T186, T187, T188, T189, T190, T191, T192, T193, T194, T195, T196, T197, T198, T199, T200, T201, T202, T203, T204, T205, T206, T207, T208, T209, T210, T211, T212, T213, T214, T215, T216, T217, T218, T219, T220, T221, T222, T223, T224, T225, T226, T227, T228, T229, T230, T231, T232, T233, T234, T235, T236, T237, T238, T239, T240, T241, T242, T243, T244, T245, T246, T247, T248, T249, T250, T251, T252, T253, T254>::type, Seq>,
            brigand::wrap<typename sort_loop<Comp, list<T255>, Ts...>::type, Seq>
        >;
    };
}

template <typename Seq, typename Comp = less<_1,_2>>
using sort = typename detail::sort_impl<Seq, Comp>::type;
}
