#ifndef DIRECTED_GRAPH_H
#define DIRECTED_GRAPH_H

#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

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
	unordered_map<int, unordered_map<int, T>> adj_matrix;


public:

	directed_graph();
	~directed_graph();

	bool contains(const int&) const;
	bool adjacent(const int&, const int&);

	void add_vertex(const vertex<T>&); //Adds the passed in vertex to the graph (with no edges).
	void add_edge(const int&, const int&, const T&); //Adds a weighted edge from the first vertex to the second.

	void remove_vertex(const int&); //Removes the given vertex. Should also clear any incident edges.
	void remove_edge(const int&, const int&); //Removes the edge between the two vertices, if it exists.

	size_t in_degree(const int&); //Returns number of edges coming in to a vertex.
	size_t out_degree(const int&); //Returns the number of edges leaving a vertex.
	size_t degree(const int&); //Returns the degree of the vertex (both in edges and out edges).

	size_t num_vertices() const; //Returns the total number of vertices in the graph.
	size_t num_edges() const; //Returns the total number of edges in the graph.

	vector<vertex<T>> get_vertices(); //Returns a vector containing all the vertices.
	vector<vertex<T>> get_neighbours(const int&); //Returns a vector containing all the vertices reachable from the given vertex. The vertex is not considered a neighbour of itself.
	vector<vertex<T>> get_second_order_neighbours(const int&); // Returns a vector containing all the second_order_neighbours (i.e., neighbours of neighbours) of the given vertex.
															  // A vector cannot be considered a second_order_neighbour of itself.
	bool reachable(const int&, const int&) const; //Returns true if the second vertex is reachable from the first (can you follow a path of out-edges to get from the first to the second?). Returns false otherwise.
	bool contain_cycles() const; // Return true if the graph contains cycles (there is a path from any vertices directly/indirectly to itself), false otherwise.

	vector<vertex<T>> depth_first(const int&); //Returns the vertices of the graph in the order they are visited in by a depth-first traversal starting at the given vertex.
	vector<vertex<T>> breadth_first(const int&); //Returns the vertices of the graph in the order they are visisted in by a breadth-first traversal starting at the given vertex.

	directed_graph<T> out_tree(const int&); //Returns a tree starting at the given vertex using the out-edges. This means every vertex in the tree is reachable from the root.

	vector<vertex<T>> pre_order_traversal(const int&, directed_graph<T>&); // returns the vertices in the visiting order of a pre-order traversal of the tree starting at the given vertex.
	vector<vertex<T>> in_order_traversal(const int&, directed_graph<T>&); // returns the vertices in the visiting order of an in-order traversal of the tree starting at the given vertex.
	vector<vertex<T>> post_order_traversal(const int&, directed_graph<T>&); // returns the vertices in ther visitig order of a post-order traversal of the tree starting at the given vertex.

	vector<vertex<T>> significance_sorting(); // Return a vector containing a sorted list of the vertices in descending order of their significance.

};

// Define all your methods down here (or move them up into the header, but be careful you don't double up). If you want to move this into another file, you can, but you should #include the file here.
// Although these are just the same names copied from above, you may find a few more clues in the full method headers.
// Note also that C++ is sensitive to the order you declare and define things in - you have to have it available before you use it.

template <typename T>	// const
directed_graph<T>::directed_graph() {
}

template <typename T>	// destructor
directed_graph<T>::~directed_graph() {}

template <typename T>	// does graph contain this edge
bool directed_graph<T>::contains(const int& u_id) const {
	if(this->adj_matrix.find(u_id) == this->adj_matrix.end()) return false;
	else return true;
}

template <typename T>	// check if 2 vert is linked/n
bool directed_graph<T>::adjacent(const int& u_id, const int& v_id) {
	if (u_id == v_id) return false;	// no looped edges

	//cout << "finding " << u_id << "  " << v_id;
	unordered_map<int, T> found = this->adj_matrix[u_id];
	for ( auto f : found ) {
		if (f.first == v_id) {
			//cout << " true " << endl;
			return true;
			cout << v_id << " == " << f.first << " " << f.second << endl;
		};
	}
	//cout << " false " << endl;
	return false;

	//if( found[v_id] == 0) {
	//	cout << "return false for " << u_id << " " << v_id << " find\t"<< found[v_id] << endl;
	//	return false;
	//} else {
	//	cout << "return true findTo\t"<< found[v_id] << endl;
	//	return true;
	//};


	//typedef pair<const Key, T> value_type;
	//typename unordered_map<int,T>::iterator it = adj_matrix[u_id].begin();


	//if(this->adj_matrix[u_id].find(v_id) == this->adj_matrix[u_id].end()){
	//	return false;
	//} else return true;


	//return false;
}

