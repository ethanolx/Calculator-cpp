#pragma once
#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include "Vertex.h"
#include <iostream>

namespace Utilities {
	int getPriority(char);
	std::string replace(std::string, char, std::string);
	std::string removeWhitespace(std::string);

	template <class T>
	void printVector(std::vector<T> v) {
		for (T k : v) {
			std::cout << k << ' ';
		}
		std::cout << std::endl;
	}


	float add(float a, float b);
	float subtract(float a, float b);
	float multiply(float a, float b);
	float divide(float a, float b);
	float exp(float a, float b);
}