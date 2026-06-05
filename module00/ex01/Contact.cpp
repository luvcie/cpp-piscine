#include "Contact.hpp"

Contact::Contact() {
}

void Contact::set_first_name(std::string name) {
	first_name = name;
}

void Contact::set_last_name(std::string name) {
	last_name = name;
}

void Contact::set_nickname(std::string nick) {
	nickname = nick;
}

void Contact::set_phone_number(std::string number) {
	phone_number = number;
}

void Contact::set_darkest_secret(std::string secret) {
	darkest_secret = secret;
}

std::string Contact::get_first_name() const {
	return first_name;
}

std::string Contact::get_last_name() const {
	return last_name;
}

std::string Contact::get_nickname() const {
	return nickname;
}

std::string Contact::get_phone_number() const {
	return phone_number;
}

std::string Contact::get_darkest_secret() const {
	return darkest_secret;
}

bool Contact::is_empty() const {
	return first_name.empty();
}
