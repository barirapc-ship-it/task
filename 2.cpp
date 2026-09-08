#include <iostream>
using namespace std;

int main() {
    int numbers[5];
    int total = 0;

    // asking the user to input 5 numbers
    cout << "Enter 5 numbers:" << endl;
    for (int i = 0; i < 5; i++) {
        cin >> numbers[i];
    }

    // adding the numbers together
    for (int i = 0; i < 5; i++) {
        total = total + numbers[i];
    }

    // displaying the final total
    cout << "Total = " << total << endl;

    return 0;
}
