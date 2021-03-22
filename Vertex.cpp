#pragma once
#include "Vertex.h"

Vertex::Vertex() {
	cls = VertexClass::LEAF;
	left = nullptr;
	right = nullptr;
	value.leaf = 0;
}

Vertex::Vertex(Vertex::Operation* op) {
	cls = VertexClass::INTERNAL;
	left = nullptr;
	right = nullptr;
	value.interna = op;
}

Vertex::Vertex(float val) {
	cls = VertexClass::LEAF;
	left = nullptr;
	right = nullptr;
	value.leaf = val;
}
