#ifndef DIRECTED_GRAPH_H
#define DIRECTED_GRAPH_H

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>
#include <algorithm>

#include "vertex.hpp"

using namespace std;

/*
	the graph class
*/
template <typename T>
class directed_graph
{

private:
	unordered_map<int, T> vertex_list;
	unordered_map<int, unordered_map<int, T>> adj_list;

	size_t vertex_size = 0;
	size_t edge_size = 0;

	int root_node;

	//

public:
	directed_graph();
	directed_graph(const int&);		// tree root
	~directed_graph();

	// ======= helper functions ===========
	bool contains(const int &) const;
	bool adjacent(const int &, const int &);

	void add_vertex(const vertex<T> &);						 //Adds the passed in vertex to the graph (with no edges).
	void add_edge(const int &, const int &, const T &); //Adds a weighted edge from the first vertex to the second.

	void remove_vertex(const int &);				  //Removes the given vertex. Should also clear any incident edges.
	void remove_edge(const int &, const int &); //Removes the edge between the two vertices, if it exists.

	size_t in_degree(const int &);  //Returns number of edges coming in to a vertex.
	size_t out_degree(const int &); //Returns the number of edges leaving a vertex.
	size_t degree(const int &);	  //Returns the degree of the vertex (both in edges and out edges).

	size_t num_vertices() const; //Returns the total number of vertices in the graph.
	size_t num_edges() const;	  //Returns the total number of edges in the graph.

	vertex<T> get_vertex(const int&);
	vector<vertex<T>> get_vertices();									//Returns a vector containing all the vertices.
	vector<vertex<T>> get_neighbours(const int &);					//Returns a vector containing all the vertices reachable from the given vertex. The vertex is not considered a neighbour of itself.
	vector<vertex<T>> get_second_order_neighbours(const int &); // Returns a vector containing all the second_order_neighbours (i.e., neighbours of neighbours) of the given vertex.
																					// A vector cannot be considered a second_order_neighbour of itself.
	bool reachable(const int &, const int &); //Returns true if the second vertex is reachable from the first (can you follow a path of out-edges to get from the first to the second?). Returns false otherwise.
	bool contain_cycles();							// Return true if the graph contains cycles (there is a path from any vertices directly/indirectly to itself), false otherwise.

	vector<vertex<T>> depth_first(const int &);	 //Returns the vertices of the graph in the order they are visited in by a depth-first traversal starting at the given vertex.
	vector<vertex<T>> breadth_first(const int &); //Returns the vertices of the graph in the order they are visisted in by a breadth-first traversal starting at the given vertex.

	directed_graph<T> out_tree(const int &); //Returns a tree starting at the given vertex using the out-edges. This means every vertex in the tree is reachable from the root.
	void out_tree(directed_graph<T> &, const int &, const int &, bool*);

	vector<vertex<T>> pre_order_traversal(const int &, directed_graph<T> &);  // returns the vertices in the visiting order of a pre-order traversal of the tree starting at the given vertex.
	void pre_order_traversal(vector<vertex<T>>&, const int&, bool*);

	vector<vertex<T>> in_order_traversal(const int &, directed_graph<T> &);	  // returns the vertices in the visiting order of an in-order traversal of the tree starting at the given vertex.
	void in_order_traversal(vector<vertex<T>>&, const int&, const int&, bool*);

	vector<vertex<T>> post_order_traversal(const int &, directed_graph<T> &); // returns the vertices in ther visitig order of a post-order traversal of the tree starting at the given vertex.
	void post_order_traversal(vector<vertex<T>>&, const int&, bool*);

	vector<vertex<T>> significance_sorting(); // Return a vector containing a sorted list of the vertices in descending order of their significance.
};

#include "directed_graph.tpp"

#endif