#include <iostream>
#include <string>
using namespace std;

class Startup {
public:
    string name;
    double investment;

    // 1. DEFAULT CONSTRUCTOR
    // Runs when: Startup s1;
    Startup() : name("Side Project"), investment(0.0) {
        cout << "[Default] New basic startup created: " << name << endl;
    }

    // 2. PARAMETERIZED CONSTRUCTOR
    // Runs when: Startup s2("Butwal Tech", 50000);
    Startup(string n, double i) : name(n), investment(i) {
        cout << "[Parameterized] Custom startup created: " << name << endl;
    }

    // 3. DELEGATING CONSTRUCTOR (C++11)
    // One constructor calls another constructor to reduce code repetition.
    Startup(string n) : Startup(n, 1000.0) { 
        cout << "[Delegating] Minimal setup for: " << name << endl;
    }

    // 4. COPY CONSTRUCTOR
    // Runs when: Startup s4 = s2; (Creates a brand new object using s2's data)
    Startup(const Startup &old_obj) {
        name = old_obj.name + " (Copy)";
        investment = old_obj.investment;
        cout << "[Copy] Duplicated startup: " << name << endl;
    }

    void display() {
        cout << "   -> Name: " << name << " | Balance: " << investment << " RS" << endl;
    }
};

int main() {
    cout << "--- Initializing Objects ---\n" << endl;

    Startup s1;                     // Calls Default
    Startup s2("Global AI", 90000); // Calls Parameterized
    Startup s3("Local App");        // Calls Delegating (which calls Parameterized)
    Startup s4 = s2;                // Calls Copy

    cout << "\n--- Final Database Status ---" << endl;
    s1.display();
    s2.display();
    s3.display();
    s4.display();

    return 0;
}