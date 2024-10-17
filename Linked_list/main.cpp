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
        Node *Head; // مؤشر إلى أول عقدة في القائمة

    //create the list
    LinkedList(){
        Head = NULL;
    }

    // التحقق مما إذا كانت القائمة فارغة
    bool isEmpty(){
        return (Head == NULL);
    }

    // إدراج عنصر في بداية القائمة
    void insertFirst(int newValue){

        Node *newNode = new Node(); // إنشاء عقدة جديدة
        newNode->Data = newValue; // تخزين القيمة الجديدة في العقدة

        if (isEmpty()){
            newNode->next = NULL;
        }
        else{
            newNode->next = Head;
        }
        Head = newNode; // تحديث الرأس ليشير إلى العقدة الجديدة
    }

    //Display / Traverse
    void Display(){
        Node *temp = Head; // بدء الاجتياز من الرأس
        while(temp != NULL){
            cout << temp->Data << " -> ";  
             temp = temp->next; // الانتقال إلى العقدة التالية
        }
        cout << "NULL" << endl;
    }

    // حساب عدد العناصر في القائمة
    void count(){
        int counter;
        Node *temp = Head;
        while(temp != NULL){
            counter++;
            temp = temp->next;
        }
        cout << "The list contains " << counter << " items." << endl;
    }

    // البحث عن عنصر في القائمة
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
    LinkedList list;  // إنشاء قائمة جديدة

    // التحقق مما إذا كانت القائمة فارغة
    if(list.isEmpty()){
        cout << "The list is Empty" << endl;
    }else{
        list.count();
    }

    // إدخال عدد العناصر التي يرغب المستخدم في إضافتها
    int numOfItems;
    cout << "Enter how many items you want to add to the Linked list: ";
    cin >> numOfItems;
    // إدخال العناصر في القائمة
    for (int i = 0; i < numOfItems;i++){
        int item;
        cout << "Enter Item to insert in the list: ";
        cin >> item;
        list.insertFirst(item);
    }

    // dispaly
    list.Display();

    // البحث عن عنصر معين في القائمة
    int search;
    cout << "Enter item to search for: ";
    cin >> search;
    if(list.isFound(search)){
        cout << "items is found" << endl;
    }else{
        cout << "items is not found"<<endl;
    }
}