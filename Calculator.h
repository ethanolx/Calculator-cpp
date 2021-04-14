#include <unordered_map>
#include <string>
#include <set>
#include <vector>
#include "Vertex.h"
#include "Utilities.h"

#ifndef Ch
#define Ch

class Calculator {
	Calculator();
	static void extract(std::string);
	static float reduce();

	// Properties
	static int currentParenthesisModifier;
	static const int parenthesisModifier = 4;
	static std::unordered_map<int, std::vector<int>> indexMap;
	static std::set<int> prioritySet;
	static std::vector<Vertex> operandVect;
	static std::vector<Vertex> operationVect;
	static Vertex* build(std::vector<int>);
	static void transform(std::vector<Vertex>&, std::vector<Vertex>&);
	static std::vector<int> partition(bool, int, std::vector<int>);
	static void dfs(Vertex&);

public:
	static std::vector<int> flatten(std::unordered_map<int, std::vector<int>>, std::set<int>);
	static float evaluate(std::string);
};

#endif 