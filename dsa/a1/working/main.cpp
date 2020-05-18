//#include "./test.hpp"
#include "./working_map_list.hpp"

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

	cout << "making graph\n";
	directed_graph<int> g;

	g.add_vertex(vertex<int>(1, 12));
	g.add_vertex(vertex<int>(2, 12));
	g.add_vertex(vertex<int>(3, 12));
	g.add_vertex(vertex<int>(4, 12));
	g.add_vertex(vertex<int>(5, 12));
	g.add_vertex(vertex<int>(6, 12));
	g.add_vertex(vertex<int>(7, 12));
	g.add_vertex(vertex<int>(8, 12));
	g.add_vertex(vertex<int>(9, 12));
	g.add_vertex(vertex<int>(10, 12));
	g.add_vertex(vertex<int>(11, 12));
	g.add_vertex(vertex<int>(13 ,13));


	g.add_edge(1, 2, 1);
	g.add_edge(1, 9, 1);
	g.add_edge(2, 3, 1);
	g.add_edge(2, 6, 1);
	g.add_edge(3, 4, 1);
	g.add_edge(3, 5, 1);
	g.add_edge(6, 7, 1);
	g.add_edge(6, 8, 1);
	g.add_edge(9, 11, 1);
	g.add_edge(9, 10, 1);
	g.add_edge(1, 13, 3);

	cout << "testing tree time" << endl;

	directed_graph<int> tree = g.out_tree(1);

	vector<vertex<int>> pre = tree.pre_order_traversal(1, tree);
	cout << "\npre path:\t";
	for(int i = 0; i < pre.size(); i++) {
		cout << pre[i].id << "-";
	}
	cout << endl;

	vector<vertex<int>> inorder = tree.in_order_traversal(1, tree);
	cout << "\nin path:\t";
	for(int i = 0; i < inorder.size(); i++) {
		cout << inorder[i].id << "-";
	}
	cout << endl;

	vector<vertex<int>> post = tree.post_order_traversal(1, tree);
	cout << "\npost path:\t";
	for(int i = 0; i < inorder.size(); i++) {
		cout << inorder[i].id << "-";
	}
	cout << endl;

}