#include <iostream>
using namespace std;

class stack
{
private:
    int *arr;
    int sizeOfArray;
    int top;

public:
    stack(int maxSizeOfArray)
    {
        sizeOfArray = maxSizeOfArray;
        top = -1;
        arr = new int[sizeOfArray];
    }

    // add
    void push(int element)
    {
        if (top == sizeOfArray - 1)
        {
            cout << "Stack is full";
            return;
        }
        top++;
        arr[top] = element;
    }

    // get the last items (top)
    void pop()
    {
        if (top == -1)
        {
            cout << "Stack is empty";
            return;
        }
        cout << "This is the element " << arr[top] << endl;
        top--;
    }

    // print the top
    void peek()
    {
        if (top == -1)
        {
            cout << "Stack is empty.\n";
            return;
        }
        cout << arr[top];
    }

    void display()
    {
        if (top == -1)
        {
            cout << "Stack is empty.\n";
            return;
        }
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
    }
};

int main()
{
    stack amr(10);

    amr.push(55); // 0
    amr.push(44); // 1
    amr.push(66); // 2

    amr.display(); // 66 ,44 ,

    cout
        << "\n\n\n\n\n";
    return 0;
}