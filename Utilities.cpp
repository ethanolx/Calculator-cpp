#pragma once
#include <string>
#include <unordered_map>
#include <iostream>
#include "Type.h"
#include "Utilities.h"
#include <algorithm>
#include <set>

using namespace std;

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

vector<Vertex>* transform(vector<float> operands, vector<Utilities::Operation*> operators) {
	vector<Vertex> newVector;
	for (int i = 0; i < operands.size(); i++) {
		Vertex v(operands[i], operands[i + 1], operators[i]);
		newVector.push_back(v);
	}
	return &newVector;
}

Vertex* Utilities::build(vector<Vertex>& v, vector<int> vertexIndices) {
	if (v.size() > 0) {
		Vertex currentVector = v[vertexIndices.front()];
		currentVector.left = build(v, Utilities::partition(true, vertexIndices.front(), vertexIndices));
		currentVector.right = build(v, Utilities::partition(false, vertexIndices.front(), vertexIndices));
		return &currentVector;
	}
	return nullptr;
}

vector<int> flatten(unordered_map<int, vector<int>> indexMap, set<int> prioritySet) {
	vector<int> v;
	for (int i : prioritySet) {
		v.push_back(indexMap[i].back());
	}
	return v;
}

vector<int> Utilities::partition(bool leftFilter, int partitionIndex, vector<int> flattenedPriorities) {
	vector<int> n;
	copy_if(flattenedPriorities.begin(), flattenedPriorities.end(), back_inserter(n), [&](int a) {
		return leftFilter ? a < partitionIndex : a > partitionIndex;
		});
	return n;
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

void Utilities::printVector(vector<T> v) {
	for (auto a : v) {
		cout << a << ' ';
	}
	cout << endl;
}