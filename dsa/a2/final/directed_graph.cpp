#include "directed_graph.hpp"

/**
 *	Method definitions of directed_graph class
 */

// ===================================================
// ====            public functions               ====
// ===================================================

// ===================================================
// =============== const, destr ======================

/**
 * Basic constructor for directed graph
 */
template <typename T> directed_graph<T>::directed_graph() {}

/**
 * Basic constructor for a spanning tree
 *
 * @param root_id - stores the int id for the root vertex of the tree
 */
template <typename T> // tree constructor
directed_graph<T>::directed_graph(const int& root_id) { this->tree_root = root_id; }

/**
 * Basic destructor for directed graph
 */
template <typename T> directed_graph<T>::~directed_graph() {}


// ===================================================
// ============== helper functions ===================

/**
 * Checks the graph if a vertex exist in the graph
 *
 * @param u_id - int id of the vertex
 * @return true if the graph contains vertex of u_id
 *         false if otherwise
 */
template <typename T>
bool directed_graph<T>::contains(const int &u_id) const {
	return this->vertex_list.find(u_id) != this->vertex_list.end();
}

/**
 * Checks the graph if it contains an edge from u to v
 *
 * Also check if vertex u and v exist
 * and if the user wants a looped edge, requirements assumed there are no loop edge
 *
 * @param u_id - int id of the starting vertex
 * @param v_id - int id of the vertex which vertex u points to
 * @return true if the graph contains the edge from vertex u to vertex v
 * 		   false if otherwise, or if vertex u or v does not exist,
			  or if user wants to check for looped edge
 */
template <typename T>
bool directed_graph<T>::adjacent(const int &u_id, const int &v_id) {
	// check if there exist u or v
	// checks for looped edges u->u as requirements assumed there are no loop edges
	if (contains(u_id) && contains(v_id) && (u_id != v_id))
	{
		return this->adj_list[u_id].find(v_id) != this->adj_list[u_id].end();
	}
	return false;
}


// ------------ add functions ------------------------
/**
 * Adds a vertex into the graph.
 *
 * First checks if vertex already exist or not to prevent dupes
 * If not, adds to vertex list, adjacency list and increase vertex counter
 *
 * @param vertex - vertex type T to be added into the graph
 */
template <typename T>
void directed_graph<T>::add_vertex(const vertex<T> &u) {
	if (!contains(u.id)) {
		this->vertex_list.insert({u.id, u.weight});
		this->adj_list[u.id] = unordered_map<int, T>();
		this->vertex_size++;

		cout << "Added: " << u.id << endl;
	}
}

/**
 * Adds an edge of vertex u to v and its weight into graph's adjacency list
 *
 * Nothing will be added if vertex v or u does not exist or if there exist edge u to v
 * user tries to add a looped edge, as requirements assume graph does not contains any.
 *
 * @param u_id - int id of the starting vertex
 * @param v_id - int id of the vertex which vertex u points to
 * @param weight - type T weight of the edge from vertex u to v
 */
template <typename T> // ok
void directed_graph<T>::add_edge(const int &u_id, const int &v_id, const T &weight) {
	// can not just use adjacent to check if ther exist u or v even
	// even though adjacent also checks for existing vertex
	// !adjacent will return true if edge DONT exist and will be added into adjacency list

	if (contains(u_id) && contains(v_id) && !adjacent(u_id, v_id)) {
		this->adj_list[u_id].insert({v_id, weight});
		this->edge_size++;

		cout << "Edge: " << u_id << " - " << v_id << " w: " << weight << endl;
	}
}


// ------------ remove functions ---------------------
/**
 * Remove vertex by id from the graph
 *
 * If the vertex exist, remove from the vetex list and adjacency matrix and decrease vertex count
 * Also remove any edges points to the removing vertex
 *
 * @param u_id - int id of removing vertex
 */
template <typename T>
void directed_graph<T>::remove_vertex(const int &u_id) {
	if (contains(u_id)) {
		this->vertex_list.erase(u_id);
		this->adj_list.erase(u_id);

		for (auto v : this->vertex_list) {		// pair<int, T>
			this->adj_list[v.first].erase(u_id);
		}
		// v-> u
		this->vertex_size--;
	}
}

/**
 * Remove edge from vertex u to v from graph
 *
 * If the edge exist, remove edge from adjacency list and decrement edge count
 *
 * @param u_id - int id of removing edge starting point
 * @param v_id - int id of removing edge end point
 */
template <typename T>
void directed_graph<T>::remove_edge(const int &u_id, const int &v_id) {
	if (adjacent(u_id, v_id)) {
		this->adj_list[u_id].erase(v_id);
		this->edge_size--;
	}
}


