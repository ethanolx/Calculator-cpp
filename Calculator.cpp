#include "Calculator.h"
#include "Type.h"
#include <iostream>
#include <string>
#include <iostream>
#include <stack>
#include "Utilities.h"
#include <regex>
#include "Vertex.h"

using namespace std;

int Calculator::currentParenthesisModifier = 0;
unordered_map<int, vector<int>> Calculator::indexMap = unordered_map<int, vector<int>>();
vector<float> Calculator::operandVect(0);
set<int> Calculator::prioritySet = set<int>();
vector<Utilities::Operation*> Calculator::operationVect = vector<Utilities::Operation*>();

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
						Calculator::operationVect.push_back(&Utilities::add);
						break;
					case '-':
						Calculator::operationVect.push_back(&Utilities::subtract);
						break;
					case '*':
						Calculator::operationVect.push_back(&Utilities::multiply);
						break;
					case '/':
						Calculator::operationVect.push_back(&Utilities::divide);
						break;
					case '^':
						Calculator::operationVect.push_back(&Utilities::exp);
						break;
				}
			}
			else
				Calculator::operandVect.push_back(stof(nextTerm));

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

void Calculator::evaluate(string seq) {
	cout << "Original" << endl << seq << endl << endl;
	string stripped = Utilities::removeWhitespace(seq);

	cout << "Stripped" << endl << stripped << endl << endl;

	extract(stripped);
	reduce();

	cout << "Operands" << endl;
	for (float f : Calculator::operandVect) {
		cout << f << endl;
	}

	cout << endl << "Priorities" << endl;
	for (int i : Calculator::prioritySet) {
		cout << i << endl;
	}

	cout << endl << "Index Map" << endl;
	for (auto kv : Calculator::indexMap) {
		cout << kv.first << "  --->   ";
		for (int j : Calculator::indexMap[kv.first]) {
			cout << j << ' ';
		}
		cout << endl;
	}
}

float Calculator::reduce() {
	cout << "Reduce" << endl;
	vector<Vertex> v = *Utilities::transform(Calculator::operandVect, Calculator::operationVect);
	Vertex root = *Utilities::build(v, Utilities::flatten(Calculator::indexMap));
	Vertex target;
	while (target.cls != Vertex::VertexClass::LEAF) {
		target = *root.left;
		cout << target.value.leaf;
	}
	return 1.0;
}