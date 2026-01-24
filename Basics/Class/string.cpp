//to use string
#include <iostream>
#include <string>
using namespace std;

int main() {
    //defining four string
    string prompt("What is your name?: "),
    name,
    line(40, '-'),
    total = "Hello";

    cout<<prompt;
    getline(cin, name);

    total = total+name;

    cout<<line<<endl<<total<<endl;
    cout<<"Your name is "<<name.length()<<" Character long!"<<endl;
    cout<<line<<endl;
    return 0;  

}