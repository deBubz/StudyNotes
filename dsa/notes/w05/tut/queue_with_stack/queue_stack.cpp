#include <iostream>
#include <stack>

// implementing a queue using stack
struct queue_stack
{
	std::stack<int> ourStack;

	void push(int data) { ourStack.push(data); }

	int pop()
	{
		if (ourStack.empty())
		{	// check if empty
			std::cout << "Queue empty" << std::endl;
			exit(0);
		}

		int data = ourStack.top();	// set the top of the stack and store data
		ourStack.pop();				// pop stack, node is gone

		// if (stack is empty) return the popped data
		if (ourStack.empty()) return data;

		int item = pop();				// else keep popping until the stack is empty
											// return the first in data of the stack (first out array)
		ourStack.push(data);			// top of the stack will be pushed into the stack???

		return item;
	};
};



int main()
{
	queue_stack queue;
	for (int i = 0; i < 30; i++)
	{
		int x = std::rand()%30 + 1;
		queue.push(x);
	}


	for (int i = 0; i < 31; i++)
	{
		std::cout << queue.pop() << std::endl;
	}
}