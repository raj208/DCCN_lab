#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Function to calculate the checksum for a given data
uint16_t calculateChecksum(const vector<uint16_t>& data) {
    uint32_t sum = 0;

    // Sum all 16-bit words
    for (uint16_t word : data) {
        sum += word;

        // If overflow occurs, wrap around by adding the overflow bit
        if (sum > 0xFFFF) {
            sum = (sum & 0xFFFF) + 1;
        }
    }

    // Complement the sum to get the checksum
    uint16_t checksum = ~sum & 0xFFFF;
    return checksum;
}

// Function to verify the checksum by adding all words, including the checksum itself
bool verifyChecksum(const vector<uint16_t>& data, uint16_t checksum) {
    uint32_t sum = 0;

    // Sum all 16-bit words and the received checksum
    for (uint16_t word : data) {
        sum += word;
        if (sum > 0xFFFF) {
            sum = (sum & 0xFFFF) + 1;
        }
    }

    sum += checksum;
    if (sum > 0xFFFF) {
        sum = (sum & 0xFFFF) + 1;
    }

    // Valid if the final sum is 0xFFFF (all 1s in binary)
    return (sum == 0xFFFF);
}

int main() {
    int n;
    cout << "Enter the number of 16-bit data words: ";
    cin >> n;

    vector<uint16_t> data(n);
    cout << "Enter the data words (in hexadecimal, e.g., FFFF):" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Word " << i + 1 << ": ";
        cin >> hex >> data[i];
    }

    // Calculate checksum
    uint16_t checksum = calculateChecksum(data);
    cout << "Calculated checksum: " << hex << setw(4) << setfill('0') << uppercase << checksum << endl;

    // Verification step (simulating receiver side)
    cout << "Enter received data words (in hexadecimal, including the checksum):" << endl;
    vector<uint16_t> receivedData(n + 1);
    for (int i = 0; i < n + 1; ++i) {
        cout << "Word " << i + 1 << ": ";
        cin >> hex >> receivedData[i];
    }

    uint16_t receivedChecksum = receivedData.back();
    receivedData.pop_back(); // Remove the checksum for verification

    if (verifyChecksum(receivedData, receivedChecksum)) {
        cout << "No error detected. Data is valid." << endl;
    } else {
        cout << "Error detected in received data." << endl;
    }

    return 0;


// sample usage
// Enter the number of 16-bit data words: 3
// Enter the data words (in hexadecimal, e.g., FFFF):
// Word 1: 1234
// Word 2: ABCD
// Word 3: 5678
// Calculated checksum: 9756

// Enter received data words (in hexadecimal, including the checksum):
// Word 1: 1234
// Word 2: ABCD
// Word 3: 5678
// Word 4: 9756
// No error detected. Data is valid.
