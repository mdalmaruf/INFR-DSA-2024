class Stack:
    def __init__(self, size):
        self.stack = []
        self.max_size = size

    def push(self, item):
        if len(self.stack) < self.max_size:
            self.stack.append(item)
        else:
            print("Stack is overflow")
        self.display()

    def pop(self):
        if not self.stack:
            print("Stack is underflow")
            return None  # Return None or raise an exception
        else:
            return self.stack.pop()

    def display(self):
        print("top -->", end=" ")
        for item in reversed(self.stack):
            print(item, end=" ")
        print()

if __name__ == "__main__":
    max_size = int(input("Enter stack size: "))
    stack = Stack(max_size)

    while True:
        print("1. PUSH\n2. POP\n3. EXIT")
        choice = int(input("Enter your choice: "))
        if choice == 1:
            item = int(input("Enter the element: "))
            stack.push(item)
        elif choice == 2:
            item = stack.pop()
            if item is not None:
                print(f"Popped: {item}")
        elif choice == 3:
            print("Exiting...")
            break
        else:
            print("Invalid choice.")
