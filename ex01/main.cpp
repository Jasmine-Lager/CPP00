
#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook book;
	std::string command;

	while (true)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, command))
			break;
		if (command == "ADD")
			book.add_contact();
		else if (command == "SEARCH")
			book.search_contact();
		else if (command == "EXIT")
			break;
	}
	return (0);
}