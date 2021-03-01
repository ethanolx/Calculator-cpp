#pragma once
#include <string>
#include <stack>
#include "Type.h"

class Calculator
{
public:
	Calculator(std::string);
	float evaluate();
private:
	void extract(std::string);
	stack<std::string> operatorStack;
	stack<double> operandStack;
	Type evalNextType(char);
	Type previousTargetType;
};

