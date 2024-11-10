#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to encode a binary message using Differential Manchester encoding
vector<string> differentialManchesterEncode(const string& binaryMessage) {
    vector<string> encodedSignal;
    bool currentState = true;  // Initial state, true represents +V and false represents -V

    for (char bit : binaryMessage) {
        if (bit == '0') {
            // 0: Transition at the start, followed by a mid-bit transition
            currentState = !currentState;  // Transition at the start
            encodedSignal.push_back(currentState ? "+V -V" : "-V +V");
        } else if (bit == '1') {
            // 1: No transition at the start, only a mid-bit transition
            encodedSignal.push_back(currentState ? "+V -V" : "-V +V");
        } else {
            cerr << "Invalid character in binary message: " << bit << endl;
            exit(1);
        }
        currentState = !currentState;  // Always a transition in the middle
    }

    return encodedSignal;
}

int main() {
    string binaryMessage;
    cout << "Enter a binary message: ";
    cin >> binaryMessage;

    // Encode the binary message using Differential Manchester encoding
    vector<string> encodedSignal = differentialManchesterEncode(binaryMessage);

    // Display the encoded signal
    cout << "Differential Manchester encoded signal: ";
    for (const string& signal : encodedSignal) {
        cout << signal << " ";
    }
    cout << endl;

    return 0;
}


// sample usage
// Enter a binary message: 1010
// Differential Manchester encoded signal: +V -V -V +V +V -V -V +V 
