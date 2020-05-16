#include<iostream>
#include"queue.h"

// implementing queue using arrays
int main()
{
	queue<int> *s = new queue<int>(5);

	for (int i = 0; i < 20; i++)
	{
		int in = std::rand()%20 + 1;
		s->push(in);
	}

	s->push(3);

	int removed = std::rand()%20;
	std::cout << "removed " << removed << std::endl;
	for (int i = 0; i < removed; i++)
	{
		s->pop();
	}


	s->displayInfo();
}