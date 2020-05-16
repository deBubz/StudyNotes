#define CXXTEST_HAVE_EH
#define CXXTEST_ABORT_TEST_ON_FAIL
#include <cxxtest/TestSuite.h>
#include <cxxtest/GlobalFixture.h>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <sstream>
#include <ctime>
#include <unordered_set>

#include "directed_graph.hpp"
#include "test_helper.cpp"

class Management : public CxxTest::GlobalFixture{

	public:

	bool setUpWorld(){
		std::srand(std::time(0));
		return true;
	}

	bool tearDownWorld(){
		return true;
	}

};

static Management management;

class Assignment1Tests : public CxxTest::TestSuite{

	public:

	void testBasicConstructor(void){

		directed_graph<int> g;
		TS_ASSERT_EQUALS(g.num_vertices(), 0);
		TS_ASSERT_EQUALS(g.num_edges(), 0);

		directed_graph<std::string> h;
		TS_ASSERT_EQUALS(h.num_vertices(), 0);
		TS_ASSERT_EQUALS(h.num_edges(), 0);

		directed_graph<double> i;
		TS_ASSERT_EQUALS(i.num_vertices(), 0);
		TS_ASSERT_EQUALS(i.num_edges(), 0);
	}

	void testAddVertex(){

		directed_graph<int> g;
		int r = std::rand()%20 + 1;
		for (int i = 0; i < r; ++i) g.add_vertex(i);

		TS_ASSERT_EQUALS(g.num_vertices(),r);
	}

	void testContains(){

		directed_graph<int> g;
		int r = std::rand()%20 + 1;
		for (int i = 0; i < r; ++i) g.add_vertex(i);

		for (int i = 0; i < r; i++){
			TS_ASSERT(g.contains(i));
		}
	}

	void testRemoveVertex(){

		directed_graph<int> g;
		std::vector<int> in;
		std::vector<int> out;

		int r = std::rand()%20 + 1;

		for (int i = 0; i < r; ++i) g.add_vertex(i);

		TS_ASSERT_EQUALS(g.num_vertices(),r);
		for (int i = 0; i < r; i++){
			TS_ASSERT(g.contains(i));
		}

		for (int i = 0; i < r; ++i) {
			if (std::rand()%2 == 0) {
				in.push_back(i);
			}
			else {
				out.push_back(i);
			}
		}

		for (auto i : out) g.remove_vertex(i);

		TS_ASSERT_EQUALS(g.num_vertices(), r - out.size());
		for (auto i : out){
			TS_ASSERT(!g.contains(i));
		}
		for (auto i : in){
			TS_ASSERT(g.contains(i));
		}

	}

	void testAddEdge(){

		directed_graph<int> g;
		int r = std::rand()%20 + 2;
		int m = 0;

		bool re[r][r];

		for (int i = 0; i < r; ++i){
			for (int  j = 0; j < r; ++j){
				re[i][j] = false;
			}
		}

		for (int i = 0; i < r; ++i){
			for (int j = 0; j < r;  ++j){
				if (std::rand()%2 == 1 && i != j){
					re[i][j] = true;
					m++;
				}
			}
		}

		for (int i = 0; i < r; ++i){
			g.add_vertex(i);
		}

		for (int i = 0; i < r; ++i){
			for (int j = 0; j < r; ++j){
				if (re[i][j]){
					g.add_edge(i,j);
				}
			}
		}

		TS_ASSERT_EQUALS(g.num_edges(), m);

	}

