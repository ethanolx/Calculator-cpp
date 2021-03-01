#pragma once
#include <string>
#include "Type.h"
#include "Utilities.h"

using namespace std;

int Utitities::getPriority(OperatorType t) {
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

string replace(string original, char to_replace, string replace_with) {
	string new_string = "";
	for (char c : original) {
		new_string += c == to_replace ? replace_with : string(1, c);
	}
	return new_string;
}