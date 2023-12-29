#include <cmath>
#include <string>
#include "esercizio6declare.h"
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
std::ostream& Punto::print(std::ostream& os){
    return os << "[" << x << "," << y << "," << z << "]";
}
//Class -- Sfera inherits Punto
int Sfera::members=0;
Sfera::Sfera(double x, double y, double z, double r):Punto(x,y,z),r(r){++members;};
const double Sfera::get_r(){
    return r;
}
void Sfera::set_r(double gr){
    r = gr;
}
Punto Sfera::getCentro(){
    Punto myPoint(x,y,z);
    return myPoint;
}
void Sfera::setCentro(Punto gp){
    set_x(gp.get_x()); 
    set_y(gp.get_y());
    set_z(gp.get_z());
}
const double Sfera::GetArea(){
    const double pi = 3.14159265358979323846;
    return 4*pi*r*r;
}
const double Sfera::GetVolume(){
    const double pi = 3.14159265358979323846;
    return (4./3.)*pi*r*r*r;
}
std::ostream& operator << (std::ostream& COUT, Sfera& S){
    COUT <<"The radius is: "<<S.get_r()<<"\n";
    COUT <<"The surface area is: "<<S.GetArea()<<"\n";
    COUT <<"The volume is:"<<S.GetVolume()<<"\n";
    return COUT,S.getCentro().print(std::cout);
}


