#pragma once
#include <sqlite3.h>
#include <iostream>
#include <string>

class DataBaseConnection {
public:
	DataBaseConnection(const char* address);
	~DataBaseConnection();
	void enterDataToDataBase(const std::string& email, const std::string& password, const std::string& name) const;
	bool updatePassword(const std::string& email, const std::string& pass) const;
	bool updateName(const std::string& email, const std::string& name) const;
	bool emaillExists(const std::string& email) const;
	bool userWithSameDataExists(const std::string& email, const std::string& password) const;
private:
	static int callback(void* data, int argc, char** argv, char** azColName);
	void createTable();
	sqlite3* DB;
};