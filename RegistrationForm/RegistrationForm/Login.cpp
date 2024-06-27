#include "Login.h"

void Login::execute(const DataBaseConnection& dataBase) {
	std::string password;
	std::cout << "Login\nEmail: ";
	std::getline(std::cin, email);
	std::cout << "Password: ";
	std::getline(std::cin, password);


	if (dataBase.userWithSameDataExists(email, password)) {
		loginFunctions(dataBase);
	}
	else {
		throw std::invalid_argument("Incorrect password or email.\n");
	}
}

void Login::loginFunctions(const DataBaseConnection& dataBase) const {
	std::cout << "Successfull login!\n";
	std::string command;
	while (true) {
		printLoginFunction();
		std::cout << "Enter digit: ";
		std::getline(std::cin, command);

		try {
			if (command == "1") {
				changeName(dataBase);
			}
			else if (command == "2") {
				changePassword(dataBase);
			}
			else if (command == "3") {
				std::cout << "Successfull logout!\n";
				break;
			}
			else {
				std::cout << "Invalid command. Try again!\n";
			}
		}
		catch (const std::invalid_argument& e) {
			std::cout << e.what();
		}
	}
}

void Login::changePassword(const DataBaseConnection& dataBase) const {
	std::cout << "Change password \nEnter new password: ";
	std::string newPassword;
	std::getline(std::cin, newPassword);
	isValidPassword(newPassword);
	std::cout << "Enter password again: ";
	std::string reNewPassword;	
	std::getline(std::cin, reNewPassword);
	if (newPassword != reNewPassword) {
		throw std::invalid_argument("Passwords must be the same\n");
	}
	dataBase.updatePassword(email, newPassword);
}

void Login::changeName(const DataBaseConnection& dataBase) const {
	std::string newName;
	std::cout << "Change name \nEnter new name: ";
	std::getline(std::cin, newName);
	isValidName(newName);
	dataBase.updateName(email, newName);
}

void Login::printLoginFunction() const {
	std::cout << "Enter digit before command \n [1]: Change name.\n [2]: Change password.\n [3]: Logout.\n";
}
