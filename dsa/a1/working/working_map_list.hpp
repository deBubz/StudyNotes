#ifndef DIRECTED_GRAPH_H
#define DIRECTED_GRAPH_H

#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<array>

// include more libraries here if you need to

using namespace std; // the standard namespace are here just in case.

/*
	the vertex class
*/
template <typename T>
class vertex {

public:
	int id;
	T weight;

	vertex(int x, T y) : id(x), weight(y) {}
	// add more functions here if you need to
};

/*
	the graph class
*/
template <typename T>
class directed_graph {

private:
	unordered_map<int, T> vertex_list;
	unordered_map<int, unordered_map<int, T>> adj_list;

	size_t vertex_size = 0;
	size_t edge_size = 0;


public:

	directed_graph();
	~directed_graph();

	// ok
	bool contains(const int&) const;
	bool adjacent(const int&, const int&);

	// ok
	void add_vertex(const vertex<T>&); //Adds the passed in vertex to the graph (with no edges).
	void add_edge(const int&, const int&, const T&); //Adds a weighted edge from the first vertex to the second.

	// ok
	void remove_vertex(const int&); //Removes the given vertex. Should also clear any incident edges.
	void remove_edge(const int&, const int&); //Removes the edge between the two vertices, if it exists.

	// ok
	size_t in_degree(const int&); //Returns number of edges coming in to a vertex.
	size_t out_degree(const int&); //Returns the number of edges leaving a vertex.
	size_t degree(const int&); //Returns the degree of the vertex (both in edges and out edges).

	// ok
	size_t num_vertices() const; //Returns the total number of vertices in the graph.
	size_t num_edges() const; //Returns the total number of edges in the graph.

	// ok
	vector<vertex<T>> get_vertices(); //Returns a vector containing all the vertices.
	vector<vertex<T>> get_neighbours(const int&); //Returns a vector containing all the vertices reachable from the given vertex. The vertex is not considered a neighbour of itself.
	vector<vertex<T>> get_second_order_neighbours(const int&); // Returns a vector containing all the second_order_neighbours (i.e., neighbours of neighbours) of the given vertex.
															  // A vector cannot be considered a second_order_neighbour of itself.
	// todo
	bool reachable(const int&, const int&) const; //Returns true if the second vertex is reachable from the first (can you follow a path of out-edges to get from the first to the second?). Returns false otherwise.
	bool contain_cycles() const; // Return true if the graph contains cycles (there is a path from any vertices directly/indirectly to itself), false otherwise.

	// todo
	vector<vertex<T>> depth_first(const int&); //Returns the vertices of the graph in the order they are visited in by a depth-first traversal starting at the given vertex.
	vector<vertex<T>> breadth_first(const int&); //Returns the vertices of the graph in the order they are visisted in by a breadth-first traversal starting at the given vertex.

	// todo
	directed_graph<T> out_tree(const int&); //Returns a tree starting at the given vertex using the out-edges. This means every vertex in the tree is reachable from the root.

	vector<vertex<T>> pre_order_traversal(const int&, directed_graph<T>&); // returns the vertices in the visiting order of a pre-order traversal of the tree starting at the given vertex.
	vector<vertex<T>> in_order_traversal(const int&, directed_graph<T>&); // returns the vertices in the visiting order of an in-order traversal of the tree starting at the given vertex.
	vector<vertex<T>> post_order_traversal(const int&, directed_graph<T>&); // returns the vertices in ther visitig order of a post-order traversal of the tree starting at the given vertex.

	vector<vertex<T>> significance_sorting(); // Return a vector containing a sorted list of the vertices in descending order of their significance.

};

// Define all your methods down here (or move them up into the header, but be careful you don't double up). If you want to move this into another file, you can, but you should #include the file here.
// Although these are just the same names copied from above, you may find a few more clues in the full method headers.
// Note also that C++ is sensitive to the order you declare and define things in - you have to have it available before you use it.

template <typename T> directed_graph<T>::directed_graph() {}
template <typename T> directed_graph<T>::~directed_graph() {}

template <typename T>	// does graph contain this edge
bool directed_graph<T>::contains(const int& u_id) const {
	if(this->adj_list.find(u_id) == this->adj_list.end()) return false;
	else return true;
}

template <typename T>	// check if 2 vert has an edge
bool directed_graph<T>::adjacent(const int& u_id, const int& v_id) {
	if (contains(u_id) && contains(v_id) && (u_id != v_id)) {
		// if exist && no looped edges
		return this->adj_list[u_id].find(v_id) != this->adj_list[u_id].end();
	} else return false;
}

template <typename T>	// add vertex
void directed_graph<T>::add_vertex(const vertex<T>& u) {
	if(!contains(u.id)){	// if not already added
		this->vertex_list.insert({u.id, u.weight});		// into list
		this->adj_list[u.id] = unordered_map<int, T>(); // (uid, empty map<key, weight>)
		this->vertex_size++;
	}
}

template <typename T>	// add edge
void directed_graph<T>::add_edge(const int& u_id, const int& v_id, const T& weight) {

	if (contains(u_id) && contains(v_id)) {		// check existing vertexes
		if (!adjacent(u_id, v_id)) {	// check existing edges
			this->adj_list[u_id].insert({v_id, weight});
			this->edge_size++;
		}
	}
}

