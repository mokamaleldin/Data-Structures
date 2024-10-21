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

    //اضافه عنصر قبل عنصر 
    /*
        EX:
        if i have 5,3,0,7,9 
        and i wnat to add 4 after the 0
    */
    void inserBefore(int item,int newValue){
        if(isEmpty()){
            insertFirst(newValue);
        }
        else{
            if(isFound(item)){
            Node *newNode = new Node(); 
            newNode->Data = newValue; 
            Node *temp = Head;
            while (temp != NULL && temp->next->Data != item){
                temp = temp->next;
            }
            newNode->next = temp->next; 
            temp->next = newNode; 
            }else{
                cout << "Sorry , item not found";
            }
        }
    }

    //LIST اضافه عنصر الي نهايه ال 
    void Append(int newValue){
        if(isEmpty()){
            insertFirst(newValue);
        }
        else{
            Node *temp = Head;
            while (temp->next != NULL){
                temp = temp->next;
            }
            Node *newNode = new Node(); 
            newNode->Data = newValue;
            temp->next = newNode;
            newNode->next = NULL;
        }
    }
};

int main(){
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

    // البحث عن عنصر معين في القائمة
    int search;
    cout << "Enter item to search for: ";
    cin >> search;
    if(list.isFound(search)){
        cout << "items is found" << endl;
    }else{
        cout << "items is not found"<<endl;
    }

    //اضافه عنصر قبل عنصر
    cout << "Here you will insert item before item" << endl;
    int newValue, myItem;
    cout << "Entert item: ";
    cin >> myItem;
    cout << "Entera new value to insert: ";
    cin >> newValue;
    list.inserBefore(myItem,newValue);

    //LIST اضافه عنصر الي نهايه ال
    int newItem;
    cout << "Enter a new item: ";
    cin >> newItem;
    list.Append(newItem);

    // dispaly
    list.Display();
}