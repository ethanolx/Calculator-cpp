#pragma once

enum class Type {
	OPERAND,
	OPERATOR,
	PARENTHESIS
};

enum class OperatorType: int {
	ADD = '+',
	SUBTRACT = '-',
	MULTIPLY = '*',
	DIVIDE = '/',
	EXPONENT = '^'
};