/*
 * Integer Pointers Program
 * This program takes three integers from the user,
 * stores them using pointers with dynamic memory,
 * and displays their values.
 */

#include <iostream>
using namespace std;

int main() {

    // Step 1: Declare three integer variables
    int val1, val2, val3;

    // Step 2: Get three integer values from the user
    cout << "=== Integer Pointers Program ===" << endl;
    cout << endl;

    cout << "Enter integer value #1: ";
    cin >> val1;

    cout << "Enter integer value #2: ";
    cin >> val2;

    cout << "Enter integer value #3: ";
    cin >> val3;

    // Step 3: Allocate dynamic memory for each pointer
    //         using the 'new' operator, then copy values in
    int* ptr1 = new int(val1);
    int* ptr2 = new int(val2);
    int* ptr3 = new int(val3);

    // Step 4: Display variable contents and pointer info
    cout << endl;
    cout << "============================================" << endl;
    cout << "         Variable & Pointer Details         " << endl;
    cout << "============================================" << endl;

    // Variable 1
    cout << endl;
    cout << "[ Variable 1 ]" << endl;
    cout << "  Value (variable) : " << val1  << endl;
    cout << "  Pointer (ptr1)   : " << ptr1  << "  (address of dynamic memory)" << endl;
    cout << "  *ptr1 (deref)    : " << *ptr1 << endl;

    // Variable 2
    cout << endl;
    cout << "[ Variable 2 ]" << endl;
    cout << "  Value (variable) : " << val2  << endl;
    cout << "  Pointer (ptr2)   : " << ptr2  << "  (address of dynamic memory)" << endl;
    cout << "  *ptr2 (deref)    : " << *ptr2 << endl;

    // Variable 3
    cout << endl;
    cout << "[ Variable 3 ]" << endl;
    cout << "  Value (variable) : " << val3  << endl;
    cout << "  Pointer (ptr3)   : " << ptr3  << "  (address of dynamic memory)" << endl;
    cout << "  *ptr3 (deref)    : " << *ptr3 << endl;

    // Step 5: Release dynamic memory using the 'delete' operator
    //         and set pointers to nullptr to avoid dangling pointers
    delete ptr1;
    delete ptr2;
    delete ptr3;

    ptr1 = nullptr;
    ptr2 = nullptr;
    ptr3 = nullptr;

    cout << endl;
    cout << "============================================" << endl;
    cout << "Memory released and pointers reset."        << endl;
    cout << "============================================" << endl;

    return 0;
}
