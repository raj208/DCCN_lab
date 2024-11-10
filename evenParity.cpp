#include <iostream>
#include <string>
using namespace std;

// Function to calculate even parity bit for a given binary string
char calculateEvenParity(const string& binaryString) {
    int count = 0;

    // Count the number of 1's in the binary string
    for (char bit : binaryString) {
        if (bit == '1') count++;
    }

    // If the count of 1's is even, parity bit is 0; if odd, parity bit is 1
    return (count % 2 == 0) ? '0' : '1';
}

// Function to append the even parity bit to the binary string
string addParityBit(const string& binaryString) {
    char parityBit = calculateEvenParity(binaryString);
    return binaryString + parityBit;
}

int main() {
    string binaryString;

    cout << "Enter a binary string: ";
    cin >> binaryString;

    string binaryWithParity = addParityBit(binaryString);
    cout << "Binary string with even parity bit: " << binaryWithParity << endl;

    return 0;
}
