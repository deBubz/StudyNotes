#ifndef DIRECTED_GRAPH_H
#define DIRECTED_GRAPH_H

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>

using namespace std;

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

/*
	the graph class
*/
template <typename T>
class directed_graph
{

private:
	unordered_map<int, T> vertex_list;
	unordered_map<int, unordered_map<int, T>> adj_list;

	size_t vertex_size;
	size_t edge_size;

public:
	directed_graph();
	~directed_graph();

	// ======= helper functions ===========
	// ok
	bool contains(const int &) const;
	bool adjacent(const int &, const int &);


	// ok
	void add_vertex(const vertex<T> &);						 //Adds the passed in vertex to the graph (with no edges).
	void add_edge(const int &, const int &, const T &); //Adds a weighted edge from the first vertex to the second.

	// ok
	void remove_vertex(const int &);				  //Removes the given vertex. Should also clear any incident edges.
	void remove_edge(const int &, const int &); //Removes the edge between the two vertices, if it exists.

	// ok
	size_t in_degree(const int &);  //Returns number of edges coming in to a vertex.
	size_t out_degree(const int &); //Returns the number of edges leaving a vertex.
	size_t degree(const int &);	  //Returns the degree of the vertex (both in edges and out edges).

	// ok
	size_t num_vertices() const; //Returns the total number of vertices in the graph.
	size_t num_edges() const;	  //Returns the total number of edges in the graph.

	// helper methods
	// get vertex by id

	// ok

	vertex<T> get_vertex(const int&);
	vector<vertex<T>> get_vertices();									//Returns a vector containing all the vertices.
	vector<vertex<T>> get_neighbours(const int &);					//Returns a vector containing all the vertices reachable from the given vertex. The vertex is not considered a neighbour of itself.
	vector<vertex<T>> get_second_order_neighbours(const int &); // Returns a vector containing all the second_order_neighbours (i.e., neighbours of neighbours) of the given vertex.
																					// A vector cannot be considered a second_order_neighbour of itself.
	// done
	bool reachable(const int &, const int &); //Returns true if the second vertex is reachable from the first (can you follow a path of out-edges to get from the first to the second?). Returns false otherwise.
	bool contain_cycles();							// Return true if the graph contains cycles (there is a path from any vertices directly/indirectly to itself), false otherwise.

	// done
	vector<vertex<T>> depth_first(const int &);	 //Returns the vertices of the graph in the order they are visited in by a depth-first traversal starting at the given vertex.
	vector<vertex<T>> breadth_first(const int &); //Returns the vertices of the graph in the order they are visisted in by a breadth-first traversal starting at the given vertex.

	// todo
	directed_graph<T> out_tree(const int &); //Returns a tree starting at the given vertex using the out-edges. This means every vertex in the tree is reachable from the root.
	void out_tree_helper(directed_graph<T> &, const int &, const int &, bool*);

	vector<vertex<T>> pre_order_traversal(const int &, directed_graph<T> &);  // returns the vertices in the visiting order of a pre-order traversal of the tree starting at the given vertex.
	vector<vertex<T>> in_order_traversal(const int &, directed_graph<T> &);	  // returns the vertices in the visiting order of an in-order traversal of the tree starting at the given vertex.
	vector<vertex<T>> post_order_traversal(const int &, directed_graph<T> &); // returns the vertices in ther visitig order of a post-order traversal of the tree starting at the given vertex.

	vector<vertex<T>> significance_sorting(); // Return a vector containing a sorted list of the vertices in descending order of their significance.
};

// Define all your methods down here (or move them up into the header, but be careful you don't double up). If you want to move this into another file, you can, but you should #include the file here.
// Although these are just the same names copied from above, you may find a few more clues in the full method headers.
// Note also that C++ is sensitive to the order you declare and define things in - you have to have it available before you use it.

// =============== const, destr ======================
template <typename T> directed_graph<T>::directed_graph() {
	this->vertex_size = 0;
	this->edge_size = 0;
}
template <typename T> directed_graph<T>::~directed_graph() {}

// ============== helper functions ===================

template <typename T> // ok
bool directed_graph<T>::contains(const int &u_id) const
{	// check if graph contains vertex u
	return this->vertex_list.find(u_id) != this->vertex_list.end();
}

template <typename T> // ok
bool directed_graph<T>::adjacent(const int &u_id, const int &v_id)
{	// check if graph contains u->v
	if (contains(u_id) && contains(v_id) && (u_id != v_id))
	{	// check if exist u or v, no looped edges u->u
		return this->adj_list[u_id].find(v_id) != this->adj_list[u_id].end();
	}
	return false;
}

