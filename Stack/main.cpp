#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class stack{
    private:
        int top;
        int item[MAX_SIZE];

        bool isFull(){
            return top == MAX_SIZE - 1;
        }
        bool isEmpty(){
            return top == -1; 
        }
    public:
    
        // stack():top(-1){}
        stack()
        {
            top = -1;
        }

       void push(int element){
            if(isFull()){
                cout << "Stack is full";
                return;
            }
           top++;
           item[top] = element;
       }

       void pop(){
              if(isEmpty()){
                cout << "Stack is empty";
                return;
              }
              cout << "This is the element " << item[top]<<endl;
              top--;
       }
};

int main() {
    stack stack1;
    stack1.push(5);
    stack1.push(15);
    stack1.push(2);
    stack1.pop();
    stack1.pop();

    cout << "\n\n\n\n\n";
    return 0;
}