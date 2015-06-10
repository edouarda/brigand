
#pragma once

#include <type_traits>

#include <brigand/pair.hpp>
#include <brigand/no_such_type.hpp>

namespace brigand
{

    template <class... T>
    struct map;

    template <>
    struct map<>
    {
        template <typename U>
        static no_such_type_ at(U) {}     
    };

    template <typename Last>
    struct map<Last>
    {
    
        static typename Last::second_type at(typename Last::first_type);
    
        // I wanted to call it "not sure if type" but Joel didn't want to :(
        template <typename U>
        static no_such_type_ at(U) {}
    
    };

    template <class First, class... T>
    struct map<First, T...>
    {
        static typename First::second_type at(typename First::first_type);
    
        template <typename U>
        static decltype(typename map<T...>::at(U{})) at(U);
    };


    template <typename M, typename K>
    struct lookup
    {
        using type = typename decltype(M::at(K{}));
    };

}