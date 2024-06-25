#include "Function.h"

bool Function::isValidEmail(const std::string& email) const {
	int counter = 0;
	for (size_t i = 0; i < email.length(); i++) {
		if (i != 0 && i != email.length() - 1 && email[i] == '@') {
			counter++;
		}
	}
	if (counter == 1) {
		return true;
	}
	else {
		throw std::invalid_argument("Invalid email\n");
	}
}

bool Function::isValidPassword(const std::string& password) const {
	return password.length() >= 8 ? true : throw std::invalid_argument("Password must be longer than 8 characters\n");
}

bool Function::isValidName(const std::string& name) const {
	int counter1 = 0;
	int counter2 = 0;
	for (size_t i = 0; i < name.length(); i++) {
		if ((name[i] <= 'a' && name[i] >= 'z') || (name[i] <= 'A' && name[i] >= 'Z')) {
			throw std::invalid_argument("Invalid name\n");
		}
		else if (name[i] >= 'A' && name[i] <= 'Z') {
			counter2++;
		}
		else if (i != 0 && i != name.length() - 1 && name[i] == ' ') {
			counter1++;
		}
	}
	if (counter1 == 1 && counter2 == 2) {
		return true;
	}
	else {
		throw std::invalid_argument("Invalid name\n");
	}
}
