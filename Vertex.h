#ifndef Vh
#define Vh

class Vertex {
public:
	typedef float Operation(float, float);

	Vertex();
	Vertex(float);
	Vertex(Operation*);

	Vertex* left;
	Vertex* right;
	
	enum class VertexClass { INTERNAL, LEAF } cls;
	union Value { float flt; Operation* optn; } value;
};

#endif