//#define CATCH_CONFIG_MAIN
#include <iostream>
#include "Polynomial.h"
#include "catch.hpp"

int main(){
    Polynomial P1;
    P1.add(1,0);
    P1.add(-1,1);
    std::cout<<P1;
    P1.add(6,3);
    std::cout<<P1;

    return 0;
}