#include <iostream>
#include "esercizio2declare.h"
int main() {
Descartes p1(10.1,3.1,9.2);
Descartes p2(2.1,4.3,5.1);
double my_distance = p1.distance(p2);
std::cout<<my_distance;
return 0;
}
