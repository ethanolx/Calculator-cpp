#pragma once
#include <string>
#ifndef STACK_H
#define STACK_H

template <class T>
class Stack
{
public:
	void append(T);
	void pop();
private:
	const int size = 0;
};

#endif // STACK_H