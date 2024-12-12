#include "phonebook.hpp"
#include <cctype> 

PhoneBook::PhoneBook(): contactCount(0) {}

PhoneBook::~PhoneBook() {}

bool isNumeric(const std::string& str) {
    for (size_t i = 0; i < str.length(); i++) {
        if (!std::isdigit(str[i])) {
            return false;
        }
    }
    return !str.empty();  // Ensure input is not empty
}

std::string readNumericInput(std::string prompt) {
    std::string input;

    while (true) {
        std::cout << prompt;
        getline(std::cin, input);
        if (isNumeric(input)) {
            break;
        }
        std::cout << "Input must contain only numbers and cannot be empty. Please try again.\n";
    }
    return input;
}

std::string readInput(std::string prompt) {
	std::string input;

	while (true) {
		std::cout << prompt;
		getline(std::cin, input);
		if (!input.empty()) {
			break;  // Exit loop if input is valid
		}
		std::cout << "Input cannot be empty. Please try again.\n";
	}
	return input;
}

Contact createContact() {
	Contact contact;

	contact.setFirstName(readInput("First name: "));
	contact.setLastName(readInput("Last name: "));
	contact.setNickname(readInput("Nickname: "));
	contact.setPhoneNumber(readNumericInput("Phone number: "));
	contact.setSecret(readInput("Darkest secret: "));
	return contact;
}