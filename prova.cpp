#include <iostream>
#include <ctime>
#include <random>
#include <vector>
int main(){
std::vector<int> interi=  {};
interi.push_back(8);
for(int i=0;i<interi.size();i++) {
    std::cout << interi[i] << std::endl;
}
return 0;
}