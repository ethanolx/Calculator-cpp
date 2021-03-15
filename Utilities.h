#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include "Vertex.h"

namespace Utilities {
	int getPriority(char);
	std::string replace(std::string, char, std::string);
	std::string removeWhitespace(std::string);
	typedef float Operation(float, float);
	Vertex* build(std::vector<Vertex>&, std::vector<int>);
	std::vector<Vertex>* transform(std::vector<float>, std::vector<Utilities::Operation*>);
	std::vector<int> flatten(std::unordered_map<int, std::vector<int>>);
	std::vector<int> partition(bool, int, std::vector<int>);

	template <class T>
	void printVector(vector<T>);

	float add(float a, float b);
	float subtract(float a, float b);
	float multiply(float a, float b);
	float divide(float a, float b);
	float exp(float a, float b);
}