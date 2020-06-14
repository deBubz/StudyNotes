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
	Directed Graph class using adjacent list built from unordered_map
	DSA 2020 - Assessment 1 submission

	by Bao Hoang 13363332
*/
template <typename T>
class directed_graph
{
	// private elements are moved to the end of the class to group and contain recursive helper functions
public:
	// ======= constructors, destructors ========
	directed_graph();
	directed_graph(const int&);		// tree constructor
	~directed_graph();

	// ======= helper methods ===================
	bool contains(const int &) const;
	bool adjacent(const int &, const int &);

	// add methods
	void add_vertex(const vertex<T> &);
	void add_edge(const int &, const int &, const T &);

	// remove methods
	void remove_vertex(const int &);
	void remove_edge(const int &, const int &);

	// degree count methods
	size_t in_degree(const int &);
	size_t out_degree(const int &);
	size_t degree(const int &);

	// get size count methods
	size_t num_vertices() const;
	size_t num_edges() const;

	// get methods
	vertex<T> get_vertex(const int&);
	vector<vertex<T>> get_vertices();
	T get_edge(const int&, const int&);

	// neighbours methods
	vector<vertex<T>> get_neighbours(const int &);
	vector<vertex<T>> get_second_order_neighbours(const int &);

	// ======= cycles ===========================
	bool reachable(const int &, const int &);
	bool contain_cycles();

	// ======= graph traversals =================
	vector<vertex<T>> depth_first(const int &);
	vector<vertex<T>> breadth_first(const int &);

	// ======= trees ============================
	directed_graph<T> out_tree(const int &);

	// depth first tree traversals
	vector<vertex<T>> pre_order_traversal(const int &, directed_graph<T> &);
	vector<vertex<T>> in_order_traversal(const int &, directed_graph<T> &);
	vector<vertex<T>> post_order_traversal(const int &, directed_graph<T> &);


	// ======= sorting =========================
	vector<vertex<T>> significance_sorting();


private:
	unordered_map<int, T> vertex_list;
	unordered_map<int, unordered_map<int, T>> adj_list;

	size_t vertex_size = 0;
	size_t edge_size = 0;

	int tree_root;

	// ======= recursion helper functions =======
	void out_tree_helper(directed_graph<T> &, const int &, const int &, bool*);

	// tree traversals
	void pre_order_helper(vector<vertex<T>>&, const int&, bool*);
	void in_order_helper(vector<vertex<T>>&, const int&, const int&, bool*);
	void post_order_helper(vector<vertex<T>>&, const int&, bool*);
};

// definitions of class methods
#include "directed_graph.cpp"

#endif