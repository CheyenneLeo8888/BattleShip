#include "esercizio7declare.h"
#include <cmath>
//Implementazione delle cose vuote
const double Shape::getArea(){return 0.;};
const double Shape::getVolume(){return 0.;};
//Implementazione della classe Sfera
void Sfera::setRaggio(double graggio){
    raggio = graggio;
}
const double Sfera::getRaggio(){
    return raggio;
}
const double Sfera::getArea(){
    const double pi = 3.14159265358979323846;
    return 4*pi*raggio*raggio;
}
const double Sfera::getVolume(){
    const double pi = 3.14159265358979323846;
    return (4./3.)*pi*raggio*raggio*raggio;
}
const std::string Sfera::getName(){
    return "Sfera";
}
std::ostream& Sfera::print(std::ostream& os){
    os << "This is a " << getName() << "\n";
    os << "The radius is: " << raggio << "\n";
    os << "The surface area is: " << getArea() << "\n";
    os << "The volume is: " << getVolume() << "\n";
    return os;
}
//Implementazione della classe Cubo
void Cubo::setLato(double glato){
    lato = glato;
}
const double Cubo::getLato(){
    return lato;
}
const double Cubo::getArea(){
    return 6*lato*lato;
}
const double Cubo::getVolume(){
    return lato*lato*lato;
}
const std::string Cubo::getName(){
    return "Cubo";
}
std::ostream& Cubo::print(std::ostream& os){
    os << "This is a " << getName() << "\n";
    os << "The side length is: " << lato << "\n";
    os << "The surface area is: " << getArea() << "\n";
    os << "The volume is: " << getVolume() << "\n";
    return os;
}