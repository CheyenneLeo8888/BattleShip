#include <cmath>
#include "esercizio2declare.h"
//The class

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
Descartes::Descartes(double x, double y, double z){
    set_x(x);
    set_y(y);
    set_z(z);
}
double Descartes::distance(Descartes p){
    return sqrt((x-p.x)*(x-p.x) + (y-p.y)*(y-p.y) + (z-p.z)*(z-p.z) );
}
