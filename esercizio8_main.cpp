#include "esercizio7declare.h"
#include <vector>
using namespace std;
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
    std::vector<Shape*> allShapes;
    allShapes.push_back(ptr_s1);
    allShapes.push_back(ptr_s2);
    allShapes.push_back(ptr_s3);
    allShapes.push_back(ptr_c1);
    allShapes.push_back(ptr_c2);
    allShapes.push_back(ptr_c3);
    for(Shape* shape : allShapes){
        shape->print(std::cout);
    }
    return 0;
}