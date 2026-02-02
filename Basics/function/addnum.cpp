#include <iostream>

int addNumbers(int a, int b){
    int sum = a+b;
    return sum;
}
int main(){
    int result = addNumbers(4,10);
    std::cout<< "THe sum is " <<result<<std::endl;
    return 0;
}