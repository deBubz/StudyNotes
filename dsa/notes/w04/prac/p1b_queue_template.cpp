#include <iostream>

// ----- queue.h --------
#include <vector>

template <typename T>
class queue {
    private:
        std::vector<T> data;       // storing data
        int capacity = 0;
        int queue_front = 0;
        int queue_back = 0;
    public:
        queue(){};
        queue(int capacity){
            this->capacity = capacity;
        }
        ~queue(){};

        // methods
        void push(T t) {            // add to end
            this->data.push_back(t);
            this->queue_back++;
			this->capacity++;
        };

        T front() {                 // get from front of queue
            return this->data.at(this->queue_front);
        };

        void pop() {                // remove from front of queue
            this->queue_front++;
        };

        bool empty() {              // check if empty
            return this->queue_back - this->queue_front == 0;
        };

        void displayInfo() {
            std::cout << "capacity = " << this->capacity <<
                "\nsize = " << (this->queue_back - this->queue_front) <<
                "\nfront_position = " << this->queue_front << std::endl;
        };
};



// ----- main.cpp -------
// #import "queue.h"

int main() {
    int capacity;
    std::cout << "Initial Queue capacity:" << std::endl;
    std::cin >> capacity;

    // create queue
    queue<int> q(capacity);

    // add more
    for (int i = 0; i < 3 * capacity; i++) {
        q.push(i * 3);
    }

    // show
    q.displayInfo();

    while(!q.empty()) {
        std::cout << q.front() << std::endl;
        q.pop();
    }


}