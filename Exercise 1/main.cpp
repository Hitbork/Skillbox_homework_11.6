#include <iostream>

// Function of encrypting to Caesar
std::string encrypt_caesar(std::string text, int pos) {
    // Creating var to input a result
    std::string result = "";

    // Cycle for creating result
    for (int i = 0; i < text.length(); i++) {
        if ((text[i] >= 'a') && (text[i] <= 'z')) {
            result += (char) (97 + (((int)text[i] - 97 + pos) % 26));
        } else if ((text[i] >= 'A') && (text[i] <= 'Z')) {
            result += (char) (65 + (((int)text[i] - 65 + pos) % 26));
        } else {
            result += text[i];
        };
    }

    // Returning result
    return result;
}

// Function of decrypting to Caesar
std::string decrypt_caesar(std::string text, int pos) {
    return encrypt_caesar(encrypt_caesar(text, pos), 26-pos);
}


// Main function
int main() {
    // Greetings
    std::cout << "Encrypter and decrypter of Caesar...\n\n\n";


    // Creating vars and quering data
    std::string input;
    int number;

    std::cout << "Input a text to encrypt:\n";
    std::getline(std::cin, input);
    std::cout << std::endl;

    std::cout << "Input number of positions to move:";
    std::cin >> number;

    std::cout << "\n\n";


    // Output using functions
    std::cout << "Result of encrypt:\n" << encrypt_caesar(input, number) << "\n\n";
    std::cout << "Result of decrypt:\n" << decrypt_caesar(input, number) << "\n\n";
}
