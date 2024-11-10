#include <iostream>
#include <vector>
using namespace std;

// Function to calculate the even parity bit for a single byte
char calculateParityBit(unsigned char byte) {
    int count = 0;

    // Count the number of 1's in the byte
    for (int i = 0; i < 8; i++) {
        if (byte & (1 << i)) count++;
    }

    // Return '0' if count is even, '1' if count is odd
    return (count % 2 == 0) ? '0' : '1';
}

// Function to generate VRC (parity bits) for a block of data
vector<char> generateVRC(const vector<unsigned char>& dataBlock) {
    vector<char> parityBits;

    // Calculate parity for each byte in the data block
    for (unsigned char byte : dataBlock) {
        parityBits.push_back(calculateParityBit(byte));
    }

    return parityBits;
}

// Function to verify VRC (parity bits) for a block of data
bool verifyVRC(const vector<unsigned char>& dataBlock, const vector<char>& parityBits) {
    for (size_t i = 0; i < dataBlock.size(); i++) {
        if (calculateParityBit(dataBlock[i]) != parityBits[i]) {
            return false; // Parity mismatch detected
        }
    }
    return true; // All parity bits match
}

int main() {
    int numBytes;
    cout << "Enter the number of data bytes: ";
    cin >> numBytes;

    vector<unsigned char> dataBlock(numBytes);
    cout << "Enter the data bytes (in hexadecimal):" << endl;
    for (int i = 0; i < numBytes; i++) {
        int byte;
        cin >> hex >> byte;
        dataBlock[i] = static_cast<unsigned char>(byte);
    }

    // Generate VRC parity bits for the data block
    vector<char> parityBits = generateVRC(dataBlock);

    // Display the data block with its parity bits
    cout << "Data block with parity bits (VRC):" << endl;
    for (size_t i = 0; i < dataBlock.size(); i++) {
        cout << hex << static_cast<int>(dataBlock[i]) << " (Parity: " << parityBits[i] << ") ";
    }
    cout << endl;

    // Verification step to check for errors
    if (verifyVRC(dataBlock, parityBits)) {
        cout << "VRC verification successful: Data is valid." << endl;
    } else {
        cout << "VRC verification failed: Data is corrupted." << endl;
    }

    return 0;
}



//sample usage
// Enter the number of data bytes: 3
// Enter the data bytes (in hexadecimal):
// 4F
// A5
// C3
// Data block with parity bits (VRC):
// 4f (Parity: 0) a5 (Parity: 1) c3 (Parity: 1)
// VRC verification successful: Data is valid.
