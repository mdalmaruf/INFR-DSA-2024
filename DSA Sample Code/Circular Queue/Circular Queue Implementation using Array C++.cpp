#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T, size_t SIZE>
class CircularQueue {
private:
    T data[SIZE];
    size_t head = 0; // Points to the front of the queue
    size_t tail = 0; // Points to the element following the last item
    size_t count = 0; // Number of elements in the queue

public:
    void enqueue(const T& item) {
        if (count >= SIZE) throw out_of_range("Queue Overflow");
        data[tail] = item;
        tail = (tail + 1) % SIZE;
        ++count;
    }

    T dequeue() {
        if (isEmpty()) throw out_of_range("Queue Underflow");
        T item = data[head];
        head = (head + 1) % SIZE;
        --count;
        return item;
    }

    T front() const {
        if (isEmpty()) throw out_of_range("Queue Underflow");
        return data[head];
    }

    bool isEmpty() const {
        return count == 0;
    }

    bool isFull() const {
        return count == SIZE;
    }
};

int main() {
    CircularQueue<int, 5> queue; // Create a queue with a maximum size of 5

    // Enqueue elements
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    
    queue.enqueue(4);
    queue.enqueue(5);
    queue.dequeue();
    queue.enqueue(6);

    // Display the front item of the queue
    cout << "Front item: " << queue.front() << endl;

    // Dequeue all items and display them
    cout << "Items dequeued from queue:" << endl;
    while (!queue.isEmpty()) {
        cout << queue.dequeue() << endl;
    }

    return 0;
}
