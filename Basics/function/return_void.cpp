#include <iostream>
#include <string>

//defining function
void sayHello(std::string name){
    std::cout<<"Hello, "<< name << "!" << std::endl;
}

int main(){
    //calling a function
    sayHello("Alice");
    sayHello("Bob");

    return 0;
}