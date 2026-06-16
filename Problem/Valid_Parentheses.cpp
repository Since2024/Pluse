//Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//An input string is valid if:
//  1.Open brackets must be closed by the same type of brackets.
// 2.Open brackets must be closed in the correct order.
// 3. Every close bracket has a corresponding open bracket of the same type.


// Note: Logic rule last openeing bracket should be first closing bracket means we solve this by using stack LIFO, from stacking first parentheses ongoing update we will only update then valid match last opening bracket with first closing bracket otherwise invalid.
#include <iostream>
#include <stack>
#include <string>

using namespace std;
class solution {
    public:
        bool isValid(string str) {
            stack<char> st;

            for(int i=0; i<str.size(); i++) {
                if(str[i] == '(' || str[i] == '{' || str[i] == '[') { //opening 
                    st.push(str[i]);
                } else { //closing
                    if(st.size() == 0) {
                        return false;
                    }

                    if((st.top() == '(' && str[i] == ')') ||
                        (st.top() == '{' && str[i] == '}') ||
                        (st.top() == '[' && str[i] == ']')) {
                        st.pop();
                    } else { //no matc1h
                        return false;
                   }

                }

            }

            return st.size() == 0;

        }


};

int main() {
   solution sol;
    
    // Test cases
    string test1 = "()[]{}";
    string test2 = "([)]";
    
    cout << "Test 1: " << (sol.isValid(test1) ? "Valid" : "Invalid") << endl;
    cout << "Test 2: " << (sol.isValid(test2) ? "Valid" : "Invalid") << endl;
    
    return 0; // Success
}
