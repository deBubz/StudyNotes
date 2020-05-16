#include "./graph_adj_list.h"
#include <iostream>

// undirected graph adj_list
// using array of vectors

int main()
{
	int s = 6;
	Graph g(s);

	g.add_edge(0,1);
	g.add_edge(0,3);
	g.add_edge(0,4);
	g.add_edge(0,5);
	g.add_edge(1,2);
	g.add_edge(1,3);
	g.add_edge(2,4);
	g.add_edge(3,4);
	g.add_edge(3,5);
	g.add_edge(4,5);

	// set bool to show T/F rather than 0/1
	std::cout << std::boolalpha;
	std::cout << "is v 0 adjacent to v 1 " << g.is_adjacent(0, 1) << std::endl;
	std::cout << "is v 0 adjacent to v 2 " << g.is_adjacent(0, 2) << std::endl;
	std::cout << "is v 0 adjacent to v 3 " << g.is_adjacent(0, 3) << std::endl;
	std::cout << "is v 0 adjacent to v 4 " << g.is_adjacent(0, 4) << std::endl;
	std::cout << "is v 0 adjacent to v 5 " << g.is_adjacent(0, 5) << std::endl;
	std::cout << "is v 0 adjacent to itself " << g.is_adjacent(0, 0) << std::endl;

	std::cout << "\nremoving some edges\n" << std::endl;
	g.remove_edge(0, 4);
	g.remove_edge(0, 5);

	std::cout << "is v 0 adjacent to v 1 " << g.is_adjacent(0, 1) << std::endl;
	std::cout << "is v 0 adjacent to v 2 " << g.is_adjacent(0, 2) << std::endl;
	std::cout << "is v 0 adjacent to v 3 " << g.is_adjacent(0, 3) << std::endl;
	std::cout << "is v 0 adjacent to v 4 " << g.is_adjacent(0, 4) << std::endl;
	std::cout << "is v 0 adjacent to v 5 " << g.is_adjacent(0, 5) << std::endl;
	std::cout << "is v 0 adjacent to itself " << g.is_adjacent(0, 0) << std::endl;

	g.print();
}