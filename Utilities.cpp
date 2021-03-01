#pragma once
#include <string>
#include <iostream>
#include "Type.h"
#include "Utilities.h"

using namespace std;

int Utilities::getPriority(OperatorType t) {
	switch (t) {
		case OperatorType::ADD:
		case OperatorType::SUBTRACT:
			return 1;
		case OperatorType::MULTIPLY:
		case OperatorType::DIVIDE:
			return 2;
		case OperatorType::EXPONENT:
			return 3;
	}
}

Type Utilities::getType(char c) {
	switch (c) {
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			return Type::OPERAND;
		case '(':
		case ')':
			return Type::PARENTHESIS;
		default:
			return Type::OPERATOR;
	}
}

string Utilities::replace(string original, char to_replace, string replace_with) {
	string new_string = "";
	for (char c : original) {
		string ch(1, c);
		new_string += c == to_replace ? replace_with : ch;
	}
	return new_string;
}

string Utilities::removeWhitespace(string original) {
	cout << original;
	return Utilities::replace(original, ' ', "");
}