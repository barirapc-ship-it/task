#include <iostream>
using namespace std;

int main() {
    const int SIZE = 6;
    int arr[SIZE];

    // taking 6 integers input from the user
    cout << "Enter 6 integers: " << endl;
    for (int i = 0; i < SIZE; i++) {
        cin >> arr[i];
    }

    // reversing the array in-place by swapping elements from both ends towards the center
    for (int i = 0; i < SIZE / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[SIZE - 1 - i];
        arr[SIZE - 1 - i] = temp;
    }

    // displaying the updated array after reversal
    cout << "Reversed array: ";
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}