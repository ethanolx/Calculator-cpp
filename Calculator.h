#pragma once
#include <string>
#include <stack>
#include "Type.h"

class Calculator {
public:
	Calculator(std::string);
	float evaluate();
private:
	void extract(std::string);
	std::stack<std::string> operatorStack;
	std::stack<std::string> operandStack;
	//Type evalNextType(char);
	//Type previousTargetType;
};

