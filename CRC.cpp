#include <iostream>
#include <string>
using namespace std;

// Function to perform XOR operation on two binary strings
string xorOperation(const string& a, const string& b) {
    string result = "";
    for (size_t i = 1; i < b.size(); i++) {
        result += (a[i] == b[i]) ? '0' : '1';
    }
    return result;
}

// Function to perform CRC division (mod-2 division)
string mod2Division(string dividend, const string& divisor) {
    int divisorLength = divisor.size();
    string remainder = dividend.substr(0, divisorLength);

    while (divisorLength < dividend.size()) {
        if (remainder[0] == '1') {
            remainder = xorOperation(remainder, divisor) + dividend[divisorLength];
        } else {
            remainder = xorOperation(remainder, string(divisorLength, '0')) + dividend[divisorLength];
        }
        divisorLength++;
    }

    // Perform XOR for the last bits
    if (remainder[0] == '1') {
        remainder = xorOperation(remainder, divisor);
    } else {
        remainder = xorOperation(remainder, string(divisor.size(), '0'));
    }

    return remainder;
}

// Function to encode a message using CRC
string encodeCRC(const string& data, const string& generator) {
    int generatorLength = generator.size();
    string appendedData = data + string(generatorLength - 1, '0');
    string remainder = mod2Division(appendedData, generator);
    return data + remainder;  // Append remainder (CRC) to original data
}

// Function to verify the CRC-encoded message
bool verifyCRC(const string& receivedData, const string& generator) {
    string remainder = mod2Division(receivedData, generator);
    return remainder == string(generator.size() - 1, '0');
}

int main() {
    string data;
    string generator;

    cout << "Enter the data bits: ";
    cin >> data;

    cout << "Enter the generator polynomial bits: ";
    cin >> generator;

    // Encode data using CRC
    string encodedData = encodeCRC(data, generator);
    cout << "Encoded data with CRC: " << encodedData << endl;

    // Verification step (simulating receiver side)
    cout << "Enter received data for verification: ";
    string receivedData;
    cin >> receivedData;

    if (verifyCRC(receivedData, generator)) {
        cout << "No error detected. Data is valid." << endl;
    } else {
        cout << "Error detected in received data." << endl;
    }

    return 0;
}


// sample usage
// Enter the data bits: 1101011011
// Enter the generator polynomial bits: 10011
// Encoded data with CRC: 11010110111110
// Enter received data for verification: 11010110111110
// No error detected. Data is valid.
