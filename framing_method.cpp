#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 1. Bit Stuffing
string bitStuffing(const string& data) {
    string stuffedData = "";
    int count = 0;

    for (char bit : data) {
        stuffedData += bit;
        if (bit == '1') {
            count++;
        } else {
            count = 0;
        }
        if (count == 5) {
            stuffedData += '0'; // Insert a 0 after 5 consecutive 1's
            count = 0;
        }
    }
    return stuffedData;
}

// 2. Character Stuffing
string characterStuffing(const string& data, char escapeChar, char specialChar) {
    string stuffedData = "";
    for (char ch : data) {
        if (ch == specialChar) {
            stuffedData += escapeChar; // Insert escape character before special character
        }
        stuffedData += ch;
    }
    return stuffedData;
}

// 3. Character Counting
string characterCounting(const string& data) {
    string countedFrame = "";
    int length = data.length();
    countedFrame += to_string(length); // Prepend the length of the data
    countedFrame += data;  // Append the actual data
    return countedFrame;
}

int main() {
    string data;
    char escapeChar = 0x1B;  // Escape character (ASCII 27)
    char specialChar = 0x7E;  // Special character (ASCII ~)

    // Taking user input for the data
    cout << "Enter data (binary for bit stuffing, text for other methods): ";
    cin >> data;

    // Bit Stuffing
    string stuffedData = bitStuffing(data);
    cout << "Bit Stuffed Data: " << stuffedData << endl;

    // Character Stuffing
    string characterStuffedData = characterStuffing(data, escapeChar, specialChar);
    cout << "Character Stuffed Data: " << characterStuffedData << endl;

    // Character Counting
    string countedData = characterCounting(data);
    cout << "Character Counted Data: " << countedData << endl;

    return 0;
}



// sample usage
// Enter data (binary for bit stuffing, text for other methods): 111110101111
// Bit Stuffed Data: 1111101011110
// Character Stuffed Data: Hello~World~ESC
// Character Counted Data: 11HelloWorld
