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

	size_t vertex_size = 0;
	size_t edge_size = 0;

	int tree_root;

public:
	directed_graph();
	directed_graph(const int&);		// tree root
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
	void pre_order_helper(vector<vertex<T>>&, const int&, bool*);
	vector<vertex<T>> in_order_traversal(const int &, directed_graph<T> &);	  // returns the vertices in the visiting order of an in-order traversal of the tree starting at the given vertex.
	void in_order_helper(vector<vertex<T>>&, const int&, const int&, bool*);
	vector<vertex<T>> post_order_traversal(const int &, directed_graph<T> &); // returns the vertices in ther visitig order of a post-order traversal of the tree starting at the given vertex.
	void post_order_helper(vector<vertex<T>>&, const int&, bool*);

	vector<vertex<T>> significance_sorting(); // Return a vector containing a sorted list of the vertices in descending order of their significance.
};

// Define all your methods down here (or move them up into the header, but be careful you don't double up). If you want to move this into another file, you can, but you should #include the file here.
// Although these are just the same names copied from above, you may find a few more clues in the full method headers.
// Note also that C++ is sensitive to the order you declare and define things in - you have to have it available before you use it.

// =============== const, destr ======================
template <typename T> directed_graph<T>::directed_graph() {}
template <typename T> directed_graph<T>::directed_graph(const int& root_id) {
	this->tree_root = root_id;
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

template <typename T> // ok
bool directed_graph<T>::reachable(const int &u_id, const int &v_id)
{	// true if u->v
	for (vertex<T> v : breadth_first(u_id))
	{	// interchangable between bft and dft
		if (v.id == v_id) return true;
	}

	return false;
}

template <typename T> // ok
bool directed_graph<T>::contain_cycles()
{	// does graph has cycles
	for (auto v : this->vertex_list)	// foreach vertex u in graph
	{
		for (vertex<T> n : get_neighbours(v.first))
		{	// neighbour v can reach u => cycle
			if (reachable(n.id, v.first)) return true;
		}
	}

	return false;
}

template <typename T> // ok
vector<vertex<T>> directed_graph<T>::depth_first(const int &u_id)
{	// dft iterative, same as bft but with stack
	vector<vertex<T>> DFT;
	stack<int> to_visit;

	bool flag[num_vertices() + 1];	// visited flag
	for (int i = 0; i < num_vertices() + 1; i++) { flag[i] = false; }

	to_visit.push(u_id);					// first node
	while (!to_visit.empty())
	{	// while stack is not empty
		int visit = to_visit.top(); 	// pop u from stack
		to_visit.pop();

		if (!flag[visit])
		{	// if u is not visited
			DFT.push_back(get_vertex(visit));
			flag[visit] = true;			// mark u visited

			for (vertex<T> v : get_neighbours(visit))
			{	// for each u neighbour v add to stack if unvisited
				if (!flag[v.id]) { to_visit.push(v.id); }
			}
		}
	}

	return DFT;
}

template <typename T> // ok
vector<vertex<T>> directed_graph<T>::breadth_first(const int &u_id)
{	// bft iterative, same as dft but with queue
	vector<vertex<T>> BFT;
	queue<int> to_visit;

	bool flag[num_vertices() + 1];	// visited flag
	for (int i = 1; i < num_vertices() + 1; i++) { flag[i] = false; }

	to_visit.push(u_id); 				// first node

	while (!to_visit.empty())
	{	// while queue is not empty
		int visit = to_visit.front();	// pop u from queue
		to_visit.pop();

		if (!flag[visit])
		{	// if u is not visited
			BFT.push_back(get_vertex(visit));
			flag[visit] = true;			// visit u

			for (vertex<T> v : get_neighbours(visit))
			{	// for each u neighbour v add to queue if unvisited
				if (!flag[v.id]) to_visit.push(v.id);
			}
		}
	}

	return BFT;
}

// =================================================

template <typename T>
directed_graph<T> directed_graph<T>::out_tree(const int &u_id)
{	// returns a spanning tree
	bool flag[num_vertices() + 1]; // visited checker
	for (int i = 1; i < num_vertices() + 1; i++) { flag[i] = i == u_id; }

	directed_graph<T> tree(u_id);			// create tree with root node
	tree.add_vertex(get_vertex(u_id));

	cout << "======\n";
	cout << "printing tree root 1\n";

	for (vertex<T> v : get_neighbours(u_id))
	{	// foreach neighbours of root
		out_tree_helper(tree, u_id, v.id, flag);
	}

	return tree;
}

template <typename T>
void directed_graph<T>::out_tree_helper(directed_graph<T> &tree, const int &parent_id, const int &child_id, bool* flag)
{	// recursive dft function for out_tree
	if(!flag[child_id])
	{	// if child not visited
		flag[child_id] = true;
		cout << "> branch of " << parent_id << " : (" << child_id << ")\n";
		// add child vertex, parent-> child edge
		tree.add_vertex(get_vertex(child_id));
		tree.add_edge(parent_id, child_id, this->adj_list[parent_id][child_id]);

		// child is now new parent
		for (vertex<T> v : get_neighbours(child_id)) {
			out_tree_helper(tree, child_id, v.id, flag);
		}
	}
};

template <typename T>
vector<vertex<T>> directed_graph<T>::pre_order_traversal(const int &u_id, directed_graph<T> &tree)
{	// return vector of vertex in in preorder traversal
	//return mst.depth_first(mst.tree_root); this definitely works but lets do recursive

	bool flag[num_vertices() + 1]; // visited checker
	for (int i = 1; i < num_vertices() + 1; i++) { flag[i] = i == u_id; }

	vector<vertex<T>> pre_order;
	pre_order.push_back(tree.get_vertex(tree.tree_root));		// u_id as root_id is redundant

	for (vertex<T> v : get_neighbours(tree.tree_root))
	{	// foreach neighbours of root
		pre_order_helper(pre_order, v.id, flag);

	}

	return pre_order;
}

template <typename T>
void directed_graph<T>::pre_order_helper(vector<vertex<T>>& pre_order, const int& child_id, bool* flag)
{	// same as dsf
	if(!flag[child_id]) {
		flag[child_id] = true;

		pre_order.push_back(get_vertex(child_id));

		for (vertex<T> v : get_neighbours(child_id)) {
			pre_order_helper(pre_order, v.id, flag);
		}
	}
}

template <typename T>
vector<vertex<T>> directed_graph<T>::in_order_traversal(const int &u_id, directed_graph<T> &tree) {
	bool flag[num_vertices() + 1]; // visited checker
	for (int i = 1; i < num_vertices() + 1; i++) { flag[i] = false; }

	vector<vertex<T>> in_order;

	for (vertex<T> v : get_neighbours(tree.tree_root))
	{	// foreach neighbours of root
		in_order_helper(in_order, tree.tree_root, v.id, flag);
	}

	return in_order;
}

template <typename T>
void directed_graph<T>::in_order_helper(vector<vertex<T>>& in_order, const int& parent_id, const int& child_id, bool* flag) {
	if(!flag[child_id]) {
		vector<vertex<T>> n = get_neighbours(child_id);

		if(n.size() == 0) {			// add leaf
			flag[child_id] = true;
			in_order.push_back(get_vertex(child_id));
			cout << "leaf added " << child_id << endl;
		} else {	// n.size > 0
			for (vertex<T> v : get_neighbours(child_id)) {
				in_order_helper(in_order, child_id, v.id, flag);
			}
		}

		if(!flag[parent_id]) {		// add branch
			flag[parent_id] = true;
			in_order.push_back(get_vertex(parent_id));
		}
	}
}

template <typename T>
vector<vertex<T>> directed_graph<T>::post_order_traversal(const int &u_id, directed_graph<T> &tree)
{
	bool flag[num_vertices() + 1]; // visited checker
	for (int i = 1; i < num_vertices() + 1; i++) { flag[i] = false; }
	vector<vertex<T>> post_order;

	for (vertex<T> v : get_neighbours(tree.tree_root))
	{	// foreach neighbours of root
		post_order_helper(post_order, v.id, flag);
	}

	post_order.push_back(get_vertex(u_id));
	cout << "what " << u_id << " " << flag[u_id] << endl;

	return post_order;
}

template <typename T>
void directed_graph<T>::post_order_helper(vector<vertex<T>>& post_order, const int& u_id, bool* flag) {
	if(!flag[u_id]) {

		for (vertex<T> v : get_neighbours(u_id))
		{	// foreach neighbours of root
			post_order_helper(post_order, v.id, flag);
		}

		post_order.push_back(get_vertex(u_id));
		cout << "pushed " << u_id << endl;
		flag[u_id] = true;
	}
}

template <typename T>
vector<vertex<T>> directed_graph<T>::significance_sorting() {
	vector<vertex<T>> sig_sort;



	return sig_sort;
}


#endif