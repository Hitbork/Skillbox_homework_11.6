#include <iostream>

// Function to check if mailbox correct
bool is_correct_mail(std::string str) {
    // Condition for amount of "@"
    if (!((str.find("@") != str.rfind("@")) && (str.find("@") != -1))) {
        return false;
    }

    // Condition for length
    int posDog = str.find("@");
    std::string firstPart = str.substr(0, posDog),
        secondPart = str.substr(posDog+1, str.length());

    if (!(((firstPart.length() >= 1) && (firstPart.length() <= 64)) &&
        ((secondPart.length() >= 1) && (secondPart.length() <= 63)))) {
        return false;
    }

    // Condition for chars
}

int main() {
    // Greetings
    std::cout << "Is mail box name correct?\n\n\n";


    // Creating vars and quering data
    std::string str;

    std::cout << "Input mail box:\n";
    std::cin >> str;


    // Output
    std::cout << (is_correct_mail(str)) ? "Yes" : "No";
}