// ------------ degree count functions ---------------
/**
 * Returns the in degree count of given vertex id, if the vertex exists
 *
 * @param u_id - int id chosen vertex
 * @return count of in degree from given id vertex u
 *		   -1 if the vertex does not exist
 */
template <typename T> // ok
size_t directed_graph<T>::in_degree(const int &u_id) {
	size_t size = 0;

	if (contains(u_id)) {
		for (auto v : this->vertex_list) {
			// checks if vertex u is an endpoint of any edges (v, u)
			if (this->adj_list[v.first].find(u_id) != this->adj_list[u_id].end())
				size++;
		}
	}
	else size = -1;

	return size;
}

/**
 * Returns the out degree count of given vertex id, if the vertex exists
 *
 * @param u_id - int id chosen vertex
 * @return count of out degree from given id vertex u
 *		   -1 if the vertex does not exist
 */
template <typename T>
size_t directed_graph<T>::out_degree(const int &u_id) {
	return (contains(u_id)) ? this->adj_list[u_id].size() : -1;
}

/**
 * Returns the total number of degree(both out and in) count of given vertex id, if the vertex exists
 *
 * @param u_id - int id chosen vertex
 * @return count of total degree from given id vertex u
 *		   -2 if the vertex does not exist
 */
template <typename T>
size_t directed_graph<T>::degree(const int &u_id)
{	// total in + out degrees
	return in_degree(u_id) + out_degree(u_id);
}


// ------------ get size functions -------------------
/**
 * Returns the number of vertices in the graph
 *
 * @return Count of vertices in graph
 */
template <typename T>
size_t directed_graph<T>::num_vertices() const { return this->vertex_size; }

/**
 * Returns the number of edges in graph
 *
 * @return Count of edges in graph
 */
template <typename T>
size_t directed_graph<T>::num_edges() const { return this->edge_size; }


// ------------ get functions ------------------------
/**
 * Returns the vertex object of given id
 *
 * @param u_id - int id chosen vertex
 * @return vetex object of given id if it exist,
		   else return an empty vertex object
 */
template <typename T> // ok
vertex<T> directed_graph<T>::get_vertex(const int &u_id) {
	return vertex<T>(u_id, this->vertex_list[u_id]);
}

/**
 * Returns a vector of all vertices in the graph
 *
 * @return Vector of all vertices in the graph
 */
template <typename T> // ok
vector<vertex<T>> directed_graph<T>::get_vertices() {
	vector<vertex<T>> vertices;

	// for each id, weight pair in vertex list, adds a vertex object into the output vector
	for (auto v : this->vertex_list) {		// pair<int, T>
		vertices.push_back(vertex<T>(v.first, v.second));
	}

	return vertices;
}

/**
 * Returns the edge weight of u_id -> v_id
 *
 * @param u_id - first u_id
 * @param v_id - second v_iud
 * @return weight of u -> v
 */
template <typename T>
T directed_graph<T>::get_edge(const int& u_id, const int& v_id) {
	return this->adj_list[u_id][v_id];
}


// ------------ neighbours functions -----------------
/**
 * Returns a vector of the neighbouring vertex of given vertex id
 *
 * @param u_id - int id chosen vertex
 * @return Vector of the neighbouring vertex
 */
template <typename T>
vector<vertex<T>> directed_graph<T>::get_neighbours(const int &u_id) {
	vector<vertex<T>> neighbours;

	if (contains(u_id)) {
		for (auto v : this->adj_list[u_id]) {		// pair<int, T>
			neighbours.push_back(vertex<T>(v.first, v.second));
		}
	}

	return neighbours;
}

/**
 * Returns a vector of 2nd order neighbours(neighbour of neighbours) of chosen vertex id
 * The chosen vertex cannot be a 2nd order neighbour to itself
 *
 * @param u_id - int id chosen vertex
 * @return vetex object of given id if it exist,
		   else return an empty vertex object
 */
template <typename T>
vector<vertex<T>> directed_graph<T>::get_second_order_neighbours(const int &u_id)
{
	vector<vertex<T>> sec_o_neighbours;

	bool flag[num_vertices() + 1];		// to keep track of added vertexes
	for (int i = 1; i < num_vertices() + 1; i++)
	{ flag[i] = (i == u_id); }			// to prevent adding the chosen vertex as per requirements



	for (vertex<T> v1 : get_neighbours(u_id)) {
		// foreach neighbour(v1) of chosen vertex
		for (vertex<T> v2 : get_neighbours(v1.id)) {
			// foreach neighbour(v2) of chosen vertex's neighbours(v1)
			if (!flag[v2.id]) {
				sec_o_neighbours.push_back(v2);
				flag[v2.id] = true;
				// add 2nd neighbour vertex and mark added into list
			}
		}
	}

	return sec_o_neighbours;
}


