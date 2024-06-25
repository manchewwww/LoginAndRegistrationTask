// RegistrationForm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Registration.h"
#include "Login.h"

const static char DATA_BASE_PATH[47] = "C:\\Users\\User\\source\\repos\\DataBase\\Users.db";

void printRegistrationOrLogin() {
	std::cout << "Enter digit before command! \n [1] Login\n [2] Registration\n [3] Exit\n";
}

Function* factory() {
	char command = '\0';
	printRegistrationOrLogin();
	std::cout << "Enter digit: ";
	std::cin >> command;
	switch (command) {
	case '1': return new Login();
	case '2': return new Registration();
	case '3': throw 0;
	default: throw std::invalid_argument("Invalid command\n");
	}
}

int main() {
	DataBaseConnection dataBase = DATA_BASE_PATH;
	Function* a = nullptr;
	while (true) {
		try {
			if (a == nullptr) {
				a = factory();
			}
			a->execute(dataBase);
			delete a;
			a = nullptr;
		}
		catch (const std::invalid_argument& e) {
			delete a;
			a = nullptr;
			std::cout << e.what();
		}
		catch (...) {
			return 0;
		}
	}

}
