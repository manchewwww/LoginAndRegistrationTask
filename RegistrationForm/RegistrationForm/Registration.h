#pragma once
#include "Function.h"

class Registration : public Function {
public:
	void execute(const DataBaseConnection& dataBase) override;
};
