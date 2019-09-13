//#define CATCH_CONFIG_MAIN
#include <iostream>
#include "Polynomial.h"
#include "catch.hpp"

int main(){
    Polynomial P1;
    P1.add(1,2);
    P1.add(-1,1);
    P1.add(6,3);
    std::cout<<P1 << endl;
    P1.showP();

    return 0;
}