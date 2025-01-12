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

    void prepend(T value)
    {
        Node<T> *newNode = new Node<T>(value);
        newNode->next = head; // locatin for the haed next
        head = newNode;       // then the hade = newNode
    }

    // Function to insert a node after the node that p points to
    void insert(Node<T> *p, T value)
    {
        if (!p)
        {
            cout << "Error: Provided pointer is null." << endl;
            return;
        }

        Node<T> *newNode = new Node<T>(value);
        newNode->next = p->next;
        p->next = newNode;
    }

    // Function to delete a node by value
    void remove(T value)
    {
        if (!head)
            return;

        if (head->data == value) //delete the first item in the linked list
        {
            Node<T> *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node<T> *current = head;
        while (current->next && current->next->data != value)
        {
            current = current->next;
        }

        if (current->next)
        {
            Node<T> *temp = current->next;
            current->next = current->next->next;
            delete temp;
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
    list.append(25);
    list.append(555);
    list.prepend(5);
    list.display();
    return 0;
}