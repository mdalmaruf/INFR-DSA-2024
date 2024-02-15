class CircularQueue:
    """A circular queue implemented using a Python list."""

    def __init__(self, capacity):
        self.queue = [None] * capacity  # Initialize the queue with a fixed capacity
        self.head = 0  # Front pointer
        self.tail = 0  # Rear pointer
        self.count = 0  # Number of elements in the queue
        self.capacity = capacity  # Maximum capacity of the queue

    def is_empty(self):
        """Check if the queue is empty."""
        return self.count == 0

    def is_full(self):
        """Check if the queue is full."""
        return self.count == self.capacity

    def enqueue(self, item):
        """Add an item to the end of the queue."""
        if self.is_full():
            raise IndexError("enqueue to full queue")
        self.queue[self.tail] = item
        self.tail = (self.tail + 1) % self.capacity
        self.count += 1

    def dequeue(self):
        """Remove and return the front item of the queue."""
        if self.is_empty():
            raise IndexError("dequeue from empty queue")
        item = self.queue[self.head]
        self.queue[self.head] = None  # Optional: clear the slot for garbage collection
        self.head = (self.head + 1) % self.capacity
        self.count -= 1
        return item

    def peek(self):
        """Return the front item of the queue without removing it."""
        if self.is_empty():
            raise IndexError("peek from empty queue")
        return self.queue[self.head]

    def size(self):
        """Return the number of items in the queue."""
        return self.count

# Example usage
if __name__ == "__main__":
    capacity = 5
    queue = CircularQueue(capacity)
    for i in range(capacity):
        queue.enqueue(i)
        print(f"Enqueued: {i}")

    print("Now dequeueing...")
    while not queue.is_empty():
        print(f"Dequeued: {queue.dequeue()}")
