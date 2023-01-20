#include <iostream>

// Function to check if IP address is correct
bool is_correct_IP(std::string IP) {
    // Check if all chars are dots or digits
    for (int i = 0; i < IP.length(); i++) {
        if (!((IP[i] == '.') ||
            (isdigit(IP[i])))) {
            return false;
        }
    }

    // Dividing IP by dots
    int counter = 0;
    std::string temp;
    int number;
    while ((IP.find('.') != -1) && (counter < 3)) {
        temp = IP.substr(0, IP.find('.'));
        IP.erase(0, IP.find('.')+1);
        number = atoi(temp.c_str());
        if (!((number >= 0 && number <= 255) &&
              (std::to_string(number).length() == temp.length()))) {
            return false;
        }

        counter++;
    }

    if (IP.find('.') != -1) {
        return false;
    }

    number = atof(IP.c_str());

    if (!(number >= 0 && number <= 255)) {
        return false;
    }

    return true;
}


int main() {
    // Greetings
    std::cout << "Validation of IP-address\n\n\n";


    // Creating vars and quering data
    std::string IPAddress;

    std::cout << "Input IP-address:\n";
    std::cin >> IPAddress;

    std::cout << "\n";


    // Output
    if (is_correct_IP(IPAddress)) {
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
    }
}
