
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip> // For std::setw

#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact _contacts[8];	// Array of 8 contacts (subject given max)
		int _index;				// To track the next position to fill
		int _total_count;		// How many contacts exist (max 8)

	public:
		PhoneBook(void);
		~PhoneBook(void);

	void add_contact(void);		// ADD command
	void search_contact(void);	// SEARCH command
	void display_list(void);	// helper for formatting columns
};

#endif
