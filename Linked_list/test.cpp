// class LinkedStack
// {
// private:
//     Node *head;

// public:
//     LinkedStack() : head(nullptr) {}

//     void push(int value)
//     {
//         Node *newNode = new Node(value);
//         newNode->next = head;
//         head = newNode;
//     }

//     int pop()
//     {
//         if (!head){
//             return -1;
//         }
//         int value = head->data;
//         Node *temp = head;
//         head = head->next;
//         delete temp;
//         return value;
//     }


// };

bool deleteNth(Node *&head, int n)
{
    if (!head)
        return false;
    if (n == 0)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    Node *prev = nullptr;
    Node *current = head;
    for (int i = 0; i < n && current; i++)
    {
        prev = current;
        current = current->next;
    }

    if (!current)
        return false;

    prev->next = current->next;
    delete current;
    return true;
}

Node *mergeSortedLists(Node *l1, Node *l2)
{
    if (!l1)
        return l2;
    if (!l2)
        return l1;

    if (l1->data < l2->data)
    {
        l1->next = mergeSortedLists(l1->next, l2);
        return l1;
    }
    else
    {
        l2->next = mergeSortedLists(l1, l2->next);
        return l2;
    }
}