
#include <string>
#include <iostream>
#include <cmath>
#include "Vertex.h"
#include "Utilities.h"

using namespace std;

#ifndef U
#define U

int Utilities::getPriority(char t) {
	switch (t) {
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		case '^':
			return 3;
		default:
			return 0;
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
	return Utilities::replace(original, ' ', "");
}

float Utilities::add(float a, float b) {
	return a + b;
}

float Utilities::subtract(float a, float b) {
	return a - b;
}

float Utilities::multiply(float a, float b) {
	return a * b;
}

float Utilities::divide(float a, float b) {
	return a / b;
}

float Utilities::exp(float a, float b) {
	return pow(a, b);
}

#endif