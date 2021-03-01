#pragma once
#include <string>
#include "Type.h"

namespace Utilities {
	int getPriority(OperatorType);
	Type getType(char);
	std::string replace(std::string, char, std::string);
	std::string removeWhitespace(std::string);
}