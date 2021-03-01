#include "Calculator.h"
#include "Type.h"
#include <iostream>
#include <string>
#include <iostream>
#include <stack>
#include "Utilities.h"
#include <stack>

using namespace std;

Calculator::Calculator(string seq) {
	string stripped = Utilities::removeWhitespace(seq);
	extract(stripped);
};

void Calculator::extract(string seq) {
	char* ptr = nullptr;
	for (char c : seq) {
		ptr = &c;
		string s = "";
		switch (Utilities::getType(c)) {
			case Type::OPERAND:
				if (Utilities::getType(*(ptr + 1)) == Type::OPERAND) {
					s += c;
				}
				else {
					evaluate();
				}
				break;
			case Type::OPERATOR:
				break;
			case Type::PARENTHESIS:
				break;
			default:
				break;
		}
	}
};

float Calculator::evaluate() {
	return 0.0f;
}