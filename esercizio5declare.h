#ifndef ESERCIZIO5DECLARE_H
#define ESERCIZIO5DECLARE_H
#include <iostream>
//Class Descartes
class Descartes {
    public: 
    	void set_x(double gx);
        void set_y(double gy);
        void set_z(double gz);
        const double get_x();
        const double get_y();
        const double get_z();
    	Descartes(double x, double y, double z);
        const double distance(Descartes p);
    protected:
    	double x;
        double y;
        double z;
};
//Class Punto
class Punto : public Descartes{
    public:
        Punto(double x, double y, double z);
        friend std::ostream& operator << (std::ostream& COUT, Punto& P);
        static const int get_members();
    private:
        static int members;
};
class Sfera{
    public: 
        void set_r(double gr);
        const double get_r();
        void set_p(Punto gp);
        const Punto get_p();
        const double getArea();
        const double getVolume();
        Sfera(Punto p, double r);
        friend std::ostream& operator << (std::ostream& COUT, Sfera& S);
        static const int get_members();
    private:
        Punto p;
        double r;
        static int members;
};
#endif