#include <iostream>
#include <vector>
using namespace std;

class Stack {
private:
    vector<int> s;
    int maxSize;

public:
    Stack(int size) : maxSize(size) {}

    void push(int item) {
        if (s.size() < maxSize) {
            s.push_back(item);
        } else {
            cout << "Stack is overflow\n";
        }
        display();
    }

    int pop() {
        if (s.empty()) {
            cout << "Stack is underflow\n";
            return -1; // Return an invalid value or handle error
        } else {
            int item = s.back();
            s.pop_back();
            return item;
        }
    }

    void display() {
        cout << "top --> ";
        for (auto it = s.rbegin(); it != s.rend(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }
};

int main() {
    int max, choice, item;
    cout << "Enter stack size: ";
    cin >> max;
    Stack stack(max);

    do {
        cout << "1. PUSH\n2. POP\n3. EXIT\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter the element: ";
                cin >> item;
                stack.push(item);
                break;
            case 2:
                item = stack.pop();
                if (item != -1) {
                    cout << "Popped: " << item << endl;
                }
                break;
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
                break;
        }
    } while (choice != 3);

    return 0;
}
