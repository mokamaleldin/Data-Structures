#include <iostream>
using namespace std;


class stack{
    private:
        int *items;
        int capacity;
        int top;

        bool isEmpty(){
            return top == -1; 
        }

        void resize(){
            int newCapacity = capacity * 2;
            int *newItems = new int[newCapacity];

            for (int i = 0; i < capacity;i++){
                newItems[i] = items[i];
            }

            delete[] items;
            items = newItems;
            capacity = newCapacity;
        }

    public:
    
        // stack(){top =-1}
        stack(int initialCapacity =2):capacity(initialCapacity),top(-1)
        {
            items = new int[capacity];
        }

        ~stack() {
            delete[] items;
        }

       void push(int element){
            if (top + 1 == capacity) {
                resize();
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
    stack1.push(30);
    stack1.push(40); 
    stack1.pop();
    cout << "Top element (peek): " << stack1.peek() << endl;
    stack1.pop();
    stack1.pop();

    cout << "\n\n\n\n\n";
    return 0;
}