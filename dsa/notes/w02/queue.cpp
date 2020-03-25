#include <iostream>
#include <queue>
#include <bits/stdc++.h>    // use basic stack in c++

using namespace std;

void show_queue( queue<int> q ) {
    cout << "all elem in queue";
    while (!q.empty()) {
        cout << ' ' << q.front();
        q.pop();
    }
    cout << endl;
}

void show_stack (stack<int> s) {
    cout << "all elem in stack";
    while (!s.empty()) {
        cout << ' ' << s.top();
        s.pop();
    }
    cout << endl;
}

void try_queue() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.pop();
    q.emplace(3);
    q.emplace(4);
    q.pop();
    q.emplace(5);

    show_queue(q);
}

void try_stack() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.pop();
    s.push(3);
    s.push(4);
    s.pop();
    s.push(5);

    show_stack(s);
}

int main() {
    try_queue();
    try_stack();
    return 0;
}