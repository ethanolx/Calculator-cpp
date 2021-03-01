#include "Calculator.h"
#include "Type.h"
#include <iostream>
#include <string>
#include <iostream>
#include <stack>

using namespace std;

Calculator::Calculator(string seq) {
	string stripped = replace(seq, ' ', "");
	extract(stripped);
};

void Calculator::extract(string seq) {
	for (char c : seq) {
		cout << evalNextType(c) << endl;
	}
};



Type Calculator::evalNextType(char c) {
	switch (c) {
	case '1':
	case '2':
	case '3':
		return Type::OPERAND;
	case '(':
	case ')':
		return Type::PARANTHESIS;
	default:
		return Type::OPERATOR;
	}
}

float Calculator::evaluate() {
	return 0.0f;
}