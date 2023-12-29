//Definition of the class
#ifndef ESERCIZIO2DECLARE_H
#define ESERCIZIO2DECLARE_H

class Descartes {
    public: 
    	void set_x(double gx);
        void set_y(double gy);
        void set_z(double gz);
        double get_x();
        double get_y();
        double get_z();
    	Descartes(double x, double y, double z);
        double distance(Descartes p);
    protected:
    	double x;
        double y;
        double z;
};

#endif 