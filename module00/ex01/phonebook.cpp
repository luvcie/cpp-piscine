#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <sstream>

static Contact create_contact() {
	Contact contact;
	std::string input;

	std::cout << "Enter first name: ";
	std::getline(std::cin, input);
	contact.set_first_name(input);

	std::cout << "Enter last name: ";
	std::getline(std::cin, input);
	contact.set_last_name(input);

	std::cout << "Enter nickname: ";
	std::getline(std::cin, input);
	contact.set_nickname(input);

	std::cout << "Enter phone number: ";
	std::getline(std::cin, input);
	contact.set_phone_number(input);

	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, input);
	contact.set_darkest_secret(input);

	return contact;
}

static void handle_add(PhoneBook &phonebook) {
	Contact new_contact = create_contact();
	phonebook.add_contact(new_contact);
	std::cout << "Contact added successfully." << std::endl;
}

static void handle_search(const PhoneBook &phonebook) {
	phonebook.search_contacts();

	std::cout << "Enter index to display: ";
	std::string input;
	std::getline(std::cin, input);

	std::istringstream iss(input);
	int index;
	iss >> index;
	phonebook.display_contact(index);
}

int main() {
	PhoneBook phonebook;
	std::string command;

	while (true) {
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);

		if (command == "ADD") {
			handle_add(phonebook);
		} else if (command == "SEARCH") {
			handle_search(phonebook);
		} else if (command == "EXIT") {
			break;
		}
	}

	return 0;
}
