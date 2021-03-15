#pragma once

#include <unordered_map>
#include <string>
#include <set>
#include <stack>
#include <vector>
#include "Type.h"
#include "Utilities.h"

class Calculator {
	Calculator();
	static void extract(std::string);
	static float reduce();

	// Properties
	static int currentParenthesisModifier;
	static const int parenthesisModifier = 4;
	static std::unordered_map<int, std::vector<int>> indexMap;
	static std::set<int> prioritySet;
	static std::vector<float> operandVect;
	static std::vector<Utilities::Operation*> operationVect;

public:
	static void evaluate(std::string);
};
