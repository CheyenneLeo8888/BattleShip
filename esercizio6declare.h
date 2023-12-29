#ifndef ESERCIZIO6DECLARE_H
#define ESERCIZIO6DECLARE_H
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
        std::ostream& print(std::ostream& os);
    private:
        static int members;
};
//Class Sfera
class Sfera : public Punto{
    public:
        Sfera(double x, double y, double z, double r);
        void set_r(double gr);
        const double get_r();
        void setCentro(Punto gp);
        Punto getCentro();
        const double GetArea();
        const double GetVolume();
        friend std::ostream& operator << (std::ostream& COUT, Sfera& S);
        static const int get_members();
    private: 
        double r;
        static int members;
};



#endif