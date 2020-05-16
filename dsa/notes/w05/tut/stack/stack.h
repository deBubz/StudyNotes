#ifndef STACK_H
#define STACK_H

#include<iostream>

template<typename T, size_t s>
class stack
{
	private:
		T data[s];
		int length;
	public:
		stack() { length = 0; }
		~stack() {}

		void push(T t)
		{
			if(this->length < s) data[length++] = t;
			else std::cout << "Stack full" << std::endl;
		}

		T top() { return data[length-1]; }

		void pop() { this->length--; }
		bool empty() { return length == 0; }
};


#endif