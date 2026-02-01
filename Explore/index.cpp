//Write a program to accept a string from the user and display characters present at an even index number.
#include <iostream>
#include <string>

int main (){
    std::string user_input;

    std::cout << "Enter a string: ";
    std::getline(std::cin, user_input);

    std::cout<<"Characters are at even indices: ";

    for (int i =0; i<=user_input.length(); i+=2) {
        std::cout<< user_input[i] << " ";
    }

    std::cout<< std::endl;
    return 0;
}