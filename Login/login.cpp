#include <iostream>
#include <fstream>
using namespace std;

class temp{
    string userName,Email,password;
    fstream file;
    public:
    void login();
    void signUp();
    void forgot();

}obj;
int main () {
    char choice;
    cout<<"\n1- Login";
    cout<<"\n2- Sign-Up";
    cout<<"\n3- Forgot Password";
    cout<<"\n4- Exit";
    cout<<"\nEnter Your Choice :: ";
    cin>>choice;

    switch (choice)
    {
        case '1':

        break;
        case '2':

        break;
        case '3':

        break;
        case '4':

        break;
        default:
        cout<<"INvalid Selection..";

    }
}
void temp :: signUp() {
    cout<<"\nEnter your Username: ";
    getline(cin,userName);
    cout<<"Enter your Email Address: ";
    getline(cin,Email);
    cout<<"Enter YOur Password: ";
    getline(cin,password);

    file.open("loginData.txt",ios :: out | ios :: app);
    file<<userName<<"*"<<Email<<"*"<<password<<endl;
    file.close();
}