// ===================================================
// =============== cycles ============================
/**
 * Checks if vertex u can travel and reach vertex v
 *
 * Using BFT path to determine this
 * If v is on the path of BFT from u, vertex u can reach v
 *
 * Can use either BFT or DFT
 *
 * @param u_id - int id of chosen starting vertex
 * @param v_id - int id of chosen vertex if starting vertex can reach
 * @return true if vertex u can reach vertex v
 */
template <typename T>
bool directed_graph<T>::reachable(const int &u_id, const int &v_id) {
	for (vertex<T> v : breadth_first(u_id))
	{	// interchangable between bft and dft
		if (v.id == v_id) return true;
	}

	return false;
}

/**
 * Check if the grapg contains a cycle
 *
 * Construct under the theory of for a vertex u,
 * if its neighbour v has a path back to u (reachable(u, v))
 * the graph contains a cycle
 *
 * Comment: this implementation while works, is bad in time complexity
 *			as it runs bft for every neighbour of every vertex in the graph
 *
 * @return true the graph contains a cycle
 *		   false if otherwise
 */
template <typename T>
bool directed_graph<T>::contain_cycles() {
	for (auto u : this->vertex_list) {		// pair<int, T>
		// for each vertex u in the graph
		for (vertex<T> v : get_neighbours(u.first)) { // n m
			// can neighbour v reach u
			if (reachable(v.id, u.first)) return true;
		}
	}
	// u
	// v
	// v -> u


	return false;
}

// ===================================================
// =============== graph traversals ==================
/**
 * Returns a vector of vertex ordered in depth first traversal order starting from a given vertex id
 *
 * Implemented DFT itteratively based on pseudo code from lecture 5 slides
 * Same implementation itterative BFT but using stack instead of queue
 *
 * @param u_id - int id of chosen starting vertex
 * @return Vector of vertex in order of DFT
 */
template <typename T> // ok
vector<vertex<T>> directed_graph<T>::depth_first(const int &u_id) {
	vector<vertex<T>> DFT;
	stack<int> to_visit;

	bool flag[num_vertices() + 1];	// visited flag
	for (int i = 0; i < num_vertices() + 1; i++) { flag[i] = false; }

	to_visit.push(u_id);					// first node
	while (!to_visit.empty()) {
		int visit = to_visit.top(); 		// pop u from stack
		to_visit.pop();

		if (!flag[visit]) {					// add u and mark visited if not visited
			DFT.push_back(get_vertex(visit));
			flag[visit] = true;

			for (vertex<T> v : get_neighbours(visit)) {
				// for each u neighbour v add to stack if not visited
				if (!flag[v.id]) { to_visit.push(v.id); }
			}
		}
	}

	return DFT;
}

/**
 * Returns a vector of vertex ordered in breadth first traversal order starting from a given vertex id
 *
 * Implemented BFT itteratively based on pseudo code from lecture 5 slides
 * Same implementation itterative DFT but using queue instead of stack
 *
 * @param u_id - int id of chosen starting vertex
 * @return Vector of vertex in order of DFT
 */
template <typename T> // ok
vector<vertex<T>> directed_graph<T>::breadth_first(const int &u_id) {
	vector<vertex<T>> BFT;
	queue<int> to_visit;

	//bool flag[num_vertices() + 1];	// visited flag
	//for (int i = 1; i < num_vertices() + 1; i++) { flag[i] = false; }

	unordered_map<int, bool> flag;
	for(auto v : this->vertex_list) {		// pair <vector, visit bool>
		flag[v.first] = false;
	}

	to_visit.push(u_id); 					// first node

	while (!to_visit.empty()) {
		int visit = to_visit.front();		// pop u from queue
		to_visit.pop();

		if (!flag[visit]) {					// add u and mark visited if not visited
			BFT.push_back(get_vertex(visit));
			flag[visit] = true;

			for (vertex<T> v : get_neighbours(visit)) {
				// for each u neighbour v add to queue if unvisited
				if (!flag[v.id]) to_visit.push(v.id);
			}
		}
	}

	return BFT;
}


