#pragma once
#include <string>

template <class T>
class Stack
{
public:
	void append(T);
	void pop();
private:
	const int size = 0;
};