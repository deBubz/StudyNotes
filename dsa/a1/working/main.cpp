#include "./test.hpp"


int main(){
	cout << "Test Cons\t\t" << testConstructor_AddVertex_Contains() << endl;
	cout << "--------------------------" << endl;
	cout << "Test GetVert\t\t" << testGetVertices() << endl;
	cout << "--------------------------" << endl;
	cout << "Test RemoveVert\t\t" << testRemoveVertex() << endl;
	cout << "--------------------------" << endl;
	cout << "Test Edges\t\t" << testAddEdge_Adjacent_GetNeighbours() << endl;
	cout << "--------------------------" << endl;
	cout << "Test 2nd order\t\t" << test2ndOrderNeighbours() << endl;
	cout << "--------------------------" << endl;
	cout << "Test Degree\t\t" << testVertexDegrees() << endl;
	cout << "--------------------------" << endl;
	cout << "Test Remove Edge\t" << testRemoveEdge() << endl;
}