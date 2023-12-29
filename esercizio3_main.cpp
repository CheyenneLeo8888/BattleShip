#include <iostream>
#include "esercizio3declare.h"

int main(){
    Sphere p1(2.2,2.1,0);
    Sphere p2(3,1,6.7);
std::cout << p1.distance(p2);
    return 0;
}