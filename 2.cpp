#include <iostream>
using namespace std;

int main() {
    int numbers[5];
    int total = 0;

    // Read five numbers from the user
    for (int i = 0; i < 5; i++) {
        cin >> numbers[i];
    }

    // Add the numbers together
    for (int i = 0; i < 5; i++) {
        total = total + numbers[i];
    }

    // Display the total
    cout << "Total = " << total << endl;

    return 0;
}