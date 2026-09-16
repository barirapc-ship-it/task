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

    int total = 0;
    int passCount = 0;
    cout << "\nMarks: ";
    for (int i = 0; i < n; i++) {
        cout << *(marks + i) << " ";
        total += *(marks + i);
        if (*(marks + i) >= 50)
            passCount++;
    }

    double average = (double)total / n;
    cout << "\nTotal: " << total << endl;
    cout << "Average: " << average << endl;
    cout << "Count >= 50: " << passCount << endl;

    delete[] marks;
    marks = nullptr;

    return 0;
}
