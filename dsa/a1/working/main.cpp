#include "./test.hpp"

//void setup(directed_graph<int> &g) {
//	int r = rand()%test_size + 2;
//	for (int i = 0; i < r; ++i){
//		g.add_vertex(vertex<int>(i+1,(i+1)*2)); // add vertices
//	}

//	bool re[r][r];
//	for (int i = 0; i < r; ++i){
//		for (int j = 0; j < r; ++j){
//		//  srand(time(0));
//		if (rand()%2 == 0 && i != j){
//			re[i][j] = true;
//			g.add_edge(i+1, j+1, (i+1)+(j+1)); // add edges
//			} else{ re[i][j] = false; }
//		}
//	}
//}
// aa
int main(){
	cout << "Test Cons\t\t" << testConstructor_AddVertex_Contains() << endl;
	//cout << "--------------------------" << endl;
	cout << "Test GetVert\t\t" << testGetVertices() << endl;
	//cout << "--------------------------" << endl;
	cout << "Test RemoveVert\t\t" << testRemoveVertex() << endl;
	//cout << "--------------------------" << endl;
	cout << "Test Edges\t\t" << testAddEdge_Adjacent_GetNeighbours() << endl;
	//cout << "--------------------------" << endl;
	cout << "Test 2nd order\t\t" << test2ndOrderNeighbours() << endl;
	//cout << "--------------------------" << endl;
	cout << "Test Degree\t\t" << testVertexDegrees() << endl;
	//cout << "--------------------------" << endl;
	cout << "Test Remove Edge\t" << testRemoveEdge() << endl;

	//directed_graph<int> g;
	//// add vertex
	////for (int i = 1; i < 7; i++) {
	////	g.add_vertex(vertex<int>(i, i*3));
	////}
	////setup(g);

	//g.add_vertex(vertex<int>(1, 22));
	//g.add_vertex(vertex<int>(2, 23));
	//g.add_vertex(vertex<int>(3, 24));
	//g.add_vertex(vertex<int>(4, 50));
	//g.add_vertex(vertex<int>(5, 86));

	//cout << "vert count "<< g.num_vertices() << endl;

	// add edge

	cout << "testing tree time" << endl;

	directed_graph<int> g;




}