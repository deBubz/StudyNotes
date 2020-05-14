#ifndef DIRECTED_GRAPH_H
#define DIRECTED_GRAPH_H

#include <bits/stdc++.h> //The standard headers are all here just in case.
using namespace std; //The standard namespace are here just in case.

template <typename vertex>
class directed_graph {

private:

  //You will need to add some data members here
  //to actually represent the graph internally,
  //and keep track of whatever you need to.

public:

  directed_graph(); //A constructor for directed_graph. The graph should start empty.
  ~directed_graph(); //A destructor. Depending on how you do things, this may not be necessary.
  
  bool contains(const vertex&) const; //Returns true if the given vertex is in the graph, false otherwise.
  bool adjacent(const vertex&, const vertex&) const; //Returns true if the first vertex is adjacent to the second, false otherwise.

  void add_vertex(const vertex&); //Adds the passed in vertex to the graph (with no edges).
  void add_edge(const vertex&, const vertex&); //Adds an edge from the first vertex to the second.

  void remove_vertex(const vertex&); //Removes the given vertex. Should also clear any incident edges.
  void remove_edge(const vertex&, const vertex&); //Removes the edge between the two vertices, if it exists.

  size_t in_degree(const vertex&) const; //Returns number of edges coming in to a vertex.
  size_t out_degree(const vertex&) const; //Returns the number of edges leaving a vertex.
  size_t degree(const vertex&) const; //Returns the degree of the vertex (both in edges and out edges).
  
  size_t num_vertices() const; //Returns the total number of vertices in the graph.
  size_t num_edges() const; //Returns the total number of edges in the graph.

  vector<vertex> get_vertices(); //Returns a vector containing all the vertices.
  vector<vertex> get_neighbours(const vertex&); //Returns a vector containing all the vertices reachable from the given vertex. The vertex is not considered a neighbour of itself.
  vector<vertex> get_second_order_neighbors(const vertex&); // Returns a vector containing all the second_order_neighbours (i.e., neighbours of neighbours) of the given vertex.
                                                            // A vector cannot be considered a second_order_neighbor of itself.
  bool reachable(const vertex&, const vertex&) const; //Returns true if the second vertex is reachable from the first (can you follow a path of out-edges to get from the first to the second?). Returns false otherwise.
  bool contian_cycles() const; // Return true if the graph contains cycles (there is a path from any vertices directly/indirectly to itself), false otherwise.
  
  vector<vertex> depth_first(const vertex&); //Returns the vertices of the graph in the order they are visited in by a depth-first traversal starting at the given vertex.
  vector<vertex> breadth_first(const vertex&); //Returns the vertices of the graph in the order they are visisted in by a breadth-first traversal starting at the given vertex.
  
  directed_graph<vertex> out_tree(const vertex&); //Returns a spanning tree of the graph starting at the given vertex using the out-edges. This means every vertex in the tree is reachable from the root.
  
  vector<vertex> pre_order_traversal(const vertex&, directed_graph<vertex>&); // returns the vertices in the visiting order of a pre-order traversal of the minimum spanning tree starting at the given vertex.
  vector<vertex> in_order_traversal(const vertex&, directed_graph<vertex>&); // returns the vertices in the visiting order of an in-order traversal of the minimum spanning tree starting at the given vertex.
  vector<vertex> post_order_traversal(const vertex&, directed_graph<vertex>&); // returns the vertices in ther visitig order of a post-order traversal of the minimum spanning tree starting at the given vertex.
  
  vector<vertex> significance_sorting(); // Return a vector containing a sorted list of the vertices in descending order of their significance.

};

// Define all your methods down here (or move them up into the header, but be careful you don't double up). If you want to move this into another file, you can, but you should #include the file here.
// Although these are just the same names copied from above, you may find a few more clues in the full method headers.
// Note also that C++ is sensitive to the order you declare and define things in - you have to have it available before you use it.


template <typename vertex> directed_graph<vertex>::directed_graph() {}
template <typename vertex> directed_graph<vertex>::~directed_graph() {}

template <typename vertex> bool directed_graph<vertex>::contains(const vertex& u) const { return false; }
template <typename vertex> bool directed_graph<vertex>::adjacent(const vertex& u, const vertex& v) const { return false; }

template <typename vertex> void directed_graph<vertex>::add_vertex(const vertex& u) {}
template <typename vertex> void directed_graph<vertex>::add_edge(const vertex& u, const vertex& v) {}

template <typename vertex> void directed_graph<vertex>::remove_vertex(const vertex& u) {}
template <typename vertex> void directed_graph<vertex>::remove_edge(const vertex& u, const vertex& v) {}

template <typename vertex> size_t directed_graph<vertex>::in_degree(const vertex& u) const { return 0; }
template <typename vertex> size_t directed_graph<vertex>::out_degree(const vertex& u) const { return 0; }
template <typename vertex> size_t directed_graph<vertex>::degree(const vertex& u) const { return 0; }

template <typename vertex> size_t directed_graph<vertex>::num_vertices() const { return 0; }
template <typename vertex> size_t directed_graph<vertex>::num_edges() const { return 0; }

template <typename vertex> vector<vertex> directed_graph<vertex>::get_vertices() { return vector<vertex>(); }
template <typename vertex> vector<vertex> directed_graph<vertex>::get_neighbours(const vertex&) { return vector<vertex>(); }
template <typename vertex> vector<vertex> directed_graph<vertex>::get_second_order_neighbors(const vertex&) { return vector<vertex>(); }

template <typename vertex> bool directed_graph<vertex>::reachable(const vertex& u, const vertex& v) const { return false; }
template <typename vertex> bool directed_graph<vertex>::contian_cycles () const { return false; }

template <typename vertex> vector<vertex> directed_graph<vertex>::depth_first(const vertex& u) { return vector<vertex>(); }
template <typename vertex> vector<vertex> directed_graph<vertex>::breadth_first(const vertex& u) { return vector<vertex>(); }

template <typename vertex> directed_graph<vertex> directed_graph<vertex>::out_tree(const vertex& u) { return directed_graph<vertex>(); }

template <typename vertex> vector<vertex> directed_graph<vertex>::pre_order_traversal(const vertex& u, directed_graph<vertex>& mst) { return vector<vertex>(); }
template <typename vertex> vector<vertex> directed_graph<vertex>::in_order_traversal(const vertex& u, directed_graph<vertex>& mst) { return vector<vertex>(); }
template <typename vertex> vector<vertex> directed_graph<vertex>::post_order_traversal(const vertex& u, directed_graph<vertex>& mst) { return vector<vertex>(); }

template <typename vertex> vector<vertex> directed_graph<vertex>::significance_sorting(){ return vector<vertex>(); }

#endif