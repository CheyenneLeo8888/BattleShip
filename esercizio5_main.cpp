#include "esercizio5declare.h"
int main(){
    //Creiamo 2 punti
    Punto p1(1,2,3);
    std::cout << p1 << std::endl;
    std::cout << "Points created till now: "<< p1.get_members() << std::endl;
    Punto p2(3,6,7);
    std::cout << p2 << std::endl;
    std::cout << "Points created till now: " << p2.get_members() << std::endl;
    //Creiamo 2 sfere
    double r1 = 1.6;
    double r2 = 6.3;
    Sfera s1(p1,r1);
    std::cout << s1;
    std::cout << "Spheres created till now: " << s1.get_members() << std::endl;
    Sfera s2(p2,r2);
    std::cout << s2;
    std::cout << "Spheres created till now: " << s2.get_members() << std::endl;
    return 0;
}
