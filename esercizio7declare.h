#ifndef ESERCIZIO7DECLARE_H
#define ESERCIZIO7DECLARE_H
#include <string>
#include <iostream>
//Abstract Parent Class -- Shape
class Shape{
    public:
        virtual const double getArea();
        virtual const double getVolume();
        virtual const std::string getName() = 0;
        virtual std::ostream& print(std::ostream& os) = 0;
};
//Child Class -- Sfera inherits Shape
class Sfera: public Shape{
    public: 
        const double getRaggio();
        void setRaggio(double graggio);
        virtual const double getArea();
        virtual const double getVolume();
        virtual const std::string getName();
        virtual std::ostream& print(std::ostream& os);
    private:
        double raggio;
};
//Child Class -- Cubo inherits Shape
class Cubo: public Shape{
    public: 
        const double getLato();
        void setLato(double glato);
        virtual const double getArea();
        virtual const double getVolume();
        virtual const std::string getName();
        virtual std::ostream& print(std::ostream& os);
    private:
        double lato;
};

#endif