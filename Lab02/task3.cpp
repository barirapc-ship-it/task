#include <iostream>
using namespace std;

int main() {
    int sales[2][3];
    int (*rowPtr)[3] = sales;

    for (int r = 0; r < 2; r++) {
        cout << "Branch " << r + 1 << ":" << endl;
        for (int c = 0; c < 3; c++) {
            cout << "  Day " << c + 1 << ": ";
            cin >> *(*(rowPtr + r) + c);
        }
    }

    cout << "\nSales table:" << endl;
    for (int r = 0; r < 2; r++) {
        for (int c = 0; c < 3; c++)
            cout << *(*(rowPtr + r) + c) << " ";
        cout << endl;
    }

    cout << "\nBranch totals:" << endl;
    for (int r = 0; r < 2; r++) {
        int branchTotal = 0;
        for (int c = 0; c < 3; c++)
            branchTotal += *(*(rowPtr + r) + c);
        cout << "Branch " << r + 1 << ": " << branchTotal << endl;
    }

    cout << "\nDay totals:" << endl;
    for (int c = 0; c < 3; c++) {
        int dayTotal = 0;
        for (int r = 0; r < 2; r++)
            dayTotal += *(*(rowPtr + r) + c);
        cout << "Day " << c + 1 << ": " << dayTotal << endl;
    }

    return 0;
}
