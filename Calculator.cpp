#include "Calculator.h"
#include "Type.h"
#include <iostream>
#include <string>
#include <iostream>
#include <stack>
#include "Utilities.h"
#include <regex>
#include "Vertex.h"
#include <vector>

using namespace std;

int Calculator::currentParenthesisModifier = 0;
unordered_map<int, vector<int>> Calculator::indexMap = unordered_map<int, vector<int>>();
vector<Vertex> Calculator::operandVect(0);
set<int> Calculator::prioritySet = set<int>();
vector<Vertex> Calculator::operationVect(0);

Calculator::Calculator() {

};

void Calculator::extract(string seq) {
	size_t len = seq.length();
	bool operandExpected = true;
	int counter = 0;
	do {
		regex r("^([\\(\\)]|([\\d]+[\\.]?[\\d]*)|[+\\-*/\\^]).*");
		smatch match;
		vector<char> ops = { '+', '-', '*', '/', '^' };
		if (regex_search(seq, match, r)) {
			string nextTerm = match[1];
			if (nextTerm == "(")
				currentParenthesisModifier += parenthesisModifier;
			else if (nextTerm == ")")
				currentParenthesisModifier -= parenthesisModifier;
			else if (find(ops.begin(), ops.end(), nextTerm[0]) != ops.end()) {
				char optr = nextTerm[0];
				int priority = Utilities::getPriority(optr) + currentParenthesisModifier;
				prioritySet.insert(priority);
				indexMap[priority].push_back(counter++);
				switch (optr) {
					case '+':
						Calculator::operationVect.push_back(Vertex(&Utilities::add));
						break;
					case '-':
						Calculator::operationVect.push_back(Vertex(&Utilities::subtract));
						break;
					case '*':
						Calculator::operationVect.push_back(Vertex(&Utilities::multiply));
						break;
					case '/':
						Calculator::operationVect.push_back(Vertex(&Utilities::divide));
						break;
					case '^':
						Calculator::operationVect.push_back(Vertex(&Utilities::exp));
						break;
				}
			}
			else
				Calculator::operandVect.push_back(Vertex(stof(nextTerm)));

			if (nextTerm.length() == seq.length())
				seq = "";
			else
				seq = seq.substr(nextTerm.length());
		}
		else {
			throw 1;
		}
	} while (seq.length() > 0);
}

float Calculator::evaluate(string seq) {
	cout << "--- Original ---" << endl << seq << endl << endl;
	
	string stripped = Utilities::removeWhitespace(seq);
	cout << "--- Stripped ---" << endl << stripped << endl << endl;

	extract(stripped);
	float result = reduce();

	cout << "--- Result ---" << endl << result << endl << endl;

	return result;
}

float Calculator::reduce() {
	Calculator::transform(Calculator::operandVect, Calculator::operationVect);
	vector<int> priorities = Calculator::flatten(Calculator::indexMap, Calculator::prioritySet);
	Vertex root = *Calculator::build(priorities);
	Calculator::dfs(root);
	return root.value.leaf;
}

vector<int> Calculator::flatten(unordered_map<int, vector<int>> indexMap, set<int> prioritySet) {
	vector<int> v;
	for (int i : prioritySet) {
		vector<int>& tmp = indexMap[i];
		while (!tmp.empty()) {
			v.push_back(tmp.back());
			tmp.pop_back();
		}
	}
	return v;
}

void Calculator::transform(vector<Vertex>& operands, vector<Vertex>& operators) {
	for (int i = 0; i < operators.size(); i++) {
		Vertex& current = operators[i];
		current.left = &operands[i];
		current.right = &operands[i + 1];
	}
}

Vertex* Calculator::build(vector<int> vertexIndices) {
	Vertex& currentVector = Calculator::operationVect[vertexIndices.front()];
	vector<int> indicesToLeft = Calculator::partition(true, vertexIndices.front(), vertexIndices);
	if (!indicesToLeft.empty()) {
		currentVector.left = build(indicesToLeft);
	}

	vector<int> indicesToRight = Calculator::partition(false, vertexIndices.front(), vertexIndices);
	if (!indicesToRight.empty()) {
		currentVector.right = build(indicesToRight);
	}

	return &currentVector;
}

vector<int> Calculator::partition(bool leftFilter, int partitionIndex, vector<int> flattenedPriorities) {
	vector<int> n;
	copy_if(flattenedPriorities.begin(), flattenedPriorities.end(), back_inserter(n), [&](int a) {
		return leftFilter ? a < partitionIndex : a > partitionIndex;
		});
	return n;
}

void Calculator::dfs(Vertex& v) {
	if (v.left->cls == Vertex::VertexClass::INTERNAL) {
		dfs(*v.left);
	}
	if (v.right->cls == Vertex::VertexClass::INTERNAL) {
		dfs(*v.right);
	}
	v.value.leaf = v.value.interna(v.left->value.leaf, v.right->value.leaf);
}