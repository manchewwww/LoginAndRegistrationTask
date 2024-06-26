#include "Login.h"

void Login::execute(const DataBaseConnection& dataBase) {
	std::string password;
	std::cout << "Login\nEmail: ";
	std::cin >> email;
	std::cout << "Password: ";
	std::cin >> password;

	if (dataBase.userWithSameDataExists(email, password)) {
		loginFunctions(dataBase);
	}
	else {
		throw std::invalid_argument("Incorrect password or email.\n");
	}
}

void Login::loginFunctions(const DataBaseConnection& dataBase) const {
	std::cout << "Successfull login!\n";
	int command = 0;
	while (command != 3) {
		printLoginFunction();
		std::cout << "Enter command: ";
		std::cin >> command;
		try {
			switch (command) {
			case 1: changeName(dataBase); break;
			case 2: changePassword(dataBase); break;
			case 3: std::cout << "Successfull logout!\n"; break;
			default: {
				std::cout << "Invalid command. Try again!\n";
				break;
			}
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
	std::cin >> newPassword;
	isValidPassword(newPassword);
	std::cout << "Enter password again: ";
	std::string reNewPassword;
	std::cin >> reNewPassword;
	if (newPassword != reNewPassword) {
		throw std::invalid_argument("Passwords must be the same\n");
	}
	dataBase.updatePassword(email, newPassword);
}

void Login::changeName(const DataBaseConnection& dataBase) const {
	std::string newName;
	std::cin.ignore();
	char buffer[1024];
	std::cout << "Change name \nEnter new name: ";
	std::cin.getline(buffer, 1024);
	newName = buffer;
	isValidName(newName);
	dataBase.updateName(email, newName);
}

void Login::printLoginFunction() const {
	std::cout << "Enter command: \n [1]: Change name.\n [2]: Change password.\n [3]: Logout.\n";
}
