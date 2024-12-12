#include "contact.hpp"

Contact::Contact() {
	firstName = "";
	lastName = "";
	nickname = "";
	phoneNumber = "";
	secret = "";
}

Contact::~Contact() {}

std::string Contact::getFirstName() {
	return firstName;
}

std::string Contact::getLastName() {
	return lastName;
}

std::string Contact::getNickname() {
	return nickname;
}

std::string Contact::getPhoneNumber() {
	return phoneNumber;
}

std::string Contact::getSecret() {
	return secret;
}

void Contact::setFirstName(std::string firstName) {
	this->firstName = firstName;
}

void Contact::setLastName(std::string lastName) {
	this->lastName = lastName;
}

void Contact::setNickname(std::string nickname) {
	this->nickname = nickname;
}

void Contact::setPhoneNumber(std::string phoneNumber) {
	this->phoneNumber = phoneNumber;
}

void Contact::setSecret(std::string secret) {
	this->secret = secret;
}