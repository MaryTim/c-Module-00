#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"
#include <iostream>
#include <string>

class PhoneBook {
	public:
		PhoneBook();
		~PhoneBook();

		void add();
		void search();
		void exit();
	private:
		Contact contacts[8];
		int contactCount;
};

#endif