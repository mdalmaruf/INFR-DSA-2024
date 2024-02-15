class Queue:
    """A queue implemented using a Python list."""
    
    def __init__(self):
        self.queue = []
        self.head = 0

    def enqueue(self, item):
        """Add an item to the end of the queue."""
        self.queue.append(item)

    def dequeue(self):
        """Remove and return the front item of the queue."""
        if self.is_empty():
            raise IndexError("dequeue from empty queue")
        item = self.queue[self.head]
        self.head += 1
        # Optionally, clear memory if all items are dequeued
        if self.head > len(self.queue) // 2:
            self.queue = self.queue[self.head:]
            self.head = 0
        return item

    def peek(self):
        """Return the front item of the queue without removing it."""
        if self.is_empty():
            raise IndexError("peek from empty queue")
        return self.queue[self.head]

    def is_empty(self):
        """Check if the queue is empty."""
        return self.head == len(self.queue)

# Example usage
if __name__ == "__main__":
    queue = Queue()
    queue.enqueue('a')
    queue.enqueue('b')
    queue.enqueue('c')

    print("Front item:", queue.peek())  # Expected output: a
    print("Dequeued item:", queue.dequeue())  # Expected output: a
    print("Dequeued item:", queue.dequeue())  # Expected output: b
    print("Dequeued item:", queue.dequeue())  # Expected output: c
    # The next line will raise an exception because the queue is empty
    # print("Dequeued item:", queue.dequeue())

