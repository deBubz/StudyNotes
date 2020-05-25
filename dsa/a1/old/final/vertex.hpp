#ifndef VERTEX_H
#define VERTEX_H

/*
	the vertex class
*/

template <typename T>
class vertex
{
public:
	int id;
	T weight;

	vertex(int x, T y) : id(x), weight(y) {}
};

#endif