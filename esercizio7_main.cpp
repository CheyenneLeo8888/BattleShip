#include "esercizio7declare.h"
//Facciamo un esempio creando 3 Sfere e 3 Cubi
int main(){
    Sfera s1;
    Sfera s2;
    Sfera s3;
    Shape* ptr_s1 = &s1;
    Shape* ptr_s2 = &s2;
    Shape* ptr_s3 = &s3;
    s1.setRaggio(1);
    s2.setRaggio(2);
    s3.setRaggio(3);
    Cubo c1;
    Cubo c2;
    Cubo c3;
    Shape* ptr_c1 = &c1;
    Shape* ptr_c2 = &c2;
    Shape* ptr_c3 = &c3;
    c1.setLato(1);
    c2.setLato(2);
    c3.setLato(3);
    Shape* allShapes[]={ptr_c1,ptr_c2,ptr_c3,ptr_s1,ptr_s2,ptr_s3};
    for(Shape* shape : allShapes){
        shape->print(std::cout);
    }
    return 0;
}