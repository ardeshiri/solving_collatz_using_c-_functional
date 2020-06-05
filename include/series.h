#ifndef SERIES_H
#define SERIES_H
#include <iostream>


namespace sq{


template<typename T,T...NS>
struct sequence
{
    using sequence_type = T;
    static constexpr size_t sequence_size = sizeof...(NS);
};

template<size_t...NS>
using index_sequence = sequence<size_t, NS...>;
///-------------------------------------------------------------------------------------------------------------------------------

template< size_t N, typename T, T...NS>
struct range_to_seq;

template<size_t N, typename T, T F , T...NS>
struct range_to_seq<N, T , F, NS...>
{
    using seq = typename range_to_seq<N-1, T, F , F+N-1 , NS... >::seq ;
};

template<typename T, T F , T...NS>
struct range_to_seq<0, T ,F ,NS...>
{
    using seq = sequence<T , NS... > ;
};


template<typename SQ, typename SQ::range_type...NS>
using range_to_sequence = typename range_to_seq< SQ::range_size , typename SQ::range_type , SQ::first ,NS...>::seq;


///-------------------------------------------------------------------------------------------------------------------------------
template<typename T, T F, T L, size_t S>  /// first last(including last)
struct including_range
{
    using range_type = T;
    static constexpr T first = F;
    static constexpr T last = L;
    static constexpr size_t range_size = L-F+1;
    static constexpr size_t range_step = S;
};

template< size_t F, size_t L , size_t S>
using including_index_range = including_range<size_t,F,L,S>;
///-------------------------------------------------------------------------------------------------------------------------------

template<size_t V>
struct is_odd_:is_odd_<V-2>
{
};

template<>
struct is_odd_<1>
{
    static constexpr bool result = true;
};

template<>
struct is_odd_<0>
{
    static constexpr bool result = false;
};

template<size_t V>
constexpr bool is_odd()
{
    return is_odd_<V>::result;
}

template<size_t V>
constexpr bool is_even()
{
    return is_odd_<V-1>::result;
}


///----

template< size_t X, size_t...NS >
struct if_even_
{
    using seq = sequence<size_t , X/2, X, NS...> ;
};

template<size_t N,size_t...NS>
using if_even = typename if_even_<N, NS...>::seq;

template<size_t X, size_t...NS>
struct if_odd_
{
    using seq = sequence<size_t , (3*X)+1, X, NS...> ;
};

template< size_t X, size_t...NS >
using if_odd = typename if_odd_<X, NS...>::seq;







template<bool E, size_t N, size_t...NS>
struct Collatz_sequence_;

template<size_t N, size_t X, size_t...NS>
struct Collatz_sequence_<true, N, X , NS...>:Collatz_sequence_<is_even<X/2>(),N+1,X/2,X,NS...>
{};

template<size_t N, size_t X, size_t...NS>
struct Collatz_sequence_<false, N, X , NS...>:Collatz_sequence_<is_even<(3*X)+1>(), N+1, (3*X)+1,X,NS...>
{};

template<size_t N, size_t...NS>
struct Collatz_sequence_< false, N , 1 , NS...>
{
    using seq = sequence<size_t, N , 1 , NS...> ;
};

template<size_t N>
using Collatz_sequence = typename Collatz_sequence_< is_even<N>(), 1 , N>::seq;



///-------------------------------------------------------------------------------------------------------------------------------

template<template<typename> class F, size_t N, typename T, T...NS>
struct for_do_f;

template<template<typename> class F, size_t N, typename T, T V, T...NS>
struct for_do_f<F, N, T, V, NS...>: for_do_f<F, N-1, T, NS...>
{
    static constexpr T val = F<T>(V);
};

template<template<typename> class F, typename T, T V, T...NS>
struct for_do_f<F, 0, T, V, NS...>
{
    static constexpr T val = F<T>(V);
};


template<typename T,T t1>
void print_seq(sequence<T, t1>)  /// parameteres having name causes problem!!!
{
    std::cout<< t1<<std::endl;
}

template<typename T, T t1, T...vs>
void print_seq(sequence<T, t1, vs...>)
{
    std::cout<< t1<<" - ";
    print_seq(sequence<T, vs...>{});
}






}
#endif // SERIES_H
