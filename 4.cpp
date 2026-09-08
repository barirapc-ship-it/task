#include <iostream>
using namespace std;

int main() {
    const int SIZE = 8;
    int arr[SIZE];

    // asking the user to input 8 integers into the array
    cout << "Enter 8 integers:" << endl;
    for (int i = 0; i < SIZE; i++) {
        cin >> arr[i];
    }

    // assuming the first element holds the initial largest and smallest values
    int largest = arr[0];
    int largestIndex = 0;
    int smallest = arr[0];
    int smallestIndex = 0;

    // looping through the rest of the array to find max and min
    for (int i = 1; i < SIZE; i++) {
        // using '>' ensures we keep the first occurrence if the maximum repeats
        if (arr[i] > largest) {
            largest = arr[i];
            largestIndex = i;
        }111;
        
        // using '<' ensures we keep the first occurrence if the minimum repeats
        if (arr[i] < smallest) {
            smallest = arr[i];
            smallestIndex = i;
        }
    }

    // printing out the results with their indices
    cout << "\nLargest Value: " << largest << " at index " << largestIndex << endl;
    cout << "Smallest Value: " << smallest << " at index " << smallestIndex << endl;

    return 0;
}
