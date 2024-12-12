#include "phonebook.hpp"

PhoneBook::PhoneBook(): contactCount(0) {}

PhoneBook::~PhoneBook() {}

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

Contact PhoneBook::createContact() {
	Contact contact;

	contact.setFirstName(readInput("First name: "));
	contact.setLastName(readInput("Last name: "));
	contact.setNickname(readInput("Nickname: "));
	contact.setPhoneNumber(readInput("Phone number: "));
	contact.setSecret(readInput("Darkest secret: "));
	return contact;
}