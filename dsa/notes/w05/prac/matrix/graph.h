#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
// graph declaration

class Graph
{
private:
	// internal rep of graph
	bool** adj_matrix;		// 2d array pointers of pointers
									// use pointers to give size upon usage
	std::size_t size;
public:
	Graph(const size_t&);
	~Graph();

	// add remove edges between 2 vertex
	void add_edge(const int&, const int&);
	void remove_edge(const int&, const int&);

	// test if 2 edges are adjacent
	bool is_adjacent(const int&, const int&);
};


#endif