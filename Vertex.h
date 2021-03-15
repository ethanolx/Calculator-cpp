#pragma once
#include "Utilities.h"

class Vertex {
public:
	Vertex* left;
	Vertex* right;
	Vertex();
	Vertex(float);
	Vertex(float, float, Utilities::Operation*);
	enum class VertexClass {INTERNAL, LEAF } cls;
	typedef float Operation(float, float);
	union { float leaf; Operation* interna; } value;
};