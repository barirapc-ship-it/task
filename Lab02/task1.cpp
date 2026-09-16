#include <iostream>
using namespace std;

int main() {
    int sales[5];
    int* p = sales;

    cout << "Enter sales for 5 days:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Day " << i + 1 << ": ";
        cin >> *(p + i);
    }

    int total = 0;
    cout << "\nValues: ";
    for (int i = 0; i < 5; i++) {
        cout << *(p + i) << " ";
        total += *(p + i);
    }
    cout << "\nTotal: " << total << endl;

    // add 2 to day 3 (index 2)
    *(p + 2) = *(p + 2) + 2;

    total = 0;
    cout << "\nUpdated values: ";
    for (int i = 0; i < 5; i++) {
        cout << *(p + i) << " ";
        total += *(p + i);
    }
    cout << "\nUpdated total: " << total << endl;

    return 0;
}
