#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : contact_count(0), oldest_index(0) {
}

void PhoneBook::add_contact(Contact new_contact) {
	contacts[oldest_index] = new_contact;
	oldest_index = (oldest_index + 1) % 8;
	if (contact_count < 8)
		contact_count++;
}

static std::string truncate(std::string str) {
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

void PhoneBook::search_contacts() const {
	if (contact_count == 0) {
		std::cout << "No contacts in phonebook." << std::endl;
		return;
	}

	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;

	for (int i = 0; i < contact_count; i++) {
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << truncate(contacts[i].get_first_name()) << "|";
		std::cout << std::setw(10) << truncate(contacts[i].get_last_name()) << "|";
		std::cout << std::setw(10) << truncate(contacts[i].get_nickname()) << std::endl;
	}
}

void PhoneBook::display_contact(int index) const {
	if (index < 0 || index >= contact_count) {
		std::cout << "Invalid index." << std::endl;
		return;
	}

	std::cout << "First Name: " << contacts[index].get_first_name() << std::endl;
	std::cout << "Last Name: " << contacts[index].get_last_name() << std::endl;
	std::cout << "Nickname: " << contacts[index].get_nickname() << std::endl;
	std::cout << "Phone Number: " << contacts[index].get_phone_number() << std::endl;
	std::cout << "Darkest Secret: " << contacts[index].get_darkest_secret() << std::endl;
}
