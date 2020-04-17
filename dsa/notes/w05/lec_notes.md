# Data structures and Algorithms

## Graphs

- Great modelling tools
- **Graphs main features**
  - vervices
  - edges
  - one edge between a pair of vertices
- Different **types** of graphs are made from changing the above condition
  - **Directed graphs** edges with directions
  - **Multigraphs** many edge per pair
  - **Hypergraphs** many vertices per edge

### Graphs as Mathematical Objects

- Vertices can model:
  - Computers, websites, processes
  - proteins
  - production facilities
- Edge model relationship between:
  - network links, hyperlinks
  - protein interactions
  - shared resources, transport link

### Notations & Definitions

- **adjacent** 2 vertices have an edge between
- **incident** vertex is one pair that forms and edge 
- **degree** number on edges incident to a vertex
- **G, H** uppercase letters = graphs
- **u, v** vertices
- **d, e** edges
  - undirected graphs `uv`
  - directed graphs `(u, v)`

### Data structure

As an abstract data structure, graphs need to support

```cpp
void addVertex(Vertex v);
void removeVertex(Vertex v);

void addEdge(Vertex u, Vertex v);
void removeEdge(Vertex u, Vertex v);

bool adjacent(Vertex u, Vertex v);
size_t degree(Vertex u);

// return vertices in a graph
// return edges incident to a vertex
// return vertices adjacent to a vertex
```

### DS - Adjacency Matrix

- simplest form
  - edges stored as 2d matrix ( `vector<vector<bool>>` edges OR `edge[][]` )
- enhancements
  - can use a numeric matrix to give *weighed edge*
  - supports **directed** and **undirected**
  - if vertices have **associated data**, they can be stored separately
- quick access `O(1)`, spaces `O(n^2)`

### DS - Adjacency List

- Each vertex has associated with a list of its adjacent vertices forming an array of linked lists or similar.
- Easy to modify for more complex edge and vertex data structure
- Works best for sparse graphs

> OK what the fuck is this

### DS - object oriented

- Extreme version
  - classes for vertex, edge and graphs
  - vertex contains list of edge
  - each edge knows its endpoints
  - the graph knows about everything
  - lots of reference to keep track of
  - slower to implement
- Evaluation Criteria
  - Search time, space
  - support for modification

## Traversing Graphs

algorithms for graph traversal focuses on

- **vising history** which vertices was visited
- **visiting order** which neighbour to travel to next
  - use an order or an arbitrary one

### Depth first Traversal

- recursively pick unvisited neighbour to visit depthward
- **backtrack** to previous recorded neighbour when a dead ends occurs

[Recursive](https://www.tutorialspoint.com/data_structures_algorithms/depth_first_traversal.htm)

```md
// pseudo
DFT(Vertex v){
    mark v as visited;
    visit(v)
    for(u in v) {
        if(!u.visited) DFT(u);
    }
}
```

Iterative

```md
// pseudo 
DFT(){
    starting vertex v;
    Stack unprocessed = new Stack();
    unprocessed.push(v);

    while (!unprocessed.empty()) {
        Vertex u = unprocessed.pop();
        visit(u);
        mark(u);

        for(w in u) {
            unprocessed.push(w);
        }
    }
}
```

### Breadth first traversal

- pick a starting vertex and put it in a `queue`
- inherently iterative, possible but no point to implement recursive
- takes a vertex from `queue` visit it and place its neighbours in the queue

```md
// pseudo
BFT() {
    starting vertex v;
    Queue unprocessed = new Queue();
    unprocessed.push(v);

    while (!unprocessed.empty) {
        Vertex u = unprocessed.pop();
        visit(u); mark(u);

        for(neighbour w of u) {
            if(!w.marked) unprocessed.push(w);
        }
    }
}
```

### Depth first v Breadth first

- Some graphs produce the same traversal order for both
- Iterative version for both are the same (swap `stack` with `queue`)
- both `O(|v| + |e|)`

## Greedy Algos

- Narrow Sense
- Broad Sense

### Is my algo greddy

## Spanning trees of Graphs

### Problem

### Spanning trees

### Unweighted Graphs

> a graph where all edges weghts are the same


### Weighted Graphs

- if theres different weights on the edges, a simple traversal is not enough

Use these 2 following greedy algos

### Prim's algo

Given a connected graph G

1. pick starting vertex `v`, add to the partially complete tree `T`
2. While `|T| < n`
   1. let `E'` be the set of edges where `uv` where `u in T` and `v in G/T`
   2. let `uv` be the edges of the smallest weight in `E'`
   3. add `uv` to the edges of `T` and `v` to verteces of `T`
3. Return `T` 

In other words

- keep track of which edges and vertices in the tree
- pick the smallest edge and vertices are in the tree
- keep going until the whole graph is spanned

```md
// pseudo
prims(Graph G, Tree T) {
    add T to starting v from G;
    while (|T| < |G|) {
        find u,v = argmin weight(vu);

        add vu to T;
    }
}
```

### Kruskal's Algo

#### Other Algos

- (misc) sort of like a backward;s Kruskal
- we remove edges, instead of adding them and see what we're left with at the end.

### Disconnected Graphs

if graph has several disconnected component, we **cannot** get a spanning tree. *Must be connected*.

The algos we have so far wont work.


---

## A1

could be

- binary trees
- directed graphs


