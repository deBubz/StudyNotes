#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <array>
#include <list>
#include <forward_list>
#include <deque>
#include <map>
#include <cstddef>
#include <string>
#include <utility>
#include <algorithm>
#include <limits>
#include <climits>
#include <optional>
#include <exception>
#include <stdexcept>

#include "directed_graph.hpp"

using namespace std;

/*
 * Computes the shortest distance from u to v in graph g.
 * The shortest path corresponds to a sequence of vertices starting from u and ends at v,
 * which has the smallest total weight of edges among all possible paths from u to v.
 */

template <typename T>
vector<vertex<T>> shortest_path(directed_graph<T> g, int u_id, int v_id) {
	vector<vertex<T>> shortest;

	// var declaration
	unordered_map<int, T> distance;
	unordered_map<int, int> prev;
	priority_queue<pair<int, T>, vector<pair<int, T>>, greater<pair<int, T>>> prior_queue;

	// queue<int> vertex_list = setup_bfs_queue(g, u_id);
	// unordered_map<int, pair<T, int>> dijkstra;					// vertex, (distance, previous)

	// setting up dynamic programming table
	for(vertex<T> v : g.get_vertices()) {
		if (v.id == u_id) distance[v.id] = 0;
		else distance[v.id] = INT_MAX;		// source

		prev[v.id] = -1;					// undefined previous node
		prior_queue.push(pair<int, T>(v.id, distance[v.id]));
	}


	while(!prior_queue.empty()){
		int u_vertex  = prior_queue.top().first;
		prior_queue.pop();

		// generate shortest path
		if (u_vertex == v_id) {
			int curr = v_id;

			if( prev[curr] != -1 || curr == u_id ) {
				while (curr != -1) {
					shortest.insert(shortest.begin(), g.get_vertex(curr));
					curr = prev[curr];
				}
			}
		}

		// dijkstras
		for(auto v : g.get_neighbours(u_vertex) ) {
			// T alt = dijkstra[u_vertex].first + g.get_edge(u_vertex, v.id);
			T alt = distance[u_vertex] + g.get_edge(u_vertex, v.id);
			//cout << "> alt " << alt << " = " << dijkstra[u_vertex].first << " + " << g.get_edge(u_vertex, v.id) << endl;
			if (alt < distance[v.id]) {
				distance[v.id] = alt;
				prev[v.id] = u_vertex;
			}
		}
	}



	// generating output
	// int prev_path = v_id;
	// while(prev_path != -2) {
	// 	shortest.insert(shortest.begin(), g.get_vertex(prev_path));
	// 	prev_path = dijkstra[prev_path].second;
	// }

	return shortest;
}



/*
 * Computes the strongly connected components of the graph.
 * A strongly connected component is a subset of the vertices
 * such that for every pair u, v of vertices in the subset,
 * v is reachable from u and u is reachable from v.
 */
template <typename T>
void tarjan(directed_graph<T> g, vector<vector<vertex<T>>> &result, const int& u, int& count, unordered_map<int, pair<int, int>>& dfn_low, stack<int>& s, set<int>& in_s) {
	// initialize dfn and low
	int c = count + 1;
	dfn_low[u] = pair<int, int> (c, c);
	count++;

	// add to stack and mark visited
	s.push(u);
	in_s.insert(u);

	// recursion
	// foreach v of u, v

	for(vertex<T> v : g.get_neighbours(u)) {
		if(!dfn_low[v.id].first) {	// v not visited, recursion

			tarjan(g, result, v.id, count, dfn_low, s, in_s);
			dfn_low[u].second = min(dfn_low[u].second, dfn_low[v.id].second);
		}

		else if (in_s.find(v.id) != in_s.end()) {

			dfn_low[u].second = min(dfn_low[u].second, dfn_low[v.id].first);
		}
	}

	// chech and add
	if(dfn_low[u].first == dfn_low[u].second) {
		vector<vertex<T>> scc;

		while(s.top() != u) {
			scc.push_back(g.get_vertex(s.top()));
			in_s.erase(s.top());
			s.pop();
		}
		// add root
		scc.push_back(g.get_vertex(s.top()));
		in_s.erase(s.top());
		s.pop();

		result.push_back(scc);
	}
}