	void testAreAdjacent() {

		directed_graph<std::string> h;

		h.add_vertex("vertex1");
		h.add_vertex("vertex2");
		h.add_vertex("vertex3");
		h.add_vertex("vertex4");

		h.add_edge("vertex2", "vertex3");
		h.add_edge("vertex4", "vertex1");
		h.add_edge("vertex1", "vertex3");

		TS_ASSERT(h.adjacent("vertex2", "vertex3"));
		TS_ASSERT(h.adjacent("vertex4", "vertex1"));
		TS_ASSERT(h.adjacent("vertex1", "vertex3"));
		TS_ASSERT(!h.adjacent("vertex1", "vertex2"));
		TS_ASSERT(!h.adjacent("vertex1", "vertex4"));
		TS_ASSERT(!h.adjacent("vertex2", "vertex1"));
		TS_ASSERT(!h.adjacent("vertex2", "vertex4"));
		TS_ASSERT(!h.adjacent("vertex3", "vertex1"));
		TS_ASSERT(!h.adjacent("vertex3", "vertex2"));
		TS_ASSERT(!h.adjacent("vertex3", "vertex4"));
		TS_ASSERT(!h.adjacent("vertex4", "vertex2"));
		TS_ASSERT(!h.adjacent("vertex4", "vertex3"));

		directed_graph<int> g;
		int r = std::rand()%20 + 2;
		int m = 0;

		bool re[r][r];

		for (int i = 0; i < r; ++i){
			for (int  j = 0; j < r; ++j){
				re[i][j] = false;
			}
		}

		for (int i = 0; i < r; ++i){
			for (int j = 0; j < r;  ++j){
				if (std::rand()%2 == 1 && i != j){
					re[i][j] = true;
					m++;
				}
			}
		}

		for (int i = 0; i < r; ++i){
			g.add_vertex(i);
		}

		for (int i = 0; i < r; ++i){
			for (int j = 0; j < r;  ++j){
				if (re[i][j]){
					g.add_edge(i,j);
				}
			}
		}

		TS_ASSERT_EQUALS(g.num_edges(), m);

		for (int i = 0; i < r; ++i){
			for (int j = 0; j < r;  ++j){
				if (re[i][j]){
					TS_ASSERT(g.adjacent(i,j));
				}
				else {
					TS_ASSERT(!g.adjacent(i,j));
				}
			}
		}

	}

	void testRemoveEdge(){

		directed_graph<int> g;
		int r = std::rand()%20 + 2;
		int m = 0;
		int total_weight = 0;

		bool re[r][r];

		for (int i = 0; i < r; ++i){
			for (int  j = 0; j < r; ++j){
				re[i][j] = false;
			}
		}

		for (int i = 0; i < r; ++i){
			for (int j = 0; j < r;  ++j){
				if (std::rand()%2 == 1 && i != j){
					re[i][j] = true;
					m++;
				}
			}
		}

		for (int i = 0; i < r; ++i){
			g.add_vertex(i);
		}

		struct PairHash{
			size_t operator()(const std::pair<int, int> &key) const{
				return std::hash<int>()(key.first) * std::hash<int>()(key.second);
			}
		};

		std::unordered_set<std::pair<int, int>, PairHash > edges;
		std::unordered_set<std::pair<int, int>, PairHash > removed_edges;

		for (int i = 0; i < r; ++i){
			for (int j = 0; j < r;  ++j){
				if (re[i][j]){
					g.add_edge(i,j);

					if (std::rand()%2 == 0) removed_edges.insert({i,j});
					else edges.insert({i,j});
				}
			}
		}

		TS_ASSERT_EQUALS(g.num_edges(), m);

		for (auto e : removed_edges){
			g.remove_edge(e.first, e.second);
		}

		TS_ASSERT_EQUALS(g.num_edges(), m - removed_edges.size());

		for (auto e : edges){
			TS_ASSERT(g.adjacent(e.first, e.second));
		}

		for (auto e : removed_edges){
			TS_ASSERT(!g.adjacent(e.first, e.second));
		}

	}

	void testOutDegree(){

		directed_graph<int> g;
		int r = std::rand()%20 + 2;

		bool re[r][r];

		for (int i = 0; i < r; ++i){
			for (int  j = 0; j < r; ++j){
				re[i][j] = false;
			}
		}

		for (int i = 0; i < r; ++i){
			for (int j = 0; j < r; ++j){
				if (std::rand()%2 == 1 && i != j){
					re[i][j] = true;
				}
			}
		}

		for (int i = 0; i < r; ++i){
			g.add_vertex(i);
		}

		for (int i = 0; i < r; ++i){
			for (int j = 0; j < r;  ++j){
				if (re[i][j]){
					g.add_edge(i,j);
				}
			}
		}

		for (int i = 0; i < r; ++i){
			int edge_count = 0;
			for (int j = 0; j < r;  ++j){
				if (re[i][j]){
					edge_count++;
				}
			}
			TS_ASSERT_EQUALS(g.out_degree(i), edge_count);
		}

	}

