#include "phonebook.hpp"
#include <cctype> 
#include <iomanip>
#include <cstdlib>

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

std::string truncateStr(std::string str) {
	if (str.size() <= 10)
		return str;
	else
		return str.substr(0, 9) + '.';
}

void PhoneBook::add() {
	if (contactCount == 8) {
		std::cout << "Phone book is full! The oldest contact will be overwritten!" << std::endl;
		contactCount = 0;
	}
	contacts[contactCount] = createContact();
	contactCount++;
}

void printContacts(Contact contacts[]) {
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	   for (int i = 0; i < 8; i++) {
        std::cout << "|";
        std::cout << std::setw(10) << i << "|";
        std::cout << std::setw(10) << truncateStr(contacts[i].getFirstName()) << "|";
        std::cout << std::setw(10) << truncateStr(contacts[i].getLastName()) << "|";
        std::cout << std::setw(10) << truncateStr(contacts[i].getNickname()) << "|"
                  << std::endl;
    }
	// for (int i = 0; !contacts[i].getFirstName().empty(); i++) {
	// 	std::cout.width(1);
	// 	std::cout << "|";
	// 	std::cout.width(10);
	// 	std::cout << i;
	// 	std::cout.width(1);
	// 	std::cout << "|";
	// 	std::cout.width(10);
	// 	std::cout << truncateStr(contacts[i].getFirstName());
	// 	std::cout.width(1);
	// 	std::cout << "|";
	// 	std::cout.width(10);
	// 	std::cout << truncateStr(contacts[i].getLastName());
	// 	std::cout.width(1);
	// 	std::cout << "|";
	// 	std::cout.width(10);
	// 	std::cout << truncateStr(contacts[i].getNickname());
	// 	std::cout.width(1);
	// 	std::cout << "|" << std::endl;
	// }
}

void printDetails(Contact contact) {
	if (contact.getFirstName().empty())
	{
		std::cout << "Info is not available with this index, try a different one from 0 to 7!" << std::endl;
		return ;
	}
	std::cout << "First name: " << contact.getFirstName() << std::endl;
	std::cout << "Last name: " << contact.getLastName() << std::endl;
	std::cout << "Nickname: " << contact.getNickname() << std::endl;
	std::cout << "Phone number: " << contact.getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << contact.getSecret() << std::endl;
}

void PhoneBook::search() {
	std::string input;

	printContacts(contacts);
	std::cout << "Pick index of a contact you want to see: ";
	getline(std::cin, input);
	int number = std::atoi(input.c_str());
	if (number >= 0 && number <= 7)
		printDetails(contacts[number]);
	else
		std::cout << "Invalid index!" << std::endl;
}

void PhoneBook::exit() {
	std::cout << "BYYYYYYEEEEEEE!!!!!!" << std::endl;
	::exit(0);
}