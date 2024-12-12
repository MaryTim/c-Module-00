#include "phonebook.hpp"

int main() {
    PhoneBook phonebook;

    std::cout << phonebook.createContact().getFirstName() << std::endl;
}