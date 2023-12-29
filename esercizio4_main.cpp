#include "esercizio4declare.h"
#include <iostream>
using namespace std;
int main(){
    Punto p1(2.3,9.6,8.4);
    double r = 2.3;
    Sfera s1(p1,r);
    cout << "The Surface Area is:" << s1.getArea() << endl;
    cout << "The Volume is:" << s1.getVolume() << endl;
    s1.Sprint();
    return 0;
}
