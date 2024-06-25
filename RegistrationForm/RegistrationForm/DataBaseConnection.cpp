#include "DataBaseConnection.h"

DataBaseConnection::DataBaseConnection(const char* address) {
	sqlite3_open(address, &DB);
	createTable();
}

DataBaseConnection::~DataBaseConnection() {
	sqlite3_close(DB);
}

void DataBaseConnection::enterDataToDataBase(const std::string& email, const std::string& password, const std::string& name) const {
	char* messaggeError;

	std::string sql = "INSERT INTO USERS (EMAIL, PASSWORD, NAME) VALUES"
		"('" + email + "', '" + password + "', '" + name + "');";


	int exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);

	if (exit != SQLITE_OK) {
		sqlite3_free(messaggeError);
		throw std::invalid_argument("Error with registration!\n");
	}
	else {
		std::cout << "Successfull registration!" << std::endl;
	}
}

bool DataBaseConnection::updatePassword(const std::string& email, const std::string& pass) const {
	char* messaggeError;

	std::string sql = "UPDATE USERS SET PASSWORD = '" + pass + "' WHERE EMAIL = '" + email + "';";
	int exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
	if (exit != SQLITE_OK) {
		return false;
	}
	else {
		std::cout << "Password is updated successfully\n";
		return true;
	}
}

bool DataBaseConnection::updateName(const std::string& email, const std::string& name) const {
	char* messaggeError;
	std::string sql = "UPDATE USERS SET NAME = '" + name + "' WHERE EMAIL = '" + email + "'";
	int exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
	if (exit != SQLITE_OK) {
		return false;
	}
	else {
		std::cout << "Name is updated successfully\n";
		return true;
	}
}

bool DataBaseConnection::emaillExists(const std::string& email) const {
	std::string sql = "SELECT * FROM USERS WHERE EMAIL = '" + email + "';";
	bool exists = false;
	char* messaggeError;
	int exit = sqlite3_exec(DB, sql.c_str(), callback, &exists, &messaggeError);
	if (exit != SQLITE_OK) {
		sqlite3_free(messaggeError);
		throw std::invalid_argument("User with this email exist!\n");
	}
	return exists;
}

bool DataBaseConnection::userWithSameDataExists(const std::string& email, const std::string& password) const {
	std::string sql = "SELECT * FROM USERS WHERE EMAIL = '" + email + "' AND PASSWORD = '" + password + "';";
	bool exists = false;
	char* messaggeError;
	int exit = sqlite3_exec(DB, sql.c_str(), callback, &exists, &messaggeError);
	if (exit != SQLITE_OK) {
		sqlite3_free(messaggeError);
		throw std::invalid_argument("Incorrect password or email!\n");
	}
	return exists;
}

int DataBaseConnection::callback(void* data, int argc, char** argv, char** azColName) {
	bool* exists = static_cast<bool*>(data);
	*exists = (argc > 0);
	return 0;
}

void DataBaseConnection::createTable() {
	std::string sql = "CREATE TABLE IF NOT EXISTS USERS("
		"ID INTEGER PRIMARY KEY AUTOINCREMENT,"
		"EMAIL VARCHAR(50) NOT NULL, "
		"PASSWORD VARCHAR(100) NOT NULL,"
		"NAME VARCHAR(50) NOT NULL);";
	try {
		char* messageError;
		int exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
		if (exit != SQLITE_OK) {
			sqlite3_free(messageError);
			throw std::invalid_argument("Table is not created!\n");
		}
	}
	catch (const std::exception& e) {
		std::cout << e.what();
	}
}

