#pragma once
#include "DataBaseConnection.h"

class Function {
public:
	friend class Registration;
	friend class Login;
	virtual void execute(const DataBaseConnection& dataBase) = 0;
	virtual ~Function() = default;
private:
	bool isValidEmail(const std::string& email) const;
	bool isValidPassword(const std::string& password) const;
	bool isValidName(const std::string& name) const;
};
