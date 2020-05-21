// stl and vectors include already listed in directed_graph.hpp
#include "directed_graph.hpp"


template <typename T> directed_graph<T>::directed_graph() {}
template <typename T> directed_graph<T>::directed_graph(const int& root_id) {
	this->root_node = root_id;
}
template <typename T> directed_graph<T>::~directed_graph() {}

// ============== helper functions ===================

template <typename T> // ok
bool directed_graph<T>::contains(const int &u_id) const
{	// check if graph contains vertex u
	return this->vertex_list.find(u_id) != this->vertex_list.end();
}

template <typename T> // k
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

	for (vertex<T> v : get_neighbours(u_id))
	{	// foreach neighbours of root
		out_tree(tree, u_id, v.id, flag);
	}

	return tree;
}

template <typename T>
void directed_graph<T>::out_tree(directed_graph<T> &tree, const int &parent_id, const int &child_id, bool* flag)
{	// recursive dft function for out_tree
	if(!flag[child_id])
	{	// if child not visited
		flag[child_id] = true;
		// add child vertex, parent-> child edge
		tree.add_vertex(get_vertex(child_id));
		tree.add_edge(parent_id, child_id, this->adj_list[parent_id][child_id]);

		// child is now new parent
		for (vertex<T> v : get_neighbours(child_id)) {
			out_tree_traversal(tree, child_id, v.id, flag);
		}
	}
};

template <typename T>
vector<vertex<T>> directed_graph<T>::pre_order_traversal(const int &u_id, directed_graph<T> &tree)
{	// return vector of vertex in in preorder traversal

	bool flag[num_vertices() + 1]; // visited checker
	for (int i = 1; i < num_vertices() + 1; i++) { flag[i] = i == u_id; }

	vector<vertex<T>> pre_order;
	pre_order.push_back(tree.get_vertex(tree.root_node));		// u_id as root_id is redundant

	for (vertex<T> v : get_neighbours(tree.root_node))
	{	// foreach neighbours of root
		pre_order_traversal(pre_order, v.id, flag);

	}

	return pre_order;
}

template <typename T>
void directed_graph<T>::pre_order_traversal(vector<vertex<T>>& pre_order, const int& child_id, bool* flag)
{	// same as dsf
	if(!flag[child_id]) {
		flag[child_id] = true;

		pre_order.push_back(get_vertex(child_id));

		for (vertex<T> v : get_neighbours(child_id)) {
			pre_order_traversal(pre_order, v.id, flag);
		}
	}
}

template <typename T>
vector<vertex<T>> directed_graph<T>::in_order_traversal(const int &u_id, directed_graph<T> &tree) {
	bool flag[num_vertices() + 1]; // visited checker
	for (int i = 1; i < num_vertices() + 1; i++) { flag[i] = false; }

	vector<vertex<T>> in_order;

	for (vertex<T> v : get_neighbours(tree.root_node))
	{	// foreach neighbours of root
		in_order_traversal(in_order, tree.root_node, v.id, flag);
	}

	return in_order;
}

template <typename T>
void directed_graph<T>::in_order_traversal(vector<vertex<T>>& in_order, const int& parent_id, const int& child_id, bool* flag) {
	if(!flag[child_id]) {
		// cout << "-------------------------------" << endl;
		vector<vertex<T>> n = get_neighbours(child_id);

		if(n.size() == 0) {	// leaf
			flag[child_id] = true;
			in_order.push_back(get_vertex(child_id));
		} else {	// n.size > 0
			for (vertex<T> v : get_neighbours(child_id)) {
				in_order_traversal(in_order, child_id, v.id, flag);
			}
		}

		//  add branch
		if(!flag[parent_id]) {
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

	for (vertex<T> v : get_neighbours(tree.root_node))
	{	// foreach neighbours of root
		post_order_traversal(post_order, v.id, flag);
	}

	post_order.push_back(get_vertex(u_id));
	// cout << "what " << u_id << " " << flag[u_id] << endl;

	return post_order;
}

template <typename T>
void directed_graph<T>::post_order_traversal(vector<vertex<T>>& post_order, const int& u_id, bool* flag) {
	if(!flag[u_id]) {

		for (vertex<T> v : get_neighbours(u_id))
		{	// foreach neighbours of root
			l(post_order, v.id, flag);
		}

		// cout << "=== " << u_id << endl;
		post_order.push_back(get_vertex(u_id));
		// cout << "pushed " << u_id << endl;
		flag[u_id] = true;
	}
}
template <typename T>
vector<vertex<T>> directed_graph<T>::significance_sorting() {
	vector<vertex<T>> sig_sort = get_vertices();
	sort(sig_sort.begin(), sig_sort.end(),[](vertex<T> u, vertex<T> v){ return u.weight > v.weight; });
	return sig_sort;
}
