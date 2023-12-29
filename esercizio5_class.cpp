#include <cmath>
#include "esercizio5declare.h"
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
const double Descartes::get_x(){
    return x;
}      
const double Descartes::get_y(){
    return y;
}  
const double Descartes::get_z(){
    return z;
}  
Descartes::Descartes(double x, double y, double z):x(x),y(y),z(z){}
const double Descartes::distance(Descartes p){
    return sqrt((x-p.x)*(x-p.x) + (y-p.y)*(y-p.y) + (z-p.z)*(z-p.z) );
}

//Class -- Punto inherits Descartes
int Punto::members=0;
Punto::Punto(double x, double y, double z):Descartes(x,y,z){++members;};
const int Punto::get_members(){
    return members;
}
std::ostream& operator << (std::ostream& COUT, Punto& P){
    COUT << "[" << P.x << "," << P.y << "," << P.z << "]";
    return COUT;
}
//Class -- Sfera
int Sfera::members=0;
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
Sfera::Sfera(Punto p, double r):p(p),r(r){++members;}
const double Sfera::getArea(){
    const double pi = 3.14159265358979323846;
    return 4*pi*r*r;
}
const double Sfera::getVolume(){
    const double pi = 3.14159265358979323846;
    return (4./3.)*pi*r*r*r;
}
std::ostream& operator << (std::ostream& COUT, Sfera& S){
    COUT << "The center of the sphere is: " << S.p << std::endl;
    COUT << "The radius of the sphere: " << S.r << std::endl;
    COUT << "The surface area of the sphere is: " << S.getArea() << std::endl;
    COUT << "The volume of the Sphere is: " << S.getVolume() << std::endl;
    return COUT;
}
const int Sfera::get_members(){
    return members;
}