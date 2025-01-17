#include <iostream>
using namespace std;

class CircularQueue
{
private:
    int *queue;
    int front, back;
    int size;

public:
    // Constructor
    CircularQueue(int s)
    {
        size = s + 1;
        queue = new int[size];
        front = 0;
        back = 0;
    }

    // Destructor
    ~CircularQueue()
    {
        delete[] queue;
    }

    // Check if the queue is empty
    bool isEmpty()
    {
        return front == back;
    }

    // Check if the queue is full
    bool isFull()
    {
        return (back + 1) % size == front;
    }

    // add operation
    void add(int value)
    {
        if (isFull())
        {
            cout << "Queue is full! Cannot add " << value << endl;
            return;
        }
        queue[back] = value;
        back = (back + 1) % size;
    }

    // remove operation
    int remove()
    {
        if (isEmpty())
        {
            cout << "Queue is empty! Cannot remove." << endl;
            return -1;
        }
        int value = queue[front];
        front = (front + 1) % size;
        return value;
    }

    // Get the front element
    int getFront()
    {
        if (isEmpty())
        {
            cout << "Queue is empty! No front element." << endl;
            return -1;
        }
        return queue[front];
    }

    // Display queue contents
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue contents: ";
        int i = front;
        while (i != back)
        {
            cout << queue[i] << " ";
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main()
{
    CircularQueue cq(5); // Create a circular queue of size 5

    cq.add(10);
    cq.add(20);
    cq.add(30);
    cq.add(40);
    cq.add(50); // Queue is full here
    cq.display();

    cq.remove();
    cq.remove();
    cq.display();

    cq.add(60);
    cq.add(70);
    cq.display();
    cout << "Front element: " << cq.getFront() << endl; // Should print 30

    return 0;
}
