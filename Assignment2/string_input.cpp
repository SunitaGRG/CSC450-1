#include <iostream>
#include <string>

using namespace std;

int main() {
    string str1, str2, result;

    cout << "========================================" << endl;
    cout << "     String Concatenation Program       " << endl;
    cout << "========================================" << endl;

    for (int i = 1; i <= 3; i++) {
        cout << "\n--- Round " << i << " ---" << endl;

        cout << "Enter the first string: ";
        getline(cin, str1);

        cout << "Enter the second string: ";
        getline(cin, str2);

        result = str1 + str2;

        cout << "Concatenated Result: " << result << endl;
        cout << "Result Length: " << result.length() << " characters" << endl;
    }

    cout << "\n========================================" << endl;
    cout << "         Program Complete!              " << endl;
    cout << "========================================" << endl;

    return 0;
}
