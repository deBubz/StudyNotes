#ifndef VERTEX_H
#define VERTEX_H

/*
	Vertex class
	support class used in directed_graph.hpp
	to represent vertices in a graph
*/

template <typename T>
class vertex
{
public:
	int id;
	T weight;

	// constructor
	vertex(int x, T y) : id(x), weight(y) {}
};

#endif