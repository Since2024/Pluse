//Problem find the largest number
#include <iostream>
using namespace std;

int main() {
    int arr[]= {3, 7, 2, 9, 4};
    int n = 5;

    int maxValue = arr[0];

    for (int i =0; i<n; i++) {
        if (arr[i] > maxValue) {
            maxValue = arr[i];
        }
    }
    cout << maxValue;
    return 0;
}