#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to encode a binary message using bipolar AMI
vector<int> encodeBipolarAMI(const string& binaryMessage) {
    vector<int> encodedSignal;
    bool isPositive = true;  // To alternate between +V and -V

    for (char bit : binaryMessage) {
        if (bit == '0') {
            encodedSignal.push_back(0);  // '0' is represented by 0V
        } else if (bit == '1') {
            if (isPositive) {
                encodedSignal.push_back(1);  // '1' represented by +V
            } else {
                encodedSignal.push_back(-1);  // '1' represented by -V
            }
            isPositive = !isPositive;  // Alternate for the next '1'
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

    // Encode the binary message using bipolar AMI
    vector<int> encodedSignal = encodeBipolarAMI(binaryMessage);

    // Display the encoded signal
    cout << "Encoded signal using bipolar AMI: ";
    for (int signal : encodedSignal) {
        if (signal == 1) {
            cout << "+V ";
        } else if (signal == -1) {
            cout << "-V ";
        } else {
            cout << "0 ";
        }
    }
    cout << endl;

    return 0;
}


//sample usage
// Enter a binary message: 110100
// Encoded signal using bipolar AMI: +V -V 0 +V 0 0 