	void testInDegree(){

		directed_graph<int> g;
		int r = std::rand()%20 + 2;

		bool re[r][r];

		for (int i = 0; i < r; ++i){
			for (int  j = 0; j < r; ++j){
				re[i][j] = false;
			}
		}

		for (int i = 0; i < r; ++i){
			for (int j = 0; j < r; ++j){
				if (std::rand()%2 == 1 && i != j){
					re[i][j] = true;
				}
			}
		}

		for (int i = 0; i < r; ++i){
			g.add_vertex(i);
		}

		for (int i = 0; i < r; ++i){
			for (int j = 0; j < r;  ++j){
				if (re[i][j]){
					g.add_edge(i,j);
				}
			}
		}

		for (int i = 0; i < r; ++i){
			int edge_count = 0;
			for (int j = 0; j < r;  ++j){
				if (re[j][i]){
					edge_count++;
				}
			}
			TS_ASSERT_EQUALS(g.in_degree(i), edge_count);
		}

	}

	void testDegree(){

		directed_graph<int> g;
		int r = std::rand()%20 + 2;

		bool re[r][r];

		for (int i = 0; i < r; ++i){
			for (int  j = 0; j < r; ++j){
				re[i][j] = false;
			}
		}

		for (int i = 0; i < r; ++i){
			for (int j = 0; j < r; ++j){
				if (std::rand()%2 == 1 && i != j){
					re[i][j] = true;
				}
			}
		}

		for (int i = 0; i < r; ++i){
			g.add_vertex(i);
		}

		for (int i = 0; i < r; ++i){
			for (int j = 0; j < r;  ++j){
				if (re[i][j]){
					g.add_edge(i,j);
				}
			}
		}

		for (int i = 0; i < r; ++i){
			int edge_count = 0;
			for (int j = 0; j < r;  ++j){
				if (re[i][j]){
					edge_count++;
				}
				if (re[j][i]) {
				  edge_count++;
				}
			}
			TS_ASSERT_EQUALS(g.degree(i), edge_count);
		}

	}


	void testGetVertices(){

		directed_graph<int> g;
		int r = std::rand()%20 + 1;
		int s = std::rand()%r;

		for (int i = 0; i < r; ++i) g.add_vertex(i);

		std::vector<int> v = g.get_vertices();
		TS_ASSERT_EQUALS(r, v.size());
		for (int i = 0; i < v.size(); ++i){
			TS_ASSERT(g.contains(v[i]));
		}

		for (int i = 0; i < v.size(); ++i){
			for (int j = i + 1; j < v.size(); ++j){
				TS_ASSERT_DIFFERS(v[i], v[j]);
			}
		}

		for (int i = 0; i < s; ++i) g.remove_vertex(i);

		v = g.get_vertices();
		TS_ASSERT_EQUALS(r-s, v.size());
		for (int i = 0; i < v.size(); ++i){
			TS_ASSERT(g.contains(v[i]));
		}

		for (int i = 0; i < v.size(); ++i){
			for (int j = i + 1; j < v.size(); ++j){
				TS_ASSERT_DIFFERS(v[i], v[j]);
			}
		}
	}

	void testGetNeighbours(){

		directed_graph<int> g;
		int r = std::rand()%20 + 2;

		bool re[r][r];

		for (int i = 0; i < r; ++i){
			for (int  j = 0; j < r; ++j){
				re[i][j] = false;
			}
		}

		for (int i = 0; i < r; ++i){
			for (int j = 0; j < r;  ++j){
				if (std::rand()%2 == 1 && i != j){
					re[i][j] = true;
				}
			}
		}

		for (int i = 0; i < r; ++i){
			g.add_vertex(i);
		}

		for (int i = 0; i < r; ++i){
			for (int j = 0; j < r;  ++j){
				if (re[i][j]){
					g.add_edge(i,j);
				}
			}
		}

		for (int i = 0; i < r; ++i){
			std::vector<int> n_i = g.get_neighbours(i);
			TS_ASSERT_EQUALS(g.out_degree(i), n_i.size());
			for (int j = 0; j < n_i.size(); ++j){
				TS_ASSERT(g.adjacent(i, n_i[j]));
				TS_ASSERT(re[i][n_i[j]]);
			}

			for (int j = 0; j < n_i.size(); ++j){
				for (int k = j + 1; k < n_i.size(); ++k){
					TS_ASSERT_DIFFERS(n_i[j], n_i[k]);
				}
			}
		}
	}

