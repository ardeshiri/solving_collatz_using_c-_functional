#include <iostream>
#include "series.h"
using namespace std;


int main()
{



    //using t = sq::for_do_f<sq::print_single, 3, size_t, 11,22,33,4,56,1,7,8,2>;


    //print_seq(sq::index_sequence<11,44,55,33>{});
    //using rng = sq::including_index_range<0,200,1>;
    using seq = sq::Collatz_sequence<568>  ;
    print_seq(seq{});

    using seq1 = sq::Collatz_sequence<284>  ;
    print_seq(seq1{});
    //cout<<sq::is_even<16>();


    return 0;
}