template <typename T> // ok
void directed_graph<T>::add_vertex(const vertex<T> &u)
{
	if (!contains(u.id))
	{	// add vertex if not exist
		this->vertex_list.insert({u.id, u.weight});		// into list
		this->adj_list[u.id] = unordered_map<int, T>(); // map<uid, (empty map<key, weight>)>
		this->vertex_size++;
	}
}

template <typename T> // ok
void directed_graph<T>::add_edge(const int &u_id, const int &v_id, const T &weight)
{	// add edge u->v with weight
	if (contains(u_id) && contains(v_id) && !adjacent(u_id, v_id))
	{ // check if edge exist, edge doenst
		this->adj_list[u_id].insert({v_id, weight});
		this->edge_size++;
	}
}

template <typename T> // ok
void directed_graph<T>::remove_vertex(const int &u_id)
{	// remove vertex u
	if (contains(u_id))
	{	// if vertex exist
		this->vertex_list.erase(u_id);	// delete u from vertex_list
		this->adj_list.erase(u_id);		// delete u-> v from adj_list

		for (auto v : this->vertex_list)	// pair<int, T>
		{	// delete edges v->u
			this->adj_list[v.first].erase(u_id);
		}
		this->vertex_size--;
	}
}

template <typename T> // ok
void directed_graph<T>::remove_edge(const int &u_id, const int &v_id)
{	// remove edge u->v
	if (adjacent(u_id, v_id))
	{
		this->adj_list[u_id].erase(v_id);
		this->edge_size--;
	}
}

template <typename T> // ok
size_t directed_graph<T>::in_degree(const int &u_id)
{	// returns in_degrees to u
	size_t size = 0;
	if (contains(u_id))
	{
		for (auto v : this->vertex_list)
		{	// for each vertex v, if v->u exist
			if (this->adj_list[v.first].find(u_id) != this->adj_list[u_id].end())
				size++;
		}
	}
	return size;
}

template <typename T> // ok
size_t directed_graph<T>::out_degree(const int &u_id)
{	// out degree from u
	return (contains(u_id)) ? this->adj_list[u_id].size() : 0;
}

template <typename T> // ok
size_t directed_graph<T>::degree(const int &u_id)
{	// total in + out degrees
	return in_degree(u_id) + out_degree(u_id);
}

template <typename T> // ok
vertex<T> directed_graph<T>::get_vertex(const int &u_id)
{	// returns a copy of vector obj from vertex_list
	return vertex<T>(u_id, this->vertex_list[u_id]);
}

template <typename T> // ok
size_t directed_graph<T>::num_vertices() const
{
	return this->vertex_size;
}

template <typename T> // ok
size_t directed_graph<T>::num_edges() const
{
	return this->edge_size;
}

template <typename T> // ok
vector<vertex<T>> directed_graph<T>::get_vertices()
{	// return vector of vertices
	vector<vertex<T>> vertices;

	for (auto v : this->vertex_list)
	{	// converting map to vector
		vertices.push_back(vertex<T>(v.first, v.second));
	}

	return vertices;
}

template <typename T> // ok
vector<vertex<T>> directed_graph<T>::get_neighbours(const int &u_id)
{	// get all v for u->v
	vector<vertex<T>> neighbours;

	if (contains(u_id))
	{
		for (auto v : this->adj_list[u_id])
		{
			neighbours.push_back(vertex<T>(v.first, v.second));
		}
	}

	return neighbours;
}

template <typename T> // second neighbours
vector<vertex<T>> directed_graph<T>::get_second_order_neighbours(const int &u_id)
{
	vector<vertex<T>> sec_o_neighbours;

	// setting up flags for added verts
	bool flag[num_vertices() + 1];
	for (int i = 1; i < num_vertices() + 1; i++)
	{ flag[i] = (i == u_id); }

	for (vertex<T> v1 : get_neighbours(u_id))
	{
		for (vertex<T> v2 : get_neighbours(v1.id))
		{	// foreach 2_o_neighbour of 1_o_neighbour of u
			if ((v2.id != u_id) && !flag[v2.id])
			{	// cannot be itself and not yet added
				sec_o_neighbours.push_back(v2);
				flag[v2.id] = true;		//add & mark added
			}
		}
	}

	return sec_o_neighbours;
}

template <typename T> // true if u can reach v
bool directed_graph<T>::reachable(const int &u_id, const int &v_id)
{
	if (adjacent(u_id, v_id)) return true;

	for (auto v : breadth_first(u_id))
	{
		if (v.id == v_id)
		{
			return true;
		}
	}

	return false;
}

