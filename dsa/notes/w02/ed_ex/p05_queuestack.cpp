#include <iostream>
#include <queue>            // queue
#include <bits/stdc++.h>    // everything, bust mainly for stack

void showQ(std::queue<int> q){
    std::cout << "Show Queue";
    while (!q.empty()) {
        std::cout << " " << q.front();
        q.pop();
    }
    std::cout << std::endl;
}
void showS(std::stack<int> s){
    std::cout << "Show Stack";
    while(!s.empty()){
        std::cout << " " << s.top();
        s.pop();
    }
    std::cout << std::endl;
}

void tryQ(){
    std::queue<int> q;

    q.push(1);
    q.push(2);
    q.pop();
    q.emplace(3);
    q.emplace(4);     
    q.pop();
    q.emplace(5);

    showQ(q);
}
void tryS(){
    std::stack<int> s;

    s.push(1);
    s.push(2);
    s.pop();
    s.push(3);
    s.push(4);     
    s.pop();
    s.push(5);

    showS(s);
}

int main() {
    tryS();
    tryQ();
}