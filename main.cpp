#define CON_CATCH

#ifndef CON_CATCH
#include <iostream>
#include "Polynomial.h"

int main(){
    Polynomial p;
    p.add(1,0);
    p.add(-1,1);
    p.add(6,3);


    std::cout<<p << endl;
    auto p2 = p;
    p2 = p2+p;




    std::cout<<endl << p2 << endl;

    return 0;
}
#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#endif