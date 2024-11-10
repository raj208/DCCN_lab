#include <iostream>
#include <vector>
using namespace std;

// Function to calculate the LRC for a block of data
unsigned char calculateLRC(const vector<unsigned char>& dataBlock) {
    unsigned char lrc = 0;

    // XOR each byte in the data block to get the LRC
    for (unsigned char byte : dataBlock) {
        lrc ^= byte;
    }

    return lrc;
}

// Function to verify the LRC for a block of data (including LRC byte)
bool verifyLRC(const vector<unsigned char>& dataBlockWithLRC) {
    unsigned char lrc = 0;

    // XOR each byte in the data block including LRC byte
    for (unsigned char byte : dataBlockWithLRC) {
        lrc ^= byte;
    }

    // If result is 0, data is valid; otherwise, there's an error
    return lrc == 0;
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

    // Calculate LRC and add it to the data block
    unsigned char lrc = calculateLRC(dataBlock);
    dataBlock.push_back(lrc);

    cout << "Data block with LRC byte: ";
    for (unsigned char byte : dataBlock) {
        cout << hex << static_cast<int>(byte) << " ";
    }
    cout << endl;

    // Verification step (optional, to demonstrate error-checking)
    if (verifyLRC(dataBlock)) {
        cout << "LRC verification successful: Data is valid." << endl;
    } else {
        cout << "LRC verification failed: Data is corrupted." << endl;
    }

    return 0;
}



//sample usage
// Enter the number of data bytes: 4
// Enter the data bytes (in hexadecimal):
// 12
// 34
// 56
// 78
// Data block with LRC byte: 12 34 56 78 0x12
// LRC verification successful: Data is valid.
