#include <iostream>
#include <stdexcept>

// Template class for Stack which allows storing any data type T
template <typename T>
class Stack {
private:
    // Private Node structure used for stack elements
    struct Node {
        T data;          // Data of type T
        Node* next;      // Pointer to next Node

        // Node constructor initializes data and next pointer
        Node(T val, Node* nxt = nullptr) : data(val), next(nxt) {}
    };

    Node* topNode;     // Top node of the stack

public:
    // Stack constructor initializes top node as nullptr (empty stack)
    Stack() : topNode(nullptr) {}

    // Destructor to clean up memory by deleting all nodes in the stack
    ~Stack() {
        while (topNode != nullptr) {
            Node* temp = topNode;     // Temporarily store current top node
            topNode = topNode->next;  // Move top node to the next node
            delete temp;              // Delete the old top node
        }
    }

    // Pushes a new value onto the stack
    void push(const T& value) {
        Node* newNode = new Node(value, topNode);  // Create new node with value
        topNode = newNode;  // Update top node to be the new node
    }

    // Pops the top value from the stack and returns it
    T pop() {
        if (isEmpty()) {
            throw std::out_of_range("Stack Underflow");  // Throw exception if stack is empty
        }
        Node* temp = topNode;         // Temporarily store current top node
        T poppedValue = topNode->data;  // Get data from top node
        topNode = topNode->next;      // Move top node to next node
        delete temp;                  // Delete the old top node
        return poppedValue;           // Return the popped value
    }

    // Returns the top value of the stack without popping it
    T top() const {
        if (isEmpty()) {
            throw std::out_of_range("Stack Underflow");  // Throw exception if stack is empty
        }
        return topNode->data;  // Return data of top node
    }

    // Checks if the stack is empty
    bool isEmpty() const {
        return topNode == nullptr;  // Return true if top node is nullptr
    }
};

int main() {
    Stack<int> stack;  // Create a stack for integers
    stack.push(10);    // Push values onto the stack
    stack.push(20);
    stack.push(30);

    // Display the top item of the stack
    std::cout << "Top item: " << stack.top() << std::endl;
    // Pop all items from the stack and display them
    std::cout << "Items popped from stack:" << std::endl;
    while (!stack.isEmpty()) {
        std::cout << stack.pop() << std::endl;
    }

    return 0;
}
