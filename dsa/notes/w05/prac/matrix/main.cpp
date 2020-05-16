#include "graph.h"

//

int main()
{
	Graph g(6);

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
	std::cout << "is v 0 adjacent to v 1" << g.is_adjacent(0, 1);
	std::cout << "is v 0 adjacent to v 2" << g.is_adjacent(0, 2);
	std::cout << "is v 0 adjacent to v 3" << g.is_adjacent(0, 3);
	std::cout << "is v 0 adjacent to v 4" << g.is_adjacent(0, 4);
	std::cout << "is v 0 adjacent to v 5" << g.is_adjacent(0, 5);
	std::cout << "is v 0 adjacent to itself" << g.is_adjacent(0, 0);

	std::cout << "removing some edges" << std::endl;
	g.remove_edge(0, 4);
	g.remove_edge(0, 5);

	std::cout << "is v 0 adjacent to v 1" << g.is_adjacent(0, 1);
	std::cout << "is v 0 adjacent to v 2" << g.is_adjacent(0, 2);
	std::cout << "is v 0 adjacent to v 3" << g.is_adjacent(0, 3);
	std::cout << "is v 0 adjacent to v 4" << g.is_adjacent(0, 4);
	std::cout << "is v 0 adjacent to v 5" << g.is_adjacent(0, 5);
	std::cout << "is v 0 adjavent to itself" << g.is_adjacent(0, 0);
}