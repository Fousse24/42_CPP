#ifndef CONTACT_HPP
#define CONTACT_HPP

#include	<string>

class Contact
{
private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string secret;

public:
    Contact();
    ~Contact();

	void setFirstName(std::string str);
	void setLastName(std::string str);
	void setNickname(std::string str);
	void setPhoneNumber(std::string str);
	void setSecret(std::string str);

	std::string getFirstName();
	std::string getLastName();
	std::string getNickname();
	std::string getPhoneNumber();
	std::string getSecret();
};

#endif