
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : _index(0), _total_count(0) {}

PhoneBook::~PhoneBook(void) {}

void PhoneBook::add_contact(void)
{
	std::string fields[5];
	std::string prompts[5];
	int i = 0;

	prompts[0] = "First Name: ";
	prompts[1] = "Last Name: ";
	prompts[2] = "Nickname: ";
	prompts[3] = "Phone Number: ";
	prompts[4] = "Darkest Secret: ";

	while (i < 5)
	{
		while (true)
		{
			std::cout << prompts[i];
			if (!std::getline(std::cin, fields[i]))
				return;
			if (!fields[i].empty())
				break;
			std::cout << "Field cannot be empty." << std::endl;
		}
		i++;
	}

	i = _index % 8;
	_contacts[i].set_first_name(fields[0]);
	_contacts[i].set_last_name(fields[1]);
	_contacts[i].set_nickname(fields[2]);
	_contacts[i].set_phone_number(fields[3]);
	_contacts[i].set_darkest_secret(fields[4]);

	_index++;
	if (_total_count < 8)
		_total_count++;
}

static std::string format_str(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void PhoneBook::display_list(void)
{
	int i;

	std::cout << "|" << std::setw(10) << "index" << "|";
	std::cout << std::setw(10) << "first name" << "|";
	std::cout << std::setw(10) << "last name" << "|";
	std::cout << std::setw(10) << "nickname" << "|" << std::endl;

	i = 0;
	while (i < _total_count)
	{
		std::cout << "|" << std::setw(10) << i << "|";
		std::cout << std::setw(10) << format_str(_contacts[i].get_first_name()) << "|";
		std::cout << std::setw(10) << format_str(_contacts[i].get_last_name()) << "|";
		std::cout << std::setw(10) << format_str(_contacts[i].get_nickname()) << "|" << std::endl;
		i++;
	}
}

void PhoneBook::search_contact(void)
{
	int i;
	std::string input;

	if (_total_count == 0)
	{
		std::cout << "Phonebook is empty." << std::endl;
		return ;
	}
	this->display_list(); 
	std::cout << "Enter index to display: ";
	if (!(std::getline(std::cin, input)) || input.empty())
		return;
	if (input.length() == 1 && input[0] >= '0' && input[0] < '0' + _total_count)
	{
		i = input[0] - '0';
		std::cout << "First Name: " << _contacts[i].get_first_name() << std::endl;
		std::cout << "Last Name: " << _contacts[i].get_last_name() << std::endl;
		std::cout << "Nickname: " << _contacts[i].get_nickname() << std::endl;
		std::cout << "Phone Number: " << _contacts[i].get_phone_number() << std::endl;
		std::cout << "Darkest Secret: " << _contacts[i].get_darkest_secret() << std::endl;
	}
	else
		std::cout << "Invalid index." << std::endl;
}