// main SCC
template <typename T>
vector<vector<vertex<T>>> strongly_connected_components(directed_graph<T> g) {
	// variables setup
	unordered_map<int, int> dfn_map;
	unordered_map<int, int> low_map;
	int dfn_count = 0;
	unordered_map<int, pair<int, int>> dfn_low;

	stack<int> s;
	set<int> in_s;				// check if a node is in a stack;
	vector<vector<vertex<T>>> scc_result;

	// set up
	for(vertex<T> v: g.get_vertices()) {
		int tmp;	// nullvalue int
		dfn_low[v.id] = pair<int, int>(0, tmp);
		dfn_map[v.id] = 0;
		low_map[v.id] = tmp;
	}


	// main operations
	for(vertex<T> v : g.get_vertices()) {
		if(!dfn_low[v.id].first) {
			//cout << "starting outer with " << v.id << endl;
			tarjan(g, scc_result, v.id, dfn_count, dfn_low, s, in_s);
		}
		//else cout << "== " << v.id << " is visited" << endl;
	}

	//cout << "remaining size " << s.size() << " " << in_s.size() << endl;


  return scc_result;
}

/*
 * Computes a topological ordering of the vertices.
 * For every vertex u in the order, and any of its
 * neighbours v, v appears later in the order than u.
 * You will be given a DAG as the argument.
 */
 // -------------------------------------------------------------------------------

template <typename T>
void topological_sort_visit(directed_graph<T> g, vertex<T> &v, stack<int>* stack,  bool* flag) {
	if(!flag[v.id]) {
		flag[v.id] = true;
		for(auto u : g.get_neighbours(v.id)) {
			topological_sort_visit(g, u, stack, flag);
		}

		stack->push(v.id);
	}
}

template <typename T> // assuming the given graph is a DAG graph
vector<vertex<T>> topological_sort(directed_graph<T> g) {
	vector<vertex<T>> sorted;
	stack<int> stack;

	bool flag[g.num_vertices() + 1];	// visited flag
	for (int i = 0; i < g.num_vertices() + 1; i++) { flag[i] = false; }

	for(vertex<T> v : g.get_vertices()) {
		topological_sort_visit(g, v, &stack, flag);
	}

	while(!stack.empty()) {
		int v_id = stack.top();
		stack.pop();

		sorted.push_back(g.get_vertex(v_id));
	}
  return sorted;
}

// -------------------------------------------------------------------------------
/*
 * Computes the lowest cost-per-person for delivery over the graph.
 * u is the source vertex, which send deliveries to all other vertices.
 * vertices denote cities; vertex weights denote cities' population;
 * edge weights denote the fixed delivery cost between cities, which is irrelevant to
 * the amount of goods being delivered.
 */


template <typename T>
void low_cost_dfs(T &total_edge, T &total_vertex, directed_graph<T> tree, int &u_id, int &v_id, unordered_map<int, bool> &flag)
{
	if(!flag[u_id]) {
		for(vertex<T> w : tree.get_neighbours(v_id)) {
			low_cost_dfs(total_edge, total_vertex, tree, v_id, w.id, flag);
		}

		total_vertex += tree.get_vertex(v_id).weight;
		total_edge += tree.get_edge(u_id, v_id);
	}
}

template <typename T>
void low_cost_calculation(T &result, directed_graph<T> tree, int &u_id) {
	unordered_map<int, bool> flag; // visited checker
	for (vertex<T> v : tree.get_vertices()) { flag[v.id] = false; }

	T total_edge = 0;
	T total_vertex = 0;

	for(vertex<T> v : tree.get_neighbours(u_id)) {
		low_cost_dfs(total_edge, total_vertex, tree, u_id, v.id, flag);
	}

	result = total_edge/ total_vertex;
}


template <typename T>
T low_cost_delivery(directed_graph<T> g, int u_id) {
	T result = 0;
	directed_graph<T> tree;


	// create tree using dijkstras path
	tree.add_vertex(g.get_vertex(u_id));		// root node
	for(vertex<T>v : g.get_vertices()) {
		vector<vertex<T>> dij = shortest_path(g, u_id, v.id);

		// creating tree
		if(dij.size() > 1) {		// disconnected graphs returns shortest path size 0
			for(int i = 1; i < dij.size(); i++) {
				vertex<T> branch = g.get_vertex(dij[i].id);
				T edge_weight = g.get_edge(dij[i-1].id, dij[i].id);

				tree.add_vertex(branch);
				tree.add_edge(dij[i-1].id, dij[i].id, edge_weight);
			}
		}
	}

	// calculate result
	low_cost_calculation(result, tree, u_id);

 	return result;
}

