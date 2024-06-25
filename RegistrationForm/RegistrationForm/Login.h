#pragma once
#include "Function.h"
class Login : public Function {
public:
	void execute(const DataBaseConnection& dataBase) override;
private:
	void loginFunctions(const DataBaseConnection& dataBaseconst ) const;
	void changePassword(const DataBaseConnection& dataBase) const;
	void changeName(const DataBaseConnection& dataBase) const;
	void printLoginFunction() const;

	std::string email;
};