template <typename T>	// add vertex
void directed_graph<T>::add_vertex(const vertex<T>& u) {
	if(!this->contains(u.id)){	// if not already added
		vertex_list.insert({u.id, u.weight});
		this->adj_matrix[u.id] = unordered_map<int, T>(); // (key, empty map<key, weight>)
	}
}

template <typename T>	// add edge
void directed_graph<T>::add_edge(const int& u_id, const int& v_id, const T& weight) {

	if (this->contains(u_id) && this->contains(v_id)) {		// check existing vertexes
		if (this->adj_matrix[u_id].find(v_id) == this->adj_matrix[u_id].end()) {	// check existing links
			this->adj_matrix[u_id].insert({v_id, weight});

			//cout << "add\t" << u_id << " " << v_id << " " << adj_matrix[u_id][v_id] << endl;
		}
	}

}

template <typename T>	// remove vertex
void directed_graph<T>::remove_vertex(const int& u_id) {
	if (this->contains(u_id)) {
		this->vertex_list.erase(u_id);			// delet from list
		this->adj_matrix.erase(u_id);				// delet v head from list

		//cout << "\tremoving " << u_id << endl;
		//cout << "\t-------------" << endl;
		for (auto x : this->vertex_list) {		// delet v tail from list
			adj_matrix[x.first].erase(u_id);
		}
	}
}

template <typename T>	// remove edge
void directed_graph<T>::remove_edge(const int& u_id, const int& v_id) {

}

template <typename T>
size_t directed_graph<T>::in_degree(const int& u_id) {
	size_t size = 0;
	if(contains(u_id)) {							// find out_deg from u_id
		for (auto v : this->vertex_list) {	// u_map<id, weight>
			if(this->adj_matrix[v.first].find(u_id) != this->adj_matrix[v.first].end())
				size++;
		}
	}
	//cout << " wtf size " << size << "  ";
	return size;
}

template <typename T>
size_t directed_graph<T>::out_degree(const int& u_id) {
	size_t size = 0;

	if (contains(u_id)) {
		unordered_map<int, T> map = adj_matrix[u_id];

		for (auto v: this->vertex_list ) {
			if(map.find(v.first) != map.end()) size++;
		}
	}

	return size;
}

template <typename T>
size_t directed_graph<T>::degree(const int& u_id) {
	return in_degree(u_id) + out_degree(u_id);
}

template <typename T>	// return num of vertex
size_t directed_graph<T>::num_vertices() const {


	return this->vertex_list.size();

}

template <typename T>	// return num of edges
size_t directed_graph<T>::num_edges() const {
	size_t size = 0;
	for (auto v : adj_matrix) {
		size += v.second.size();
	}
	//cout << "gmm " << size << endl;
	//wrong
	return size;
}

template <typename T>	// list of vertex
vector<vertex<T>> directed_graph<T>::get_vertices() {
	vector<vertex<T>> output_list;

	for(auto v : this->vertex_list) {
		vertex<T> vert(v.first, v.second);
		output_list.push_back(vert);
	}

	return output_list;
}

template <typename T>
vector<vertex<T>> directed_graph<T>::get_neighbours(const int& u_id) {
	vector<vertex<T>> v;
	if (contains(u_id)) {
		//cout << "get n " << u_id << endl;
		for (auto f : this->adj_matrix[u_id]) {
			//cout << " found " << u_id << f.first << " " << f.second << endl;
			vertex<T> n(f.first, f.second);
			v.push_back(n);
		}
	}

	return v;
}

template <typename T>
vector<vertex<T>> directed_graph<T>::get_second_order_neighbours(const int& u_id) { return vector<vertex<T>>(); }

template <typename T>
bool directed_graph<T>::reachable(const int& u_id, const int& v_id) const { return false; }

template <typename T>
bool directed_graph<T>::contain_cycles() const { return false; }

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