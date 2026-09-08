#include <iostream>
using namespace std;

int main() {
    const int SIZE = 10;
    int arr[SIZE];

    // taking 10 integers input from the user
    cout << "Enter 10 integers:" << endl;
    for (int i = 0; i < SIZE; i++) {
        cin >> arr[i];
    }

    int uniqueCount = 0;

    // shifting unique elements to the front in-place while keeping their original order
    for (int i = 0; i < SIZE; i++) {
        bool isDuplicate = false;
        
        // checking if the current element already exists in our unique elements section
        for (int j = 0; j < uniqueCount; j++) {
            if (arr[j] == arr[i]) {
                isDuplicate = true;
                break;
            }
        }

        // if it's unique, add it to the next available position in the front
        if (!isDuplicate) {
            arr[uniqueCount] = arr[i];
            uniqueCount++;
        }
    }

    // displaying the unique values located in the first 'uniqueCount' positions
    cout << "\nUnique values: {";
    for (int i = 0; i < uniqueCount; i++) {
        cout << arr[i];
        if (i < uniqueCount - 1) cout << ", ";
    }
    cout << "}" << endl;

    cout << "Count: " << uniqueCount << endl;

    return 0;
}