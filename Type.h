#pragma once

enum class Type {
	OPERAND,
	OPERATOR,
	PARANTHESIS
};

enum class OperatorType: int {
	ADD = '+',
	SUBTRACT = '-',
	MULTIPLY = '*',
	DIVIDE = '/',
	EXPONENT = '^'
};