template <typename T>	// remove vertex
void directed_graph<T>::remove_vertex(const int& u_id) {
	if (this->contains(u_id)) {
		this->vertex_list.erase(u_id);		// delet from list
		this->adj_list.erase(u_id);			// delet v head from list
		this->vertex_size--;

		for (auto x : this->vertex_list) {	// delet v tail from list
			this->adj_list[x.first].erase(u_id);
		}
	}
}

template <typename T>	// remove edge (u,v)
void directed_graph<T>::remove_edge(const int& u_id, const int& v_id) {
	if(adjacent(u_id, v_id)) {
		this->adj_list[u_id].erase(v_id);
		this->edge_size--;
	}
}

template <typename T>
size_t directed_graph<T>::in_degree(const int& u_id) {
	size_t size = 0;
	if(contains(u_id)) {							// check if exist
		for (auto v : this->vertex_list) {	// foreach map(id, W) in adj_list
			// find edges v -> u
			unordered_map<int, T> map = this->adj_list[v.first];
			if(map.find(u_id) != map.end())
				size++;
		}
	}
	return size;
}

template <typename T>
size_t directed_graph<T>::out_degree(const int& u_id) {
	size_t size = 0;

	if (contains(u_id)) {	// if exist
		unordered_map<int, T> map = adj_list[u_id];
		for (auto v: this->vertex_list ) {
			if(map.find(v.first) != map.end()) size++;
		}
	}
	return size;

	// same as these but, ed's not happy
	//return this->adj_list[u_id].size();
	//return get_neighbours(u_id).size();
}

template <typename T>
size_t directed_graph<T>::degree(const int& u_id) {
	// would be a bit faster if implemented seperately
	return in_degree(u_id) + out_degree(u_id);
}

template <typename T>	// return num of vertex
size_t directed_graph<T>::num_vertices() const { return this->vertex_size; }

template <typename T>	// return num of edges
size_t directed_graph<T>::num_edges() const { return this->edge_size; }
	//size_t size = 0;
	//for (auto v : adj_list) {
	//	size += v.second.size();
	//}


template <typename T>	// list of vertex
vector<vertex<T>> directed_graph<T>::get_vertices() {
	vector<vertex<T>> output_list;

	for(auto v : this->vertex_list) {
		vertex<T> vert(v.first, v.second);
		output_list.push_back(vert);
	}

	return output_list;
}

template <typename T>	// first neighbours
vector<vertex<T>> directed_graph<T>::get_neighbours(const int& u_id) {
	vector<vertex<T>> v;
	if (contains(u_id)) {
		for (auto f : this->adj_list[u_id]) {
			vertex<T> n(f.first, f.second);
			v.push_back(n);
		}
	}
	return v;
}

template <typename T>	// second neighbours
vector<vertex<T>> directed_graph<T>::get_second_order_neighbours(const int& u_id) {
	vector<vertex<T>> outN, secN,
		firstN = get_neighbours(u_id);
	bool flag[num_vertices() + 1];

	// setting up flags for added verts
	for (int i = 1; i < num_vertices() + 1; i++) {
		flag[i] = false;
	}

	for (vertex<T> v1 : firstN) {						// foreach neighbour
		secN = get_neighbours(v1.id);
		for (vertex<T> v2 : secN) {					// foreach neighbour of neighbour
			if ((v2.id != u_id) && !flag[v2.id]) {	// cannot be itself and not yet added
				outN.push_back(v2);
				flag[v2.id] = true;
			}
		}
	}

	return outN;
}

template <typename T>	// true if u can reach v
bool directed_graph<T>::reachable(const int& u_id, const int& v_id) const {
	if (adjacent(u_id, v_id)) return true;


	return false;
}

template <typename T>	// true if graph have any cycles
bool directed_graph<T>::contain_cycles() {
	// should be the same as reachable
	// check each v if it can reach itself

	for(auto v : this->vertex_list) {
		return reachable(v.first, v.first);
	}
}

template <typename T>
vector<vertex<T>> directed_graph<T>::depth_first(const int& u_id) { return vector<vertex<T>>(); }

template <typename T>
vector<vertex<T>> directed_graph<T>::breadth_first(const int& u_id) { return vector<vertex<T>>(); }

template <typename T>
directed_graph<T> directed_graph<T>::out_tree(const int& u_id) { return directed_graph<T>(); }

template <typename T>
vector<vertex<T>> directed_graph<T>::pre_order_traversal(const int& u_id, directed_graph<T>& mst) { return vector<vertex<T>>(); }

template <typename T>
vector<vertex<T>> directed_graph<T>::in_order_traversal(const int& u_id, directed_graph<T>& mst) { return vector<vertex<T>>(); }

template <typename T>
vector<vertex<T>> directed_graph<T>::post_order_traversal(const int& u_id, directed_graph<T>& mst) { return vector<vertex<T>>(); }

template <typename T>
vector<vertex<T>> directed_graph<T>::significance_sorting() { return vector<vertex<T>>(); }

#endif