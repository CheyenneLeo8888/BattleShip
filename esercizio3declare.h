#ifndef ESERCIZIO3DECLARE_H
#define ESERCIZIO3DECLARE_H
class Sphere{
     public: 
    	void set_r(double gr);
        void set_theta(double gtheta);
        void set_phi(double gphi);
        double get_r();
        double get_theta();
        double get_phi();
    	Sphere(double r, double theta, double phi);
        double distance(Sphere p);
     private:
    	double r;
        double theta;
        double phi;
};
#endif