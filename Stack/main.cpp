#include <iostream>
using namespace std;

class Stack {
private:
    int* stackData;   // Dynamic array for storing elements
    int capacity;     // Maximum capacity of the stack
    int top;          // Index of the top element in the stack

    // Check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Check if the stack is full
    bool isFull() {
        return top + 1 == capacity;
    }

public:
    // Constructor with a fixed capacity
    Stack(int maxCapacity) : capacity(maxCapacity), top(-1) {
        stackData = new int[capacity];
    }

    // Destructor to free up memory
    ~Stack() {
        delete[] stackData;
    }

    // Push an element onto the stack
    void push(int value) {
        if (isFull()) {
            cout << "Stack overflow. Cannot push " << value << ".\n";
            return;
        }
        stackData[++top] = value;
        cout << "Pushed " << value << " onto the stack.\n";
    }

    // Pop an element from the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop.\n";
            return;
        }
        cout << "Popped " << stackData[top--] << " from the stack.\n";
    }

    // Peek at the top element of the stack
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot peek.\n";
            return -1; // Return -1 or any other error value
        }
        return stackData[top];
    }
};

int main() {
    Stack s(3); // Create a stack with a maximum capacity of 3
    s.push(10);
    s.push(20);
    cout << "Top element is: " << s.peek() << endl; // Should display 20
    s.push(30);
    s.push(40); // Should indicate stack overflow
    s.pop();
    cout << "Top element after pop is: " << s.peek() << endl; // Should display 20
    s.pop();
    s.pop();
    s.pop(); // Should indicate stack is empty
    return 0;
}