#pragma once
#include "Vertex.h"
#include "Utilities.h"

Vertex::Vertex(float l, float r, Utilities::Operation* op) {
	cls = VertexClass::INTERNAL;
	left = &Vertex(l);
	right = &Vertex(r);
	value.interna = op;
}

Vertex::Vertex() { }

Vertex::Vertex(float val) {
	cls = VertexClass::LEAF;
	value.leaf = val;
	left = nullptr;
	right = nullptr;
}