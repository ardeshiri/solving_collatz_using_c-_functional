#include <iostream>
#include "series.h"
using namespace std;


int main()
{

    //using t = sq::for_do_f<sq::print_single, 3, size_t, 11,22,33,4,56,1,7,8,2>;
    //print_seq(sq::index_sequence<11,44,55,33>{});
    //using rng = sq::including_index_range<0,200,1>;


    //cout<< sq::max_num<6, 11,65, 2, 555,12,31>::max_val;
    using seq = sq::Collatz_seqs_len_<50>  ;
    print_seq(seq::seq{});
    cout<<endl<< seq::max_len<<endl;
    cout<<endl<< seq::max_len_index<<endl;


   // using seq1 = sq::Collatz_sequence<837799>  ;
   // print_seq(seq1{});
    //cout<<sq::is_even<16>();


    return 0;
}
