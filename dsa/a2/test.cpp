/*
* A main function for you to build and run your
* own tests with.
* This file is not part of the marking, so you
* can do anything you want here.
*/
#include <iostream>

#include "./directed_graph_algos.cpp"

using namespace std;

void check_shortest(directed_graph<int> g, int start, int end) {
    cout << "Shortest Path " << start << " - " << end << " is: \n";

    vector<vertex<int>> sp = shortest_path(g, start, end);
    for (auto vertex : sp) {
        cout << vertex.id << " - ";
    }

    cout << endl;
}


int main() {
    //directed_graph<int> g;
    //vertex<int> va = vertex<int>(0, 800);        //A
    //vertex<int> vb = vertex<int>(1, 300);        //B
    //vertex<int> vc = vertex<int>(2, 400);        //C
    //vertex<int> vd = vertex<int>(3, 710);        //D
    //vertex<int> ve = vertex<int>(4, 221);        //E

    //g.add_vertex(va);
    //g.add_vertex(vb);
    //g.add_vertex(vc);
    //g.add_vertex(vd);
    //g.add_vertex(ve);

    //g.add_edge(va.id, vb.id, 600);  //A-B 6     0-1
    //g.add_edge(va.id, vc.id, 900);  //A-C 9     0-2
    //g.add_edge(vb.id, ve.id, 3000); //B-E 3     0-3
    //g.add_edge(vc.id, vd.id, 4000); //C-D 4     1-3
    //g.add_edge(vd.id, va.id, 1);    //D-A 1     3-0
    //g.add_edge(vd.id, vc.id, 700);  //D-C 7     3-2
    //g.add_edge(vd.id, ve.id, 500);  //D-E 5     3-4

    ////g.add_edge(va.id, vb.id, 1);  //A-B 6     0-1
    ////g.add_edge(va.id, vc.id, 30);  //A-C 9     0-2
    ////g.add_edge(vb.id, vd.id, 2); //B-E 3     0-3
    ////g.add_edge(vc.id, vd.id, 30); //C-D 4     1-3
    ////g.add_edge(vd.id, va.id, 1);    //D-A 1     3-0
    ////g.add_edge(vd.id, vc.id, 700);  //D-C 7     3-2
    ////g.add_edge(vd.id, ve.id, 500);  //D-E 5     3-4


    ////vertex<int> v1 = vertex<int>(1, 1);
    ////vertex<int> v2 = vertex<int>(2, 1);
    ////vertex<int> v3 = vertex<int>(3, 1);
    ////vertex<int> v4 = vertex<int>(4, 1);
    ////vertex<int> v5 = vertex<int>(5, 1);
    ////vertex<int> v6 = vertex<int>(6, 1);
    ////vertex<int> v7 = vertex<int>(7, 1);
    ////vertex<int> v8 = vertex<int>(8, 1);
    ////vertex<int> v9 = vertex<int>(9, 1);

    ////cout << "adding" << endl;
    ////g.add_vertex(v1);
    ////g.add_vertex(v2);
    ////g.add_vertex(v3);
    ////g.add_vertex(v4);
    ////g.add_vertex(v5);
    ////g.add_vertex(v6);
    ////g.add_vertex(v7);
    ////g.add_vertex(v8);
    ////g.add_vertex(v9);
    ////cout << endl;

    ////cout << "adding edges" << endl;
    ////g.add_edge(v1.id, v2.id, 8);   // 1
    ////g.add_edge(v1.id, v3.id, 3);
    ////g.add_edge(v1.id, v6.id, 13);

    ////g.add_edge(v2.id, v3.id, 2);   // 2
    ////g.add_edge(v2.id, v4.id, 1);

    ////g.add_edge(v3.id, v2.id, 3);   // 3
    ////g.add_edge(v3.id, v4.id, 9);
    ////g.add_edge(v3.id, v5.id, 2);

    ////g.add_edge(v4.id, v5.id, 4);   // 4
    ////g.add_edge(v4.id, v7.id, 6);
    ////g.add_edge(v4.id, v8.id, 2);

    ////g.add_edge(v5.id, v1.id, 5);   // 5
    ////g.add_edge(v5.id, v4.id, 6);
    ////g.add_edge(v5.id, v6.id, 5);
    ////g.add_edge(v5.id, v9.id, 4);

    ////g.add_edge(v6.id, v7.id, 1);   // 6
    ////g.add_edge(v6.id, v9.id, 7);

    ////g.add_edge(v7.id, v5.id, 3);   // 7
    ////g.add_edge(v7.id, v8.id, 4);

    ////g.add_edge(v8.id, v9.id, 1);   // 8

    ////g.add_edge(v9.id, v7.id, 5);   // 9

    ////cout << endl;

    ////check_shortest(g, v1.id, v8.id);
    ////check_shortest(g, v3.id, v9.id);
    ////check_shortest(g, v6.id, v1.id);
    ////check_shortest(g, v4.id, v3.id);
    ////check_shortest(g, v9.id, v2.id);

    ////check_shortest(g, va.id, vd.id);
    //    cout << "Shortest Path" << endl;
    //vector<vertex<int>> short_path = shortest_path(g, 0, 4);
    //for (auto vertex : short_path) {
    //        cout << "(" << vertex.id << ", " << vertex.weight << ")";
    //}
    //cout << endl;


    ////cout << "Shortest Path A-C" << endl;
    ////vector<vertex<int>> sp2 = shortest_path(g, va.id, vc.id);
    ////for (auto vertex : sp2) {
    ////        cout << "(" << vertex.id << ", " << vertex.weight << ")";
    ////}
    ////cout << endl;
    ////cout << "Shortest Path A-D" << endl;
    ////vector<vertex<int>> sp3 = shortest_path(g, va.id, vd.id);
    ////for (auto vertex : sp3) {
    ////        cout << "(" << vertex.id << ", " << vertex.weight << ")";
    ////}
    ////cout << endl;
    ////cout << "Shortest Path A-E" << endl;
    ////vector<vertex<int>> sp4 = shortest_path(g, va.id, ve.id);
    ////for (auto vertex : sp4) {
    ////        cout << "(" << vertex.id << ", " << vertex.weight << ")";
    ////}
    ////cout << endl;
    ////cout << endl;

    ////cout << "Shortest Path D-A" << endl;
    ////vector<vertex<int>> sp5 = shortest_path(g, vd.id, va.id);
    ////for (auto vertex : sp5) {
    ////        cout << "(" << vertex.id << ", " << vertex.weight << ")";
    ////}

    ////cout << endl;

	//////////////////////////////////////////////

	////cout << " a to b is " << g.get_edge(va.id, vb.id) << endl;



	//////////////////////////////////////////////

    //cout << "\nStrongly Connected Components" << endl;

    //vector<vector<vertex<int>>> scc = strongly_connected_components(g);

    //cout << "\n\nprinting scc size: " << scc.size() << endl;
    //for (auto vector : scc) {
    //    cout << "group" << endl;
    //    for (auto vertex : vector) {
    //        cout << "(" << vertex.id << ", " << vertex.weight << ")";
    //    }
    //    cout << endl;
    //}

    ////cout << "Topological Sort" << endl;
    ////vector<vertex<int>> top_sort = topological_sort(g);
    ////for (auto vert : top_sort) {
    ////    cout << "(" << vert.id << ", " << vert.weight << ")";
    ////}

    ////cout << endl;

    ////cout << "Low_cost_delivery from A = " << low_cost_delivery(g, 0) << endl;

 directed_graph<int> g;
    vertex<int> va = vertex<int>(0, 800);        //A
    vertex<int> vb = vertex<int>(1, 300);        //B
    vertex<int> vc = vertex<int>(2, 400);        //C
    vertex<int> vd = vertex<int>(3, 710);        //D
    vertex<int> ve = vertex<int>(4, 221);        //E

    vertex<int> cc = vertex<int>(66, 200);

    g.add_vertex(va);
    g.add_vertex(vb);
    g.add_vertex(vc);
    g.add_vertex(vd);
    g.add_vertex(ve);
    g.add_vertex(cc);

    g.add_edge(va.id, vb.id, 600); //A-B 6
    g.add_edge(va.id, vc.id, 900); //A-C 9
    g.add_edge(vb.id, ve.id, 3000); //B-E 3
    g.add_edge(vc.id, vd.id, 4000); //C-D 4
    g.add_edge(vd.id, va.id, 1); //D-A 1
    g.add_edge(vd.id, vc.id, 700); //D-C 7
    g.add_edge(vd.id, ve.id, 500); //D-E 5

    cout << "Shortest Path " << endl;
    vector<vertex<int>> short_path = shortest_path(g, 0, 66);
    cout << "size " << short_path.size() << endl;
    for (auto vertex : short_path) {
            cout << "(" << vertex.id << ", " << vertex.weight << ")";
    }
    cout << endl;


    //cout << "\nStrongly Connected Components" << endl;

    //vector<vector<vertex<int>>> scc = strongly_connected_components(g);

    //cout << "\n\nprinting scc size: " << scc.size() << endl;
    //for (auto vector : scc) {
    //    cout << "group" << endl;
    //    for (auto vertex : vector) {
    //        cout << "(" << vertex.id << ", " << vertex.weight << ")";
    //    }
    //    cout << endl;
    //}

    //cout << "Topological Sort" << endl;
    //vector<vertex<int>> top_sort = topological_sort(g);
    //for (auto vert : top_sort) {
    //    cout << "(" << vert.id << ", " << vert.weight << ")";
    //}

    cout << endl;

    cout << "Low_cost_delivery from A = " << low_cost_delivery(g, 0) << endl;



}