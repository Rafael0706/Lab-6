/*
Rafael Gallegos Cespedes
Computer Science Fall 2024
Due: Dec. 3, 2024
Lab 6 Binary to Decimal Conversion
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

// Function to check if a string contains only binary digits (0 and 1)
bool isValidBinary(const string& binary) {
    for (char c : binary) {
        if (c != '0' && c != '1') {
            return false;
        }
    }
    return true;
}

// Function to convert a binary string to a decimal integer
int binaryToDecimal(const string& binary) {
    int decimal = 0;
    for (char c : binary) {
        decimal = decimal * 2 + (c - '0');
    }
    return decimal;
}

int main() {
    ifstream inputFile("BinaryIn.dat");
    if (!inputFile) {
        cerr << "Error: Unable to open file BinaryIn.dat" << endl;
        return 1;
    }

    cout << "Binary Number\tDecimal Equivalent" << endl;

    string line;
    while (getline(inputFile, line)) {
        // Remove leading spaces
        size_t start = line.find_first_not_of(" ");
        if (start == string::npos) {
            continue; // Skip empty lines
        }
        line = line.substr(start);

        // Remove spaces between binary digits
        string binaryNumber;
        bool badInput = false;

        for (size_t i = 0; i < line.length(); ++i) {
            if (line[i] == ' ') {
                // Check for consecutive spaces
                if (i + 1 < line.length() && line[i + 1] == ' ') {
                    badInput = true;
                    break;
                }
                continue;
            }
            if (line[i] == '0' || line[i] == '1') {
                binaryNumber += line[i];
            }
            else {
                badInput = true;
                break;
            }
        }

        if (badInput) {
            cout << line << "\tBad digit on input" << endl;
        }
        else if (!isValidBinary(binaryNumber)) {
            cout << line << "\tBad digit on input" << endl;
        }
        else {
            int decimalEquivalent = binaryToDecimal(binaryNumber);
            cout << binaryNumber << "\t" << decimalEquivalent << endl;
        }
    }

    inputFile.close();
    return 0;
}
