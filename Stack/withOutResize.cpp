#include <iostream>
using namespace std;

class stack{
    private:
        int *items;
        int capacity;
        int top;

        bool isFull(){
            return top == capacity - 1;
        }
        bool isEmpty(){
            return top == -1; 
        }
    public:
    
        // stack(){top =-1}
        stack(int maxCapacity):capacity(maxCapacity),top(-1)
        {
            items = new int[capacity];
        }

        ~stack() {
            delete[] items;
        }

       void push(int element){
            if(isFull()){
                cout << "Stack is full";
                return;
            }
           top++;
           items[top] = element;
       }

       void pop(){
            if(isEmpty()){
                cout << "Stack is empty";
                return;
            }
            cout << "This is the element " << items[top--]<<endl;
       }

        //tell me what is the top
        int peek(){
            if (isEmpty()) {
                cout << "Stack is empty.\n";
                return -1;
            }
            return items[top];
        }
        
        void display(){
            if (isEmpty()) {
                cout << "Stack is empty.\n";
                return;
            }
            for (int i = top; i >= 0;i--){
                cout << items[i] << " ";
            }
        }
};

int main() {
    stack stack1(10);
    stack1.push(10);
    stack1.push(20);
    cout << "Top element is: " << stack1.peek() << endl; 
    stack1.push(30);
    stack1.push(40); 
    stack1.pop();
    cout << "Top element after pop is: " << stack1.peek() << endl;
    stack1.pop();
    stack1.pop();

    cout << "\n\n\n\n\n";
    return 0;
}