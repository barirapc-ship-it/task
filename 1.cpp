#include <iostream>
using namespace std;

int main() {
    // Create the array with the given numbers
    int numbers[5] = {2, 4, 6, 8, 10};

    // Change the third element (index 2) to 7
    numbers[2] = 7;

    // Display all the values using a for loop
    for (int i = 0; i < 5; i++) {
        cout << numbers[i] << " ";
    }

    return 0;
}