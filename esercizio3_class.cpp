#include <cmath>
#include "esercizio3declare.h"
//Definisco proprietà e metodi
void Sphere::set_r(double gr){
    r = gr;
}

void Sphere::set_theta(double gtheta){
    theta = gtheta;
}        
void Sphere::set_phi(double gphi){
    phi = gphi;
}        
double Sphere::get_r(){
    return r;
}      
double Sphere::get_theta(){
    return theta;
}  
double Sphere::get_phi(){
    return phi;
}  
Sphere::Sphere(double r, double theta, double phi){
    set_r(r);
    set_theta(theta);
    set_phi(phi);
}
double Sphere::distance(Sphere p){
    double x0 = r*cos(phi)*sin(theta);
    double y0 = r*sin(phi)*sin(theta);
    double z0 = r*cos(theta);
    double xp = p.r*cos(p.phi)*sin(p.theta);
    double yp = p.r*sin(p.phi)*sin(p.theta);
    double zp = p.r*cos(p.theta);
    double my_distance = sqrt((x0-xp)*(x0-xp) + (y0-yp)*(y0-yp) + (z0-zp)*(z0-zp));
    return my_distance;
}