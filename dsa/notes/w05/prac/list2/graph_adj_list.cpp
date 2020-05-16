#include "graph_adj_list.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

Graph::Graph(const size_t& size){
	// creating array vector;
	this->size = size;
	this->adj_list = new vector<int>[this->size]();

	// initializing array
	//for(int i = 0; i < this->size; i++){	// each vector
	//	for(int y = 0; y < this->size; y++) { //pushback each time
	//		this->adj_list[i].push_back(0);
	//	}
	//}
}

Graph::~Graph(){
}

void Graph::add_edge(const int& u, const int& v){
	this->adj_list[u].push_back(v);
}

void Graph::remove_edge(const int& u, const int& v){
	for(int i = 0; i < this->adj_list[u].size(); i++) {
		if(adj_list[u][i] == v) {
			std::vector<int>::iterator it = adj_list[u].begin()+i;
			adj_list[u].erase(it);
		}
	}
}

bool Graph::is_adjacent(const int& u, const int& v){

	for(int i = 0; i < this->adj_list[u].size(); i++) {
		if(adj_list[u][i] == v) {
			return true;
		}
	}
	return false;

}

// testing
void Graph::print(){
	cout << endl;
	for(int i = 0; i < this->size; i++){	// each vector
		for(int y = 0; y < this->size; y++) { //pushback each time
			cout << this->adj_list[i][y] << " ";
		}
		cout << endl;
	}
}