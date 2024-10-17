/*
Linked list operations

    -Create 
    -Display / Traverse
    -count
    -search
    -Insert 
    -delete
    -reverse
*/

#include <iostream>
#include <string>
using namespace std;

//node class
class Node{
    public:
        int Data;
        Node *next;
};

class LinkedList{
    public:
        Node *Head;

    //create the list
    LinkedList(){
        Head = NULL;
    }

    //is the list is empty or not 
    bool isEmpty(){
        return (Head == NULL);
    }

    //insert first Element
    void insertFirst(int newValue){

        Node *newNode = new Node();
        newNode->Data = newValue;

        if (isEmpty()){
            newNode->next = NULL;
        }
        else{
            newNode->next = Head;
        }
        Head = newNode;
    }

    //Display / Traverse
    void Display(){
        Node *temp = Head;
        while(temp != NULL){
            cout << temp->Data << " -> ";  
             temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    //count
    void count(){
        int counter;
        Node *temp = Head;
        while(temp != NULL){
            counter++;
            temp = temp->next;
        }
        cout << "The list contains " << counter << " items." << endl;
    }

    //search
    bool isFound(int key){
        Node *temp = Head;
        while(temp != NULL){
            if(temp->Data == key){
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
};

int
main()
{
    LinkedList list;

    //if it is empty it will tell me if it not empty it will retun the list contains
    if(list.isEmpty()){
        cout << "The list is Empty" << endl;
    }else{
        list.count();
    }

    //add item to the first
    int numOfItems;
    cout << "Enter how many items you want to add to the Linked list: ";
    cin >> numOfItems;
    for (int i = 0; i < numOfItems;i++){
        int item;
        cout << "Enter Item to insert in the list: ";
        cin >> item;
        list.insertFirst(item);
    }

    // dispaly
    list.Display();

    //search
    int search;
    cout << "Enter item to search for: ";
    cin >> search;
    if(list.isFound(search)){
        cout << "items is found" << endl;
    }else{
        cout << "items is not found"<<endl;
    }
}