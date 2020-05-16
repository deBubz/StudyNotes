#include <iostream>
#include "stack.h"

// stack using array

int main()
{
	stack<int, 10> s;		// type, size

	for (int i = 0; i < 12; i++)
	{	// 12 to check if the stack function works
		s.push(i);
	}

	while (!s.empty())
	{	// print stack
		std::cout << s.top() << std::endl;
		s.pop();
	}
}