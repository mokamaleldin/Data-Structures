#include <iostream>
#define nullptr NULL
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node *next; // same type Node (علشان تشاور علي النود من نفس النوع عملتها نود)

    // make the node the data with value
    // make the next to be null (أي أن العقدة لا تشير إلى أي عقدة أخرى بعد)
    Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class LinkedList
{
private:
    Node<T> *head; // i add <T> to make it take any type (Node *head it will not take any type) also because i use the template

public:
    // make the head to be the null because it is the first item in the linked list
    LinkedList() : head(nullptr) {}

    void append(T value)
    {
        // make a new node
        // newNode => Node<T> هو مؤشر إلى كائن من النوع
        // new => تُستخدم لإنشاء كائن جديد في الذاكرة الديناميكية
        Node<T> *newNode = new Node<T>(value);

        if (!head)
        {
            head = newNode;
        }
        // temp = head
        // temp->next => يتم التكرار حتى الوصول إلى آخر عقدة في القائمة
        else
        {
            Node<T> *temp = head;
            while (temp->next)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void display() const
    {
        Node<T> *temp = head;
        while (temp)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }
};

int main()
{
    LinkedList<int> list;

    list.append(10);
    list.append(20);
    list.append(30);
    list.append(40);

    list.display();

    return 0;
}