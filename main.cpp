//#define CATCH_CONFIG_MAIN
#include <iostream>
#include "Polynomial.h"
#include "catch.hpp"

int main(){
    Polynomial p;
    p.add(6,3);
    p.add(-1,1);
    p.add(1,0);


    std::cout<<p << endl;

    return 0;
}