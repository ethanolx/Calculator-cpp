#include "Vertex.h"

#ifndef V
#define V

Vertex::Vertex() {
	cls = VertexClass::LEAF;
	left = nullptr;
	right = nullptr;
	value.flt = 0;
}

Vertex::Vertex(Vertex::Operation* op) {
	cls = VertexClass::INTERNAL;
	left = nullptr;
	right = nullptr;
	value.optn = op;
}

Vertex::Vertex(float val) {
	cls = VertexClass::LEAF;
	left = nullptr;
	right = nullptr;
	value.flt = val;
}

#endif