template <typename T> // true if graph have any cycles
bool directed_graph<T>::contain_cycles()
{
	// should be the same as reachable
	// for each vertex v in graph
	// can the neighbour u reach v
	for (auto v : this->vertex_list)
	{ // map(int, T)
		for (vertex<T> n : get_neighbours(v.first))
		{ // vertex
			if (reachable(n.id, v.first))
				return true;
		}
	}
	return false;
}

template <typename T>
vector<vertex<T>> directed_graph<T>::depth_first(const int &u_id)
{
	// could break for unconnected
	vector<vertex<T>> DFT;
	stack<int> to_visit;

	bool flag[num_vertices() + 1];
	// setting up flags for visited verts
	for (int i = 0; i < num_vertices() + 1; i++) {
		flag[i] = false;
	}

	to_visit.push(u_id);
	while (!to_visit.empty())
	{
		// pop from stack
		int visit = to_visit.top(); // u
		to_visit.pop();

		if (!flag[visit])
		{
			DFT.push_back(get_vertex(visit));
			// visit u
			flag[visit] = true;
		}

		for (vertex<T> v : get_neighbours(visit))
		{
			// add to stack if unvisited
			if (!flag[v.id])
			{
				to_visit.push(v.id);
			}
		}
	}

	return DFT;
}

template <typename T>
vector<vertex<T>> directed_graph<T>::breadth_first(const int &u_id)
{
	// could break for
	vector<vertex<T>> BFT; // output

	queue<int> to_visit;				 // queue for bft
	bool flag[num_vertices() + 1]; // visited checker
	for (int i = 1; i < num_vertices() + 1; i++)
	{
		flag[i] = false;
	}

	to_visit.push(u_id); // first node

	while (!to_visit.empty())
	{
		// pop from queue
		int visit = to_visit.front(); // u
		to_visit.pop();

		if (!flag[visit])
		{
			BFT.push_back(get_vertex(visit));
			flag[visit] = true;
		} // visit u

		for (vertex<T> v : get_neighbours(visit))
		{
			// add to stack if unvisited
			if (!flag[v.id])
			{
				to_visit.push(v.id);
			}
		}
	}
	return BFT;
}

// =================================================

template <typename T>
directed_graph<T> directed_graph<T>::out_tree(const int &u_id)
{
	directed_graph<T> tree;

	bool flag[num_vertices() + 1]; // visited checker
	for (int i = 1; i < num_vertices() + 1; i++) { flag[i] = i == u_id; }

	// dfs recursive
	// root node
	tree.add_vertex(get_vertex(u_id));

	for (vertex<T> v : get_neighbours(u_id))
	{	// foreach neighbours of root
		out_tree_helper(tree, u_id, v.id, flag);
		// pass tree, parent, child, flag[]
	}
	return tree;
}

template <typename T> // recursive dft for out_tree
void directed_graph<T>::out_tree_helper(directed_graph<T> &tree, const int &parent_id, const int &child_id, bool* flag)
{
	//cout << child_id << " is visited? " << flag[child_id] << endl;
	if(!flag[child_id]) {
		flag[child_id] = true;	// mark visited
		// add parent, child vertex
		tree.add_vertex(get_vertex(parent_id));
		tree.add_vertex(get_vertex(child_id));
		// add edge parent -> child
		tree.add_edge(parent_id, child_id, this->adj_list[parent_id][child_id]);

		// child now is newParent
		int newParent = child_id;

		for (vertex<T> v : get_neighbours(newParent)) {
			out_tree_helper(tree, newParent, v.id, flag);
		}	// recursive
	}
};

// ====================================================

//template <typename T>
//directed_graph<T> directed_graph<T>::out_tree(const int& u_id) {

//}

// ====================================================

template <typename T>
vector<vertex<T>> directed_graph<T>::pre_order_traversal(const int &u_id, directed_graph<T> &mst) { return vector<vertex<T>>(); }

template <typename T>
vector<vertex<T>> directed_graph<T>::in_order_traversal(const int &u_id, directed_graph<T> &mst) { return vector<vertex<T>>(); }

template <typename T>
vector<vertex<T>> directed_graph<T>::post_order_traversal(const int &u_id, directed_graph<T> &mst) { return vector<vertex<T>>(); }

template <typename T>
vector<vertex<T>> directed_graph<T>::significance_sorting() { return vector<vertex<T>>(); }

#endif