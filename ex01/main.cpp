#include "phonebook.hpp"

int main() {
    PhoneBook phonebook;
	std::string command;

	std::cout << "---> PhoneBook <---" << std::endl;
	while (1) {
		std::cout << "Enter a command: ADD, SEARCH, EXIT: ";
		std::getline(std::cin, command);
		if (command == "ADD") {
			phonebook.add();
		} else if (command == "SEARCH") {
			phonebook.search();
		} else if (command == "EXIT") {
			phonebook.exit();
		} else {
			std::cout << command << "\nPlease enter a valid command!" << std::endl;
		}
	}
	return 0;
}