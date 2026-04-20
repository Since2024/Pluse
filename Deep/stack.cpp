
#include <iostream>
using namespace std;

void demonstrateStack(){
    int num = 10;
    int x = 20;

    std::cout<<"value of num: "<<num<< "at address: " << &num;
    std::cout <<"Value of x: " <<x<< "at address: " << &x; 
}
int main(){
    demonstrateStack(); 
        return 0;
}
