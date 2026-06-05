#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
	Contact contacts[8];
	int contact_count;
	int oldest_index;

public:
	PhoneBook();

	void add_contact(Contact new_contact);
	void search_contacts() const;
	void display_contact(int index) const;
};

#endif