	void testDepthFirst(){

		directed_graph<int> g;
		int r = std::rand()%20 + 1;
		std::unordered_map<int, std::unordered_set<int> > adj_list;

		bool re[r][r];

		for (int i = 0; i < r; ++i){
			for (int  j = 0; j < r; ++j){
				re[i][j] = false;
			}
		}

		for (int i = 0; i < r; ++i){
			for (int j = 0; j < r;  ++j){
				if (std::rand()%2 == 1 && i != j){
					re[i][j] = true;

				}
			}
		}

		for (int i = 0; i < r; ++i){
			g.add_vertex(i);
		}

		for (int i = 0; i < r; ++i){
			for (int j = 0; j < r;  ++j){
				if (re[i][j]){
					g.add_edge(i,j);
				}
			}
		}

		for (int i = 0; i < r; ++i){

			std::unordered_set<int> n;
			for (int j = 0; j < r; ++j){
				if (re[i][j]) n.insert(j);
			}
			adj_list.insert({i,n});

		}

		int start_vertex = std::rand()%r;

		std::vector<int> graph_dfs = g.depth_first(start_vertex);
		std::vector<int> reference_dfs = dfs(adj_list, start_vertex);
		TS_ASSERT_EQUALS(graph_dfs, reference_dfs);

	}

	void testBreadthFirst(){

		directed_graph<int> g;
		int r = std::rand()%20 + 1;
		std::unordered_map<int, std::unordered_set<int> > adj_list;

		bool re[r][r];

		for (int i = 0; i < r; ++i){
			for (int  j = 0; j < r; ++j){
				re[i][j] = false;
			}
		}

		for (int i = 1; i < r; ++i){
			for (int j = 0; j < r;  ++j){
				if (std::rand()%2 == 1 && i != j){
					re[i][j] = true;

				}
			}
		}

		for (int i = 0; i < r; ++i){
			g.add_vertex(i);
		}

		for (int i = 0; i < r; ++i){
			for (int j = 0; j < r;  ++j){
				if (re[i][j]){
					g.add_edge(i,j);
				}
			}
		}

		for (int i = 0; i < r; ++i){

			std::unordered_set<int> n;
			for (int j = 0; j < r; ++j){
				if (re[i][j]) n.insert(j);
			}
			adj_list.insert({i,n});

		}

		int start_vertex = std::rand()%r;

		std::vector<int> graph_bfs = g.breadth_first(start_vertex);
		std::vector<int> reference_bfs = bfs(adj_list, start_vertex);

		TS_ASSERT_EQUALS(graph_bfs, reference_bfs);

	}

	void testOutTree(){

	  directed_graph<int> g;
	  std::vector<int> verts;
	  int r = std::rand()%20 + 1;

	  bool re[r][r];

	  for (int i = 0; i < r; ++i){
	    for (int  j = 0; j < r; ++j){
	      re[i][j] = false;
	    }
	  }

	  for (int i = 0; i < r; ++i){
	    g.add_vertex(i);
	    verts.push_back(i);
	  }

	  std::vector<std::pair<int, int> > tree_edges = random_tree(verts);

	  for (auto edge : tree_edges){
	    g.add_edge(edge.first, edge.second);
	    re[edge.first][edge.second] = true;
	  }

	  for (int i = 0; i < r; ++i){
	    for (int j = 0; j < r;  ++j){
	      if (std::rand()%2 == 1 && re[i][j] == 0 && i != j){
			re[i][j] = true;
			g.add_edge(i,j);
	      }
	    }
	  }

	  directed_graph<int> t = g.out_tree(0);

	  TS_ASSERT_EQUALS(t.num_vertices(), verts.size());
	  TS_ASSERT_EQUALS(t.num_edges(), t.num_vertices() - 1);
	  for (auto i = 1; i < r; ++i) TS_ASSERT(is_reachable(t, 0, i));
	  for (auto i = 0; i < r; ++i) {
		  for (auto j = 0; j < r; ++j) {
			  if (!re[i][j]) TS_ASSERT(!t.adjacent(i,j));
		  }
	  }

	}

