#include <iostream>

// Function to check default chars
bool is_ok_default_chars(std::string text, int index) {
    if (!((text[index] >= 'a' && text[index] <= 'z') ||
          (text[index] >= 'A' && text[index] <= 'Z') ||
          (text[index] >= '1' && text[index] <= '9') ||
          (text[index] == '-') ||
          (text[index] == '.' && (index >= 1 && index <= text.length()-2) &&
          ((index == text.length() - 2) ||
          ((index <= text.length() - 3) && (text[index + 1] != '.')))))) {
        return false;
    }

    return true;
}

// Function to check additional chars
bool is_ok_additional_chars(char c) {
    if ((c == '!') ||
        ((c >= '#') && (c <= '\'')) ||
        ((c >= '*') && (c <= '+')) ||
        (c == '-') ||
        (c == '/') ||
        (c == '=') ||
        (c == '?') ||
        (c == '^') ||
        (c == '_') ||
        (c == '`') ||
        ((c >= '{') && (c <= '~'))) {
        return true;
    }

    return false;
}

// Function to check if mailbox correct
bool is_correct_mail(std::string str) {
    // Condition for amount of "@"
    if (!((str.find("@") == str.rfind("@")) && (str.find("@") != -1))) {
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

    // Conditions for chars
    for (int i = 0; i < firstPart.length(); i++) {
        if (!((is_ok_default_chars(firstPart, i)) ||
            (is_ok_additional_chars(firstPart[i])))) {
            return false;
        }
    }

    for (int i = 0; i < secondPart.length(); i++) {
        if (!is_ok_default_chars(secondPart, i)) {
            return false;
        }
    }

    return true;
}

int main() {
    // Greetings
    std::cout << "Is mail box name correct?\n\n\n";


    // Creating vars and quering data
    std::string str;

    std::cout << "Input name of mail box:\n";
    std::cin >> str;

    std::cout << "\n";

    // Output
    if (is_correct_mail(str)) {
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
    }
    std::cout << (is_correct_mail(str)) ? "Yes" : "No";
}
