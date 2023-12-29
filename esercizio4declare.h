#ifndef ESERCIZIO4DECLARE_H
#define ESERCIZIO4DECLARE_H
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
class Punto : public Descartes{
    public:
        Punto(double x, double y, double z);
        void print();
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
        void Sprint();
    private:
        Punto p;
        double r;

};


#endif