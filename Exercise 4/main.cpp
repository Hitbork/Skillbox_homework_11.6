#include <iostream>

int main() {
    // Greetings
    std::cout << "Result of tic-tac-toe:\n\n\n";


    // Creating vars and quering data
    std::string firstStr, secondStr, thirdStr;

    std::cout << "Input a result of game in tic-tac-toe: ";
    std::getline(std::cin, firstStr);
    std::getline(std::cin, secondStr);
    std::getline(std::cin, thirdStr);

    std::cout << "\n";
}
