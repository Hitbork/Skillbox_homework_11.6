#include <iostream>

// Function to navigate on the field
char on_place(int i, int j, std::string firstStr, std::string secondStr, std::string thirdStr) {
    if (i == 0) {
        return firstStr[j];
    } else if (i == 1) {
        return secondStr[j];
    } else if (i == 2) {
        return thirdStr[j];
    }
}

// Function for returning amount of char in strings
int amount_of(char c, std::string firstStr, std::string secondStr, std::string thirdStr) {
    int counter = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (on_place(i, j, firstStr, secondStr, thirdStr) == c) {
                counter++;
            }
        }
    }

    return counter;
}

// Function for checking how much time some symbol won
int how_much_time_won(char c, std::string firstStr, std::string secondStr, std::string thirdStr) {
    int counter = 0;
    std::string checkString = std::string(3, c);

    if (firstStr == checkString) counter++;
    if (secondStr == checkString) counter++;
    if (thirdStr == checkString) counter++;

    std::string column1 = "";
    column1 += firstStr[0];
    column1 += secondStr[0];
    column1 += thirdStr[0];
    std::string column2 = "";
    column2 += firstStr[1];
    column2 += secondStr[1];
    column2 += thirdStr[1];
    std::string column3 = "";
    column3 += firstStr[2];
    column3 += secondStr[2];
    column3 += thirdStr[2];

    if (column1 == checkString) counter++;
    if (column2 == checkString) counter++;
    if (column3 == checkString) counter++;

    std::string diagonal1 = "";
    diagonal1 += firstStr[0];
    diagonal1 += secondStr[1];
    diagonal1 += thirdStr[2];
    std::string diagonal2 = "";
    diagonal2 += firstStr[2];
    diagonal2 += secondStr[1];
    diagonal2 += thirdStr[0];

    if (diagonal1 == checkString) counter++;
    if (diagonal2 == checkString) counter++;

    return counter;
}

// Function for checking correctness of field
bool is_correct(std::string firstStr, std::string secondStr, std::string thirdStr) {
    // Condition for empty field
    if (firstStr == "..." && secondStr == "..." && thirdStr == "...") {
        return false;
    }

    int timesCrossesWon = how_much_time_won('X', firstStr, secondStr, thirdStr),
        timesOsWon = how_much_time_won('O', firstStr, secondStr, thirdStr);


    if (((timesCrossesWon >= 1) && (timesOsWon >= 1)) ||
            (timesCrossesWon >= 2) ||
            (timesOsWon >= 2)) {
        return false;
    }

    // Check if crosses are more than os
    int crosses = amount_of('X', firstStr, secondStr, thirdStr),
        os = amount_of('O', firstStr, secondStr, thirdStr);

    if ((os > crosses) ||
            (crosses > os + 1) ||
            ((timesOsWon == 1) && (crosses > os)) ||
            ((timesCrossesWon == 1) && (os >= crosses)) ||
            ((crosses + os + amount_of('.', firstStr, secondStr, thirdStr)) != 9)) {
        return false;
    }

    return true;
}


// Function to output result of the game
std::string result_of_game(std::string firstStr, std::string secondStr, std::string thirdStr) {
    if (!is_correct(firstStr, secondStr, thirdStr)) {
        return "Incorrect";
    }


    int timesCrossesWon = how_much_time_won('X', firstStr, secondStr, thirdStr),
            timesOsWon = how_much_time_won('O', firstStr, secondStr, thirdStr);


    if (timesCrossesWon == 1) return "Petya won";

    if (timesOsWon == 1) return "Vanya won";

    return "Nobody";
}


int main() {
    // Greetings
    std::cout << "Result of tic-tac-toe:\n\n\n";


    // Creating vars and quering data
    std::string firstStr, secondStr, thirdStr;

    std::cout << "Input a result of game in tic-tac-toe:\n";
    std::getline(std::cin, firstStr);
    std::getline(std::cin, secondStr);
    std::getline(std::cin, thirdStr);

    std::cout << "\n";


    // Output
    std::cout << "Result of the game: " << result_of_game(firstStr, secondStr, thirdStr) << std::endl;
}
