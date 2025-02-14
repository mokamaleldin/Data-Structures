#include <iostream>
#define nullptr NULL
using namespace std;
        
// Node class
template <typename T>              
class Node
{
public:
    T data;     // Data of the node
    Node *next; // Pointer to the next node

    // Constructor
    Node(T value) : data(value), next(nullptr) {}
};

// LinkedList class
template <typename T>
class LinkedList
{
private:
    Node<T> *head; // Pointer to the head node

public:
    // Constructor
    LinkedList() : head(nullptr) {}

    // Function to add a node at the end
    void append(T value)
    {
        Node<T> *newNode = new Node<T>(value);
        if (!head)
        {
            head = newNode;
        }
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

    // Function to add a node at the beginning
    void prepend(T value)
    {
        Node<T> *newNode = new Node<T>(value);
        newNode->next = head;
        head = newNode;
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

        if (head->data == value)
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

    // Function to display the linked list
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

    // Function to get the head of the list
    Node<T> *getHead() const
    {
        return head;
    }

    // Destructor to clean up memory
    ~LinkedList()
    {
        Node<T> *current = head;
        while (current)
        {
            Node<T> *nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

// Example usage
int main()
{
    LinkedList<int> list;

    // Append nodes
    list.append(10);
    list.append(20);
    list.append(30);
    list.display(); // Output: 10 -> 20 -> 30 -> nullptr

    // Insert after the first node
    Node<int> *head = list.getHead();
    list.insert(head, 15); // Insert 15 after 10
    list.display();        // Output: 10 -> 15 -> 20 -> 30 -> nullptr

    // Insert after the second node
    list.insert(head->next, 18); // Insert 18 after 15
    list.display();              // Output: 10 -> 15 -> 18 -> 20 -> 30 -> nullptr

    return 0;
}















