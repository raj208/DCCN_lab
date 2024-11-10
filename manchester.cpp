#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to encode a binary message using Manchester encoding
vector<string> manchesterEncode(const string& binaryMessage) {
    vector<string> encodedSignal;

    for (char bit : binaryMessage) {
        if (bit == '0') {
            // 0 is represented by high-to-low transition (e.g., +V to -V)
            encodedSignal.push_back("+V -V");
        } else if (bit == '1') {
            // 1 is represented by low-to-high transition (e.g., -V to +V)
            encodedSignal.push_back("-V +V");
        } else {
            cerr << "Invalid character in binary message: " << bit << endl;
            exit(1);
        }
    }

    return encodedSignal;
}

int main() {
    string binaryMessage;
    cout << "Enter a binary message: ";
    cin >> binaryMessage;

    // Encode the binary message using Manchester encoding
    vector<string> encodedSignal = manchesterEncode(binaryMessage);

    // Display the encoded signal
    cout << "Manchester encoded signal: ";
    for (const string& signal : encodedSignal) {
        cout << signal << " ";
    }
    cout << endl;

    return 0;
}


// sample usage
// Enter a binary message: 1010
// Manchester encoded signal: -V +V +V -V -V +V +V -V 
