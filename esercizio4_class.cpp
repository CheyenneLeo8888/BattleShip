#include <iostream>
#include <cmath>
#include "esercizio4declare.h"
//Class -- Descartes
void Descartes::set_x(double gx){
    x = gx;
}

void Descartes::set_y(double gy){
    y = gy;
}        
void Descartes::set_z(double gz){
    z = gz;
}        
double Descartes::get_x(){
    return x;
}      
double Descartes::get_y(){
    return y;
}  
double Descartes::get_z(){
    return z;
}  
Descartes::Descartes(double x, double y, double z):x(x),y(y),z(z){}
double Descartes::distance(Descartes p){
    return sqrt((x-p.x)*(x-p.x) + (y-p.y)*(y-p.y) + (z-p.z)*(z-p.z) );
}
//Class -- Punto inherits Descartes
Punto::Punto(double x, double y, double z):Descartes(x,y,z){};
void Punto::print(){
    std::cout << "[" << x << "," << y << "," << z << "]";
}
//Class -- Sfera
void Sfera::set_r(double gr){
    r = gr;
}
const double Sfera::get_r(){
    return r;
}
void Sfera::set_p(Punto gp){
    p = gp;
}
const Punto Sfera::get_p(){
    return p;
}   
Sfera::Sfera(Punto p, double r):p(p),r(r){}
const double Sfera::getArea(){
    const double pi = 3.14159265358979323846;
    return 4*pi*r*r;
}
const double Sfera::getVolume(){
    const double pi = 3.14159265358979323846;
    return (4./3.)*pi*r*r*r;
}
void Sfera::Sprint(){
    std::cout << "S:={(x,y,z)/x^2 + y^2 + z^2 < "<<r*r<<"}";
}     
        
        
        