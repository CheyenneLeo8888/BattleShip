#include "esercizio6declare.h"
int main(){
    Sfera s1(2.2,4.5,6.7,9.4);
    std::cout << "User defined radius: "<< s1.get_r() << std::endl;
    s1.set_r(3);
    std::cout << "New radius: "<< s1.get_r() << std::endl;
    std::cout << s1;
}