#include <iostream>

using namespace std;


// the delete operator

void printInt(const int & a) {
	cout << "printing " << a << endl;
}

int main() {
	int * pt_a = new int;
	int * pt_b = new int(42);
	//int a = 21;

	cout << "*pta " << *pt_a << endl;
	cout << "*ptb " << *pt_b << endl;
	//printInt(a);

	delete pt_a;		// might break if pointer is not cleared from deleted mem
	delete pt_b;		// assign to nullptr

	//cout << *pt_a << endl;

	pt_a = nullptr;
	pt_b = nullptr;

	//cout << "*pta " << *pt_a << endl;	// core dumped, null pointers


	// misc ntoes
	// int * a					// pointer a = address		// *a = value		// &a address of pointer a
	// int a						// variable a = value
	int a = 3;

	cout << "pointer " << &a << endl;
	cout << "value " << a << endl;
}