// ===================================================
// =============== tree ==============================
/**
 * Return a directed graph object that represents a tree with given vertex id as root
 *
 * Tree built from a modified recursive DFT implementation
 * Based on pseudo code in slide 5
 *
 * NOTE: out_tree_helper is private
 *
 * @param u_id - int id of chosen root vertex
 * @return Directed graph object representing a tree
 */
template <typename T>
directed_graph<T> directed_graph<T>::out_tree(const int &u_id) {
	bool flag[num_vertices() + 1]; // visited checker
	for (int i = 1; i < num_vertices() + 1; i++) { flag[i] = (i == u_id); }

	// create tree in
	directed_graph<T> tree(u_id);
	tree.add_vertex(get_vertex(u_id));

	// see NOTE for out_tree_helper
	for (vertex<T> v : get_neighbours(u_id)) {
		// u_id the root is sent as "parent node"
		// v.id neighbours of root is sent as "child node"
		// this is to keep track of what edges to add
		out_tree_helper(tree, u_id, v.id, flag);
	}

	return tree;
}


// ------------ tree df traversals -------------------
/**
 *	Note on tree df traversal paths:
 * 	  - All 3 traversal paths are built on modified recursive DFT implementations
 *	  - Direction of traversal is not considered since the tree is not assumed to be a binary tree
 * 	  - The param u_id is technically not required in my class design
 * 		 as I added a variable in the class to keep track of the tree root
 *    - Any instance of u_id is replacable with tree.tree_root
 *
 */

/**
 * Returns a vector of vertex ordered in the path of DFT PRE ORDER traversal
 *
 * Based on a youtube video "Pre-order tree traversal in 3 min" as reference
 * src: https://youtu.be/1WxLM2hwL-U
 *
 * NOTE: pre_order_helper is private
 *
 * @param u_id - int id of root vertex/starting vertex of traversal
 * @param tree - tree object to base the traversal path to
 * @return Vector of vertex ordered in path of DFT pre order traversal
 */
template <typename T>
vector<vertex<T>> directed_graph<T>::pre_order_traversal(const int &u_id, directed_graph<T> &tree) {
	// return tree.depth_first(u_id); this definitely works but lets do recursive

	bool flag[num_vertices() + 1]; // visited checker
	for (int i = 1; i < num_vertices() + 1; i++) { flag[i] = (i == u_id); }

	// adds root as first in traversal order
	vector<vertex<T>> pre_order;
	pre_order.push_back(tree.get_vertex(u_id));

	// see NOTE
	for (vertex<T> v : get_neighbours(u_id)) {	// travel down to neighbour nodes
		pre_order_helper(pre_order, v.id, flag);
	}

	return pre_order;
}


/**
 * Returns a vector of vertex ordered in the path of DFT IN ORDER traversal
 *
 * Based on a youtube video "In-order tree traversal in 3 min" as reference
 * src: https://youtu.be/5dySuyZf9Qg
 *
 * NOTE: in_order_helper is private
 *
 * @param u_id - int id of root vertex/starting vertex of traversal
 * @param tree - tree object to base the traversal path to
 * @return Vector of vertex ordered in path of DFT in order traversal
 */
template <typename T>
vector<vertex<T>> directed_graph<T>::in_order_traversal(const int &u_id, directed_graph<T> &tree) {
	bool flag[num_vertices() + 1]; // visited checker
	for (int i = 1; i < num_vertices() + 1; i++) { flag[i] = false; }

	vector<vertex<T>> in_order;

	// l b l r l b l

	// see NOTE
	for (vertex<T> v : get_neighbours(tree.tree_root)) {	// travel down to neighbour nodes
		in_order_helper(in_order, u_id, v.id, flag);
	}

	return in_order;
}


/**
 * Returns a vector of vertex ordered in the path of DFT IN ORDER traversal
 *
 * Based on a youtube video "Post-order tree traversal in 2 min" as reference
 * src: https://youtu.be/4zVdfkpcT6U
 *
 * NOTE: post_order_helper is private
 *
 * @param u_id - int id of root vertex/starting vertex of traversal
 * @param tree - tree object to base the traversal path to
 * @return Vector of vertex ordered in path of DFT in order traversal
 */
template <typename T>
vector<vertex<T>> directed_graph<T>::post_order_traversal(const int &u_id, directed_graph<T> &tree)
{
	bool flag[num_vertices() + 1]; // visited checker
	for (int i = 1; i < num_vertices() + 1; i++) { flag[i] = false; }
	vector<vertex<T>> post_order;

	// see NOTE
	for (vertex<T> v : get_neighbours(tree.tree_root)) { // travel down to neighbour nodes
		post_order_helper(post_order, v.id, flag);
	}

	//  l l b l l b r

	// root as the last visited node in path
	post_order.push_back(get_vertex(u_id));

	return post_order;
}

