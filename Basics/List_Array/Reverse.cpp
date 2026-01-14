#include <iostream>
using namespace std;

int main () {
    // 1. DATA INITIALIZATION
    int arr[] = {3, 7, 2, 9, 4};
    int n = 5; // Total number of elements

    // 2. POINTER SETUP
    // 'left' starts at the first index (0)
    int left = 0; 
    // 'right' starts at the last index (n-1)
    int right = n - 1; 

    /* 3. THE REVERSAL ENGINE (Two-Pointer Logic)
       We run the loop until the two pointers meet in the middle.
       If we go past the middle, we would just be reversing it back to original! */
    while (left < right) {
        
        // Swap values at current pointer positions
        // This puts the 'right' value at the 'left' and vice versa
        swap(arr[left], arr[right]);

        // Move the pointers toward the center
        left++;   // Increment left to move forward
        right--;  // Decrement right to move backward
    }

    /* 4. OUTPUT PHASE
       The array is now reversed in memory. 
       We use a for-loop to traverse and print the result. */
    cout << "Reversed Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}