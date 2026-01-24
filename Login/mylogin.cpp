#include <iostream>
#include <fstream>
#include <string>
#include <limits> // Required for numeric_limits

using namespace std;

class temp {
    string userName, Email, password;
    string searchName, searchPass, searchEmail;
    fstream file;
public:
    void login();
    void signUp();
    void forgot();
} obj;

int main() {
    char choice;
    cout << "\n1- Login";
    cout << "\n2- Sign-Up";
    cout << "\n3- Forgot Password";
    cout << "\n4- Exit";
    cout << "\nEnter Your Choice :: ";
    cin >> choice;

    // IMPORTANT: Clear the buffer so getline() doesn't skip
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (choice) {
        case '1': obj.login(); break;
        case '2': obj.signUp(); break;
        case '3': obj.forgot(); break;
        case '4': return 0;
        default: cout << "Invalid Selection..";
    }
    return 0;
}

void temp::signUp() {
    cout << "\nEnter your Username: ";
    getline(cin, userName);
    cout << "Enter your Email Address: ";
    getline(cin, Email);
    cout << "Enter Your Password: ";
    getline(cin, password);

    file.open("loginData.txt", ios::out | ios::app);
    file << userName << "*" << Email << "*" << password << endl;
    file.close();
    cout << "Registration Successful!\n";
}

void temp::login() {
    string sName, sPass;
    bool found = false;
    cout << "--------Login--------" << endl;
    cout << "Enter your username: ";
    getline(cin, sName);
    cout << "Enter your Password: ";
    getline(cin, sPass);

    file.open("loginData.txt", ios::in);
    if (!file) {
        cout << "No data found. Please sign up first.\n";
        return;
    }

    // Better way to read files line by line
    while (getline(file, userName, '*') && 
           getline(file, Email, '*') && 
           getline(file, password)) {
        if (userName == sName && password == sPass) {
            cout << "\nAccount login successful!!";
            cout << "\nUserName :: " << userName;
            cout << "\nEmail :: " << Email << endl;
            found = true;
            break;
        }
    }
    if (!found) cout << "Invalid username or password.\n";
    file.close();
}

void temp::forgot() {
    string sName, sEmail;
    bool found = false;
    cout << "\nEnter your Username: ";
    getline(cin, sName);
    cout << "Enter Your Email: ";
    getline(cin, sEmail);

    file.open("loginData.txt", ios::in);
    if (!file) {
        cout << "File not found!\n";
        return;
    }

    while (getline(file, userName, '*') && 
           getline(file, Email, '*') && 
           getline(file, password)) {
        if (userName == sName && Email == sEmail) {
            cout << "\nAccount Found!" << endl;
            cout << "Your Password: " << password << endl;
            found = true;
            break;
        }
    }
    if (!found) cout << "\nAccount not found.\n";
    file.close();
}