// ===================================================
// =============== sorting ===========================

/**
 * Create a vector of vertex sorted by their weights in descending order
 *
 * used std::sort() from <algorithms> standard library
 * http://www.cplusplus.com/reference/algorithm/sort/
 *
 * @return Vector of vetex sorted by weight in descending order
 */
template <typename T>
vector<vertex<T>> directed_graph<T>::significance_sorting() {
	// list of vertex in graph/tree
	vector<vertex<T>> sig_sort = get_vertices();

	// sort sig_sort between the range of the first element to the last element
	// using a lamda comparator to indicate a descending order
	sort(sig_sort.begin(), sig_sort.end(),[](vertex<T> u, vertex<T> v){ return u.weight > v.weight; }); // desc

	return sig_sort;
}



// ===================================================
// ====            private functions              ====
// ===================================================


/**
 * Recursive helper function for out_tree
 * To add vertices and edges into tree.
 *
 * @param tree - directed_graph object to add child vertex, and edges (parent, child) to
 * @param parent_id - int id parent vertex
 * @param child_id - int id of vertex neighbouring to parent vertex
 * @param flag - boolean array to check added vertex
 */
template <typename T>
void directed_graph<T>::out_tree_helper(directed_graph<T> &tree, const int &parent_id, const int &child_id, bool* flag) {
	// end condition if vertex of child_id is already added
	// escapes to parent vertex
	if(!flag[child_id]) {	// if the child vertex is not visited
		flag[child_id] = true;

		// add child vertex and edge (parent, child)
		tree.add_vertex(get_vertex(child_id));
		tree.add_edge(parent_id, child_id, this->adj_list[parent_id][child_id]);

		// child is now new parent
		for (vertex<T> v : get_neighbours(child_id)) {
			out_tree_helper(tree, child_id, v.id, flag);
		}
	}
};

// ------------ tree dft traversals ------------------
/**
 * Recursive helper function to for pre_order_traversal
 *
 * @param pre_order - vector of vertex create travel path
 * @param child_id - id of current vector to add if not visited
 * @param flag - boolean array to check visited
 */
template <typename T>
void directed_graph<T>::pre_order_helper(vector<vertex<T>>& pre_order, const int& child_id, bool* flag) {
	// end condition, vector with child_id is already added
	if(!flag[child_id]) {		// if not visited, add vector and mark visited
		flag[child_id] = true;
		pre_order.push_back(get_vertex(child_id));

		// travel down to next neighbours
		for (vertex<T> v : get_neighbours(child_id)) {
			pre_order_helper(pre_order, v.id, flag);
		}
	}
}

/**
 * Recursive helper function for in_order_traversal
 *
 * @param in_order - vector of vertex create travel path
 * @param parent_id - int id parent vertex
 * @param child_id - int id of vertex neighbouring to parent vertex
 * @param flag - boolean array to check added vertex
 */
template <typename T>
void directed_graph<T>::in_order_helper(vector<vertex<T>>& in_order, const int& parent_id, const int& child_id, bool* flag) {
	// end condition, vector with child_id is already added
	if(!flag[child_id]) {
		vector<vertex<T>> n = get_neighbours(child_id);

		if(n.size() == 0) {					// 0 neighbours means it is a leaf
			flag[child_id] = true;			// add leaf and mark visited
			in_order.push_back(get_vertex(child_id));
		}
		else {								// not a leaf, keep traveling down to find un visited leaf
			for (vertex<T> v : get_neighbours(child_id)) {
				in_order_helper(in_order, child_id, v.id, flag);
			}
		}

		// adds current un visited vertex after one child is added
		if(!flag[parent_id]) {
			flag[parent_id] = true;			// added if not visited
			in_order.push_back(get_vertex(parent_id));
		}
	}
}

/**
 * Recursive helper function for pre_order_traversal
 *
 * @param in_order - vector of vertex create travel path
 * @param u_id - int id of current visiting vertex
 * @param flag - boolean array to check added vertex
 */
template <typename T>
void directed_graph<T>::post_order_helper(vector<vertex<T>>& post_order, const int& u_id, bool* flag) {
	// end condition, vertex is visited
	if(!flag[u_id]) {

		for (vertex<T> v : get_neighbours(u_id)) {	// travel down the tree and adds each child first
			post_order_helper(post_order, v.id, flag);
		}

		// when all child are added, add its parent
		post_order.push_back(get_vertex(u_id));
		flag[u_id] = true;
	}
}

