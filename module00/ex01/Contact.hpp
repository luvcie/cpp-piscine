#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

public:
	Contact();

	void set_first_name(std::string name);
	void set_last_name(std::string name);
	void set_nickname(std::string nick);
	void set_phone_number(std::string number);
	void set_darkest_secret(std::string secret);

	std::string get_first_name() const;
	std::string get_last_name() const;
	std::string get_nickname() const;
	std::string get_phone_number() const;
	std::string get_darkest_secret() const;

	bool is_empty() const;
};

#endif
