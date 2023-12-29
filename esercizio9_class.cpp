#include "esercizio9declare.h"
#include <iostream>
//Implementazione dei metodi concreti per i prodotti di Tank
void Tiger::move(){
    std::cout << " is moving" ;
}
void T34::move(){
    std::cout << " is moving" ;
}
void Tiger::fight(){
    std::cout << " is firing its cannon";
}
void T34::fight(){
    std::cout << " is firing its cannon";
}
std::string Tiger::getName(){
    return name;
}
std::string T34::getName(){
    return name;
}
//Implementazione dei metodi concreti per i prodotti di Infantry
void GermanInfantry::move(){
    std::cout << " is moving" ;
}
void RussianInfantry::move(){
    std::cout << " is moving" ;
}
void GermanInfantry::fight(){
    std::cout << " is firing its MP40";
}
void RussianInfantry::fight(){
    std::cout << " is firing its Mosin-Nagant";
}
std::string GermanInfantry::getName(){
    return name;
}
std::string RussianInfantry::getName(){
    return name;
}
/*unit* GermanFactory::createUnit() const{
    return new unit();
}*/