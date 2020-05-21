#include <iostream>

using namespace std;

int main() {
	cout << "How do i test bool ptr" << endl;

	bool bool_a = false;
	bool bool_b = true;
	bool *regular_ptr = &bool_a;

	cout << "bool a " << regular_ptr[0] << endl;
	*regular_ptr++;
	cout << "bool a " << *regular_ptr << endl;

	cout << "======== 2d array =========";
	cout << "lets try making a 3x3 array";

	int size = 3;
	bool **matrix;

	for(int i = 0; i < size; i++) {
		matrix[0][i] = true;
	}

	cout << "\nPrinting matrix" << endl;

	//for(int x = 0; x < 1; x++) {
	//	for(int y = 0; y < size; y++) {
	//		cout << matrix[x][y] << " ";
	//	}
	//	cout << endl;
	//}


}