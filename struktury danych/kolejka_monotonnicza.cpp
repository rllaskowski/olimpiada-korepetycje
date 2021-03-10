#include <iostream>
#include <deque>

template<typename T>
class MaxQueue {

private:    
    struct element {
        T value;
        int waiting; 
    };  

    std::deque<element> q;
    int _size;

public:
    
    MaxQueue() : _size{0} {}

    T max() {
        return q.begin()->value;
    }

    void push(T value) {
        struct element newElement = {value, 0};

        while (!q.empty() && q.rbegin()->value <= value) {
            newElement.waiting += 1+q.rbegin()->waiting;
            q.pop_back();
        }

        q.push_back(newElement);
    }

    void pop() {
        if (q.begin()->waiting > 0) {
            q.begin()->waiting--;
        } else {
            q.pop_front();
        }
        --_size;
    }

    int size() {
        return _size;
    }
};

int main() {
    MaxQueue<int> q;

    q.push(10);
    q.push(12);

    std::cout << q.max() << std::endl;

    q.pop();

    std::cout << q.max() << std::endl;

}