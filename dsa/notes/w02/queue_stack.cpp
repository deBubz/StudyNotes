#include <iostream>
#include <queue>
#include <bits/stdc++.h>

// Queue and stack example

void show_queue(std::queue<int> q);
void show_stack(std::stack<int> s);

void try_queue();
void try_stack();

void show_queue(std::queue<int> q)
{
    std::cout << "All Elems in Queue";
    while(!q.empty())
    {
        std::cout << ' ' << q.front();
        q.pop();
    }
    std::cout << std::endl;
}

void show_stack(std::stack<int> s)
{
    std::cout << "All elems in Stack";
    while(!s.empty())
    {
        std::cout << ' ' << s.top();
        s.pop();
    }
    std::cout << std::endl;
}

void try_queue()
{
    std::queue<int> q;

	q.push (1);
	q.push (2);
	q.pop();
	q.emplace (3);
	q.emplace (4);
	q.pop();
	q.emplace (5);
	
	show_queue(q);
}

void try_stack()
{
    std::stack<int> s;

    s.push(1);
    s.push(2);
	s.pop();
    s.push(3);
    s.push(4);
	s.pop();
    s.push(5);
	
    show_stack(s);
}

int main()
{
    try_queue();
    try_stack();
    return 0;
}

