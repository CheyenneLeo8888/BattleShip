//Risoluzione esercizio 1 sui puntatori
#include <iostream>
using namespace std;

int main() {
    int intero = 1;
    double doppio = 2.2;
    double my_array[]={1.1,1.2,1.3,1.4,1.5};
    cout << intero << "\n" << doppio << "\n" << endl;
    for (double value : my_array){
        cout << value << "\n";
    }
    int* ptr_intero = &intero;
    double* ptr_doppio = &doppio;
    ++*ptr_intero;
    ++*ptr_doppio;
    cout << "\n" << intero << "\n" << doppio << endl; 
    
    //Mi occupo di incrementare gli elementi dell'array
    double* ptr_arr;
    ptr_arr=my_array;
    for (int i=0; i<5; i++){
	++*(ptr_arr + i);
    }
    for (double value : my_array){
        cout << value << "\n";
    }
  return 0;
}