	void testInTree() {

	  directed_graph<int> g;
	  std::vector<int> verts;
	  int r = std::rand()%20 + 1;

	  bool re[r][r];

	  for (int i = 0; i < r; ++i){
	    for (int  j = 0; j < r; ++j){
	      re[i][j] = false;
	    }
	  }

	  for (int i = 0; i < r; ++i){
	    g.add_vertex(i);
	    verts.push_back(i);
	  }

	  std::vector<std::pair<int, int> > tree_edges = random_tree(verts);

	  for (auto edge : tree_edges){
	    g.add_edge(edge.second, edge.first);
	    re[edge.second][edge.first] = true;
	  }

	  for (int i = 0; i < r; ++i){
	    for (int j = 0; j < r;  ++j){
	      if (std::rand()%2 == 1 && re[i][j] == 0 && i != j){
			re[i][j] = true;
			g.add_edge(i,j);
	      }
	    }
	  }

	  directed_graph<int> t = g.in_tree(0);

	  TS_ASSERT_EQUALS(t.num_vertices(), verts.size());
	  TS_ASSERT_EQUALS(t.num_edges(), t.num_vertices() - 1);
	  for (auto i = 1; i < r; ++i) TS_ASSERT(is_reachable(t, i, 0));
	  for (auto i = 0; i < r; ++i) {
		  for (auto j = 0; j < r; ++j) {
			  if (!re[i][j]) TS_ASSERT(!t.adjacent(i,j));
		  }
	  }
	}

	void testReachable() {

	  directed_graph<int> g;
	  int r = std::rand()%20 + 2;

	  bool re[r][r];

	  for (int i = 0; i < r; ++i){
	    for (int  j = 0; j < r; ++j){
	      re[i][j] = false;
	    }
	  }

	  for (int i = 0; i < r; ++i){
	    for (int j = 0; j < r; ++j){
	      if (std::rand()%2 == 1 && i != j){
		re[i][j] = true;
	      }
	    }
	  }

	  for (int i = 0; i < r; ++i){
	    g.add_vertex(i);
	  }

	  for (int i = 0; i < r; ++i){
	    for (int j = 0; j < r;  ++j){
	      if (re[i][j]){
		g.add_edge(i,j);
	      }
	    }
	  }

	  for (int i = 0; i < r; ++i) {
	    for (int j = 0; j < r; ++j) {
	      TS_ASSERT_EQUALS(g.reachable(i,j), is_reachable(g, i, j));
	    }
	  }

	}

	void testGraphIterator(){

		directed_graph<int> g;
		int r = std::rand()%20 + 1;

		bool re[r][r];

		for (int i = 0; i < r; ++i){
			for (int  j = 0; j < r; ++j){
				re[i][j] = false;
			}
		}

		for (int i = 0; i < r; ++i){
			for (int j = 0; j < r;  ++j){
				if (std::rand()%2 == 1 && i != j){
					re[i][j] = true;

				}
			}
		}

		for (int i = 0; i < r; ++i){
			g.add_vertex(i);
		}

		for (int i = 0; i < r; ++i){
			for (int j = 0; j < r;  ++j){
				if (re[i][j]){
					g.add_edge(i,j);
				}
			}
		}

		std::unordered_set<int> it_vertices;
		for (auto v : g){
			it_vertices.insert(v);
		}

		TS_ASSERT_EQUALS(it_vertices.size(), r);

		for (auto u : g.get_vertices()){
			TS_ASSERT_LESS_THAN(0, it_vertices.count(u));
		}
	}

	void testNeighbourIterator(){

		directed_graph<int> g;
		int r = std::rand()%20 + 1;

		bool re[r][r];

		for (int i = 0; i < r; ++i){
			for (int  j = 0; j < r; ++j){
				re[i][j] = false;
			}
		}

		for (int i = 0; i < r; ++i){
			for (int j = 0; j < r;  ++j){
				if (std::rand()%2 == 1 && i != j){
					re[i][j] = true;
				}
			}
		}

		for (int i = 0; i < r; ++i){
			g.add_vertex(i);
		}

		for (int i = 0; i < r; ++i){
			for (int j = 0; j < r;  ++j){
				if (re[i][j]){
					g.add_edge(i,j);
				}
			}
		}

		for (auto u = 0; u < r; u++){

			std::unordered_set<int> neighbours;
			for (auto n = g.nbegin(u); n != g.nend(u); ++n){
				it_neighbours.insert(*n);
			}

			int u_degree = 0;
			for (int i = 0; i < r; i++){
				if (re[u][i] > 0) u_degree++;
			}

			TS_ASSERT_EQUALS(it_neighbours.size(), u_degree);
			for (auto v : g.get_neighbours(u)){
				TS_ASSERT_LESS_THAN(0, it_neighbours.count(v));
			}

		}

	}

};

