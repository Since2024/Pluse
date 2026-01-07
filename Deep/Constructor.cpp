#include <iostream>
#include <sys/types.h>
using namespace std;

class Cat
{
    private:
        string name;
        string color;
        string favorite_toy;

    public:
    
    void print_cat(){
        cout << "Name: " << name << endl;
        cout << "Color: " << color << endl;
        cout << "Favorite Toy: " << favorite_toy << endl;
    }
    Cat()
    {
        name = "Unknown";
        color = "Unknown";
        favorite_toy = "Unknown";
        
    }
         
}
int main ()
{
    Cat cat1;
    

    return 0;

}
