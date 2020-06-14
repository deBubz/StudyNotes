#include <limits.h>
#include <stdio.h>
#include <iostream>
#include <stack>
#include <unordered_map>
#define v_count 6

using namespace std;

void add_map(unordered_map<int, int> &m, int i) {
	m[i] = i+3;
}

int main() {
	cout << "hey hey passing maps time" << endl;
	unordered_map<int, int> u_map;

	for (int i = 0; i < 5; i++)
	{
		add_map(u_map, i);
	}

	//s.push(1);

	for (int i = 0; i < 5; i++)
	{
		cout << i << ", " << u_map[i] << endl;
	}

	cout << "test counting" << endl;
	int c = 0;
	pair<int, int> p = pair<int, int>(0,0);

	p = pair<int, int>(c++, c++);

	cout << p.first << " " << p.second<< endl;

}
