/*
 * CSC450 - Critical Thinking 5 (Module 5)
 * Program: File I/O with String Reversal
 *
 * Description:
 *   - Prompts the user to enter text
 *   - Appends the input to CSC450_CT5_mod5.txt (preserving existing content)
 *   - Reads the entire file and writes a character-reversed copy
 *     to CSC450-mod5-reverse.txt
 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

// ---------------------------------------------------------------------------
// appendToFile
//   Opens 'filename' in append mode and writes 'text' followed by a newline.
//   Returns true on success, false if the file could not be opened.
// ---------------------------------------------------------------------------
bool appendToFile(const std::string& filename, const std::string& text) {
    std::ofstream outFile(filename, std::ios::app);   // append mode
    if (!outFile.is_open()) {
        std::cerr << "Error: Could not open \"" << filename << "\" for appending.\n";
        return false;
    }
    outFile << text << "\n";
    return true;
}

// ---------------------------------------------------------------------------
// reverseFile
//   Reads every character from 'inputFilename', reverses the entire sequence,
//   and writes the result to 'outputFilename'.
//   Returns true on success, false if either file could not be opened.
// ---------------------------------------------------------------------------
bool reverseFile(const std::string& inputFilename,
                 const std::string& outputFilename) {
    // --- Read the full content of the source file ---
    std::ifstream inFile(inputFilename);
    if (!inFile.is_open()) {
        std::cerr << "Error: Could not open \"" << inputFilename << "\" for reading.\n";
        return false;
    }

    // Read all characters (including newlines) into a string
    std::string content, line;

    while (getline(inFile, line)) {
        content += line + "\n";
    }

    inFile.close();

    // --- Reverse the entire character sequence ---
    std::string reversed = content;
    std::reverse(reversed.begin(), reversed.end());

    // --- Write the reversed content to the output file ---
    std::ofstream outFile(outputFilename);   // overwrite / create
    if (!outFile.is_open()) {
        std::cerr << "Error: Could not open \"" << outputFilename << "\" for writing.\n";
        return false;
    }
    outFile << reversed;
    return true;
}

// main
int main() {
    const std::string SOURCE_FILE  = "CSC450_CT5_mod5.txt";
    const std::string REVERSE_FILE = "CSC450-mod5-reverse.txt";

    // ---- Step 1: Get input from the user ----
    std::cout << "========================================\n";
    std::cout << "  CSC450 Module 5 - File I/O Program\n";
    std::cout << "========================================\n\n";

    std::string userInput;
    std::cout << "Enter the text to append to " << SOURCE_FILE << ":\n> ";
    std::getline(std::cin, userInput);

    // ---- Step 2: Append user input to the source file ----
    if (!appendToFile(SOURCE_FILE, userInput)) {
        return 1;   // exit on file error
    }
    std::cout << "\nText has been appended to \"" << SOURCE_FILE << "\".\n";

    // ---- Step 3: Reverse the full file and write to the reverse file ----
    if (!reverseFile(SOURCE_FILE, REVERSE_FILE)) {
        return 1;   // exit on file error
    }
    std::cout << "Reversed content written to \"" << REVERSE_FILE << "\".\n\n";

    std::cout << "Program complete. Both files have been updated.\n";
    return 0;
}
