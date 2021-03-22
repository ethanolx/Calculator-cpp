#pragma once

class Vertex {
public:
	typedef float Operation(float, float);

	Vertex();
	Vertex(float);
	Vertex(Operation*);

	Vertex* left;
	Vertex* right;
	
	enum class VertexClass { INTERNAL, LEAF } cls;
	union Value { float leaf; Operation* interna; } value;
};