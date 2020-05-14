#include <iostream>
#include <queue>

// use a suitable container
// try vector
#include <vector>

int main() {
    // std::queue<std::vector<int>> q;
    std::queue<int> q;

    for (int i = 0; i < 20; i++)
    {
        // std::vector<int> v = {i};
        int v = i;
        q.push(v);
    }

    while (!q.empty()) {
        std::cout << q.front() << " ";
        q.pop();
    }

    std::cout << std::endl;
    
}