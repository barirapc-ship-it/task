#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of students (1-10): ";
    cin >> n;

    if (n < 1 || n > 10) {
        cout << "Error: n must be between 1 and 10." << endl;
        return 0;
    }

    int* marks = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "Mark " << i + 1 << ": ";
        cin >> *(marks + i);
    }

    int newMark;
    cout << "Enter the new student's mark: ";
    cin >> newMark;

    // allocate bigger block, copy old values, append new mark
    int* bigger = new int[n + 1];
    for (int i = 0; i < n; i++)
        *(bigger + i) = *(marks + i);
    *(bigger + n) = newMark;

    delete[] marks;
    marks = bigger;
    n = n + 1;

    cout << "\nAll marks: ";
    for (int i = 0; i < n; i++)
        cout << *(marks + i) << " ";
    cout << endl;

    delete[] marks;
    marks = nullptr;

    return 0;
}
