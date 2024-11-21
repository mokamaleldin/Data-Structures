#include <iostream>
using namespace std;

class TwoStacks
{
private:
    int size;
    int *arr;
    int top1;
    int top2;

public:
    TwoStacks(int n)
    {
        size = n;
        top1 = -1;
        top2 = size;
        arr = new int[size];
    }

    void push1(int value)
    {
        if (top1 < top2 - 1)
        {
            arr[++top1] = value;
            return;
        }
        cout << "Stack Overflow in Stack 1" << endl;
    }

    void push2(int value)
    {
        if (top1 < top2 - 1)
        {
            arr[--top2] = value;
            return;
        }
        cout << "Stack Overflow in Stack 1" << endl;
    }

    void pop1()
    {
        if (top1 > -1)
        {
            cout << "the vlaue of top 1 " << arr[top1--] << endl;
        }
    }

    void pop2()
    {
        if (top2 < size)
        {

            cout << "the vlaue of top 2 " << arr[top2++] << endl;
        }
    }

};

int main()
{
    TwoStacks s1(10);
    s1.push1(10);
    s1.push1(20);
    s1.push1(30);
    s1.push2(555);
    s1.push2(7474);
    s1.push2(370);

    s1.pop1();
    s1.pop2();

    cout << "\n\n\n\n\n";
};