#include <cstdlib>
#include <sstream>
#include <ctime>
#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <limits>
#include <utility>

#include "working_map_list.hpp"

using namespace std;

static int test_size = 10;

int testConstructor_AddVertex_Contains(){
    directed_graph<int> g;

    if(g.num_vertices() != 0){ return 1;}
    if(g.num_edges() != 0){ return 2; }

    // //  srand(time(0));
    int r = rand()%test_size + 1;

    for (int i = 0; i < r; ++i){
        g.add_vertex(vertex<int>(i+1,i+1)); // add vertices
        if(!g.contains(i+1)){
            return 3;
        }
    }
    if(g.num_vertices() != r){ return 4; }
    return 0;   // correct
}

int testGetVertices(){

    directed_graph<int> g;

    // //  srand(time(0));
    int r = rand()%test_size + 1;
    for (int i = 0; i < r; ++i){
        g.add_vertex(vertex<int>(i+1, (i+1)*2));  // add vertices
    }

    vector<vertex<int>> v = g.get_vertices();

    if(r != v.size()){
        return 5;
    }
    for (int i = 0; i < v.size(); ++i){
        if(!g.contains(v[i].id)){
            return 6;
        }
    }
    for (int i = 0; i < v.size()-1; ++i){
        for (int j = i + 1; j < v.size(); ++j){
            if(v[i].id == v[j].id){
                return 7;
            }
        }
    }

    //  srand(time(0));
    int s = rand()%r;
    for (int i = 0; i < s; ++i){
        g.remove_vertex(i+1);
    }
    v = g.get_vertices();

    if(r-s != v.size()){
        return 8;
    }
    for (int i = 0; i < v.size(); ++i){
        if(!g.contains(v[i].id)){
            return 9;
        }
        if(v[i].weight != v[i].id*2){
            return 10;
        }
    }
    for (int i = 0; i < v.size()-1; ++i){
        for (int j = i + 1; j < v.size(); ++j){
            if(v[i].id == v[j].id){
                return 11;
            }
        }
    }

    return 0;
}

int testRemoveVertex(){

    /* part 1 */
    directed_graph<int> g;

    //  srand(time(0));
    int r = rand()%test_size + 1;
    for (int i = 0; i < r; ++i){
        g.add_vertex(vertex<int>(i+1, (i+1)*2)); // add vertices
        if(!g.contains(i+1)){
            return 12;
        }
    }
    if(g.num_vertices() != r){
        return 13;
    }

    /* part 2 */
    vector<int> in;
    vector<int> out;

    for (int i = 0; i < r; ++i) {
        //  srand(time(0));
        if (rand()%2 == 0) {
            in.push_back(i+1);
        }else {
            out.push_back(i+1);
        }
    }
    for (auto i : out){
        g.remove_vertex(i);  // remove vertices
    }

    if(g.num_vertices() != r - out.size()){
        return 14;
    }
    for (auto i : out){
        if(g.contains(i)){
            return 15;
        }
    }
    for (auto i : in){
        if(!g.contains(i)){
            return 16;
        }
    }

    return 0;

}

int testAddEdge_Adjacent_GetNeighbours() {

    directed_graph<int> g;

    //  srand(time(0));
    int r = rand()%test_size + 2;
    for (int i = 0; i < r; ++i){
        g.add_vertex(vertex<int>(i+1,(i+1)*2)); // add vertices
    }

    bool re[r][r];
    for (int i = 0; i < r; ++i){
        for (int j = 0; j < r; ++j){
            //  srand(time(0));
            if (rand()%2 == 0 && i != j){
                re[i][j] = true;
                g.add_edge(i+1, j+1, (i+1)+(j+1)); // add edges
                cout << "edge: " << (i+1) << " " << (j+1) << endl;
            }else{
                re[i][j] = false;
            }
        }
    }

    for (int i = 0; i < r; ++i){

        for (int j = 0; j < r;  ++j){
            if (re[i][j]){
                if(!g.adjacent(i+1,j+1)){
                    return 17;
                }
            }else {
                if(g.adjacent(i+1,j+1)){
                    return 18;
                }
            }
        }

        // get list of neighbours
        vector<vertex<int>> n_i = g.get_neighbours(i+1);
        if(g.out_degree(i+1) != n_i.size()){
            //cout << "out " << g.out_degree(i+1) << " size " << n_i.size()<< endl;
            return 19;
        } //else cout << 19 << " correct" << endl;
        //cout << "testing a" << endl;

        // get list of adjacents
        for (int j = 0; j < n_i.size(); ++j){
            if(!g.adjacent(i+1, n_i[j].id)){
                return 20;
            } //else cout << 20 << " correct" << endl;
            if(!re[i][n_i[j].id-1]){
                return 21;
            }
        }
        //cout << "testing b" << endl;
        for (int j = 0; j < n_i.size()-1; ++j){
            for (int k = j + 1; k < n_i.size(); ++k){
                if(n_i[j].id == n_i[k].id){
                    return 22;
                }
            }
        }
        //cout << "testing c" << endl;
    }

        cout << "what\n";
    vector<vertex<int>> bfs = g.breadth_first(1);

    cout << "path from 1 size:" << g.num_vertices() << "\n";
    cout << "edge count " << g.num_edges() << endl;
    for(vertex<int> v : bfs) {
        cout << v.id << " ";
    }
    cout << endl;





    return 0;
}

