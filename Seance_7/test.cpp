#include "counter.hpp"
#include<iostream>



int main(){
    unsigned int a =10;
    unsigned int b = 20;

//    ForwardCounter A(a,b);
//    BackwardCounter B(a,b);
    VerboseForwardCounter C(a,b);
//    testNext(A);
//    testNext(B);
    std::cout << C;
    std::cout << std::endl;
//    testForwardCounter(C);
    testNext(C);
    return 0;

}
