#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    cout << "Enter number of students (rows, 1-10): ";
    cin >> rows;
    cout << "Enter number of subjects (cols, 1-10): ";
    cin >> cols;

    if (rows < 1 || rows > 10 || cols < 1 || cols > 10) {
        cout << "Error: rows and cols must be between 1 and 10." << endl;
        return 0;
    }

    int** marks = new int*[rows];
    for (int r = 0; r < rows; r++)
        marks[r] = new int[cols];

    for (int r = 0; r < rows; r++) {
        cout << "Student " << r + 1 << ":" << endl;
        for (int c = 0; c < cols; c++) {
            cout << "  Subject " << c + 1 << ": ";
            cin >> *(*(marks + r) + c);
        }
    }

    cout << "\nMarks matrix:" << endl;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++)
            cout << *(*(marks + r) + c) << " ";
        cout << endl;
    }

    int bestTotal = 0;
    int bestStudent = 1;

    cout << "\nStudent totals:" << endl;
    for (int r = 0; r < rows; r++) {
        int total = 0;
        for (int c = 0; c < cols; c++)
            total += marks[r][c];
        cout << "Student " << r + 1 << ": " << total << endl;

        if (r == 0 || total > bestTotal) {
            bestTotal = total;
            bestStudent = r + 1;
        }
    }

    cout << "\nTop student: " << bestStudent << " with total " << bestTotal << endl;

    for (int r = 0; r < rows; r++)
        delete[] marks[r];
    delete[] marks;
    marks = nullptr;

    return 0;
}