int test2ndOrderNeighbours(){

    directed_graph<int> g;

    int r = rand()%test_size + 3;
    for (int i = 0; i < r; ++i){
        g.add_vertex(vertex<int>(i+1, (i+1)*2)); // add vertices
    }

    bool re[r][r];
    for (int i = 0; i < r; ++i){
        for (int j = 0; j < r;  ++j){
            if (rand()%2 == 1 && i != j){
                re[i][j] = true;
                g.add_edge(i+1, j+1, (i+1)+(j+1)); // add edges
            } else {
                re[i][j] = false;
            }
        }
    }

    for(int i=0; i<r; ++i){

        int count_second_i = 0;

        for(int k=0; k<r; ++k){
            for(int j=0; j<r; ++j){
                if(re[i][j] && re[j][k] && i!=k){
                    count_second_i += 1; // increase i's 2nd-order neighbour by 1
                    break;
                }
            }
        }

        vector<vertex<int>> son_i = g.get_second_order_neighbours(i+1);

        if(count_second_i != son_i.size()){
            //cout << "test " << count_second_i << " ?? " << son_i.size() << endl;
            return 23;
        }

        for (int j = 0; j < son_i.size()-1; ++j){
            for (int k = j + 1; k < son_i.size(); ++k){
                if(son_i[j].id == son_i[k].id){
                    return 24;
                }
            }
        }
    }

    return 0;
}

int testVertexDegrees(){

    directed_graph<int> g;


    //  srand(time(0));
    int r = rand()%test_size + 2;
    for (int i = 0; i < r; ++i){
        g.add_vertex(vertex<int>(i+1,(i+1)*2)); // add vertices
    }


    bool re[r][r];
    for (int i = 0; i < r; ++i){
        for (int j = 0; j < r; ++j){

            //  srand(time(0));
            if (rand()%2 == 1 && i != j){
                re[i][j] = true;
                g.add_edge(i+1,j+1,(i+1)+(j+1)); // add edges
                cout << "edge: " << i+1 << " " << j+1 << endl;
            }else{
                re[i][j] = false;
            }

        }
    }

    for (int i = 0; i < r; ++i){

        int in_degree_count = 0;
        int out_degree_count = 0;

        for (int j = 0; j < r;  ++j){
            if (re[j][i]){
                in_degree_count++;
            }
            if(re[i][j]){
                out_degree_count++;
            }
        }
        if(g.in_degree(i+1) != in_degree_count){
            cout << g.in_degree(i+1) << " out is " << out_degree_count << endl;
            return 25;
        }
        if(g.out_degree(i+1) != out_degree_count){
            return 26;
        }
        if(g.degree(i+1) != in_degree_count + out_degree_count){
            return 27;
        }
    }



    //cout << "what\n";
    vector<vertex<int>> bfs = g.breadth_first(2);

    cout << "\npath from 2 size:" << g.num_vertices() << "\n";
    cout << "edge count " << g.num_edges() << endl;
    for(vertex<int> v : bfs) {
        cout << v.id << " ";
    }
    cout << endl;

    //cout << "reachable  from 4 - 1 " << g.reachable(4,1);



    return 0;

}

int testRemoveEdge(){

    directed_graph<int> g;

    //  srand(time(0));
    int r = rand()%test_size + 2;
    for (int i = 0; i < r; ++i){
        g.add_vertex(vertex<int>(i+1, (i+1)*2)); // add vertices
    }

    // prepare edges
    struct PairHash{
        size_t operator()(const pair<int, int> &key) const{
            return hash<int>()(key.first) * hash<int>()(key.second);
        }
    };
    unordered_set<pair<int, int>, PairHash > edges;
    unordered_set<pair<int, int>, PairHash > removed_edges;

    int m = 0;
    for (int i = 0; i < r; ++i){
        for (int j = 0; j < r;  ++j){

            //  srand(time(0));
            if (rand()%2 == 0 && i != j){

                g.add_edge(i+1,j+1,(i+1)+(j+1)); // add edges
                m++;

                //  srand(time(0));
                if (rand()%2 == 0){
                    removed_edges.insert({i+1,j+1}); // edges to delete
                }else{
                    edges.insert({i+1,j+1});// edges to keep
                }
            }
        }
    }

    if(g.num_edges() != m){
        return 28;
    }

    for (auto e : removed_edges){
        g.remove_edge(e.first, e.second); // remove the edges marked "to delete"
    }
    if(g.num_edges() != m - removed_edges.size()){
        return 29;
    }

    for (auto e : edges){
        if(!g.adjacent(e.first, e.second)){
            return 30;
        }
    }
    for (auto e : removed_edges){
        if(g.adjacent(e.first, e.second)){
            return 31;
        }
    }

    return 0;
}

