#include "Registration.h"

void Registration::execute(const DataBaseConnection& dataBase) {
	try {
		std::string email;
		std::string password;
		std::string rePassword;
		std::string name;
		std::cout << "Registration\n";
		std::cout << "Email: ";
		std::cin >> email;
		isValidEmail(email);
		dataBase.emaillExists(email);
		std::cout << "Password: ";
		std::cin >> password;
		isValidPassword(password);
		std::cout << "Re-password: ";
		std::cin >> rePassword;
		if (password != rePassword) {
			throw std::invalid_argument("Passwords must be the same\n");
		}
		std::cout << "Name: ";
		std::cin.ignore();
		char buffer[1024];
		std::cin.getline(buffer, 1024);
		name = buffer;
		isValidName(name);
		dataBase.enterDataToDataBase(email, password, name);
	}
	catch (const std::invalid_argument& e) {
		throw e;
	}
}
