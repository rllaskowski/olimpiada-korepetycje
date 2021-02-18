#include <iostream>

using namespace std;

const int M = 1 << 20;

int heap[M];
int size = 0;

int getMax() {
    return heap[1];
}

void heapify(int x) {
    int largest = x;

    if (x*2 <= size && heap[largest] < heap[x*2]) {
        largest = x*2;     
    }

    if (x*2+1 <= size && heap[largest] < heap[x*2+1]) {
        largest = x*2+1;     
    }

    if (largest != x) {
        swap(heap[x], heap[largest]);
        heapify(largest);
    }
}

void pop() {
    if (size > 0) {
        swap(heap[size], heap[1]);
        size--;
        heapify(1);
    }
}

void insert(int val) {
    int x = ++size;

    heap[x] = val;
    
    while (x > 1 && heap[x] > heap[x/2]) {
        swap(heap[x], heap[x/2]);
        x /= 2;
    }
}

int main() {
    insert(1);
    insert(8);
    insert(2);
    insert(4);
    insert(7);

    while (size > 0) {
        cout << getMax() << endl;
        pop();
    }

    return 0;
}