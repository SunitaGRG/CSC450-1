#include <iostream>
#include <string>

using namespace std;

int main() {
    string str1, str2, result;

    cout << "========================================" << endl;
    cout << "     String Concatenation Program       " << endl;
    cout << "========================================" << endl;

    // Loop runs 3 times to take input and display result
    for (int i = 1; i <= 3; i++) {
        cout << "\n--- Round " << i << " ---" << endl;

        // Take first string input
        cout << "Enter the first string: ";
        getline(cin, str1);

        // Take second string input
        cout << "Enter the second string: ";
        getline(cin, str2);

        // Combine both strings
        result = str1 + str2;

        // Display the concatenated result
        cout << "Concatenated Result: " << result << endl;
        cout << "Result Length: " << result.length() << " characters" << endl;
    }

    cout << "\n========================================" << endl;
    cout << "         Program Complete!              " << endl;
    cout << "========================================" << endl;

    return 0;
}
