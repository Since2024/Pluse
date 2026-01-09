#include <iostream>
using namespace std;

class Project {
public:
    string name;
    int days;

    // Use a Member Initializer List (The best way to initialize)
    Project(string n, int d) : name(n), days(d) {
        cout << "Project '" << name << "' initialized with " << days << " days." << endl;
    }
};

int main() {
    // This triggers the constructor and INITIALIZES the object
    Project p1("Web Scraper", 1); 
    
    return 0;
}