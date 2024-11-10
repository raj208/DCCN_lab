#include <iostream>
#include <string>
using namespace std;

// Function to encrypt the given text using Caesar Cipher
string encrypt(string text, int shift) {
    string result = "";

    for (int i = 0; i < text.length(); i++) {
        // Encrypt uppercase letters
        if (isupper(text[i]))
            result += char(int(text[i] + shift - 65) % 26 + 65);

        // Encrypt lowercase letters
        else if (islower(text[i]))
            result += char(int(text[i] + shift - 97) % 26 + 97);

        // Non-alphabetic characters remain the same
        else
            result += text[i];
    }
    return result;
}

// Function to decrypt the given text using Caesar Cipher
string decrypt(string text, int shift) {
    string result = "";

    for (int i = 0; i < text.length(); i++) {
        // Decrypt uppercase letters
        if (isupper(text[i]))
            result += char(int(text[i] - shift - 65 + 26) % 26 + 65);

        // Decrypt lowercase letters
        else if (islower(text[i]))
            result += char(int(text[i] - shift - 97 + 26) % 26 + 97);

        // Non-alphabetic characters remain the same
        else
            result += text[i];
    }
    return result;
}

int main() {
    string text;
    int shift;

    cout << "Enter text: ";
    getline(cin, text);
    cout << "Enter shift amount: ";
    cin >> shift;

    string encryptedText = encrypt(text, shift);
    cout << "Encrypted Text: " << encryptedText << endl;

    string decryptedText = decrypt(encryptedText, shift);
    cout << "Decrypted Text: " << decryptedText << endl;

    return 0;
}
