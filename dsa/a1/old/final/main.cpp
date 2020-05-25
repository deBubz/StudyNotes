#include <iostream>

#include "directed_graph.hpp"
#include "vertex.hpp"

using namespace std;


// testing envj
int main() {
	directed_graph<int> g;

	cout << "adding verts" << endl;
	g.add_vertex(vertex<int>(1, 100));

	cout << "vert counts: " << g.num_vertices() << endl;

};