#include <iostream>
using namespace std;

// defining the student class as requested above main
class Student {
public:
    int rollNumber;
    int marks;

    // public member function to print the values with labels on separate lines
    void display() {
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Marks: " << marks << endl;
    }
};

int main() {
    // creating s1 and s2 objects
    Student s1, s2;

    // assigning values to s1 using the dot operator
    s1.rollNumber = 1;
    s1.marks = 75;

    // assigning values to s2 using the dot operator
    s2.rollNumber = 2;
    s2.marks = 90;

    // displaying the starting values
    cout << "--- Before any changes ---" << endl;
    cout << "For s1:" << endl;
    s1.display();
    
    cout << "\nFor s2:" << endl;
    s2.display();

    // changing only s1's marks to 80 like the lab manual said
    s1.marks = 80;

    // displaying both again to check if s2 got affected
    cout << "\n--- After changing s1.marks to 80 ---" << endl;
    cout << "For s1:" << endl;
    s1.display();
    
    cout << "\nFor s2 (should remain the same since objects have separate memory copies):" << endl;
    s2.display();

    return 0;
}