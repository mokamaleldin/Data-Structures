#include <iostream>
#include <string>
using namespace std;

class Array {
    private:
        int size;
        int length;
        int *items;
    public:
        // Constructor to initialize the array with a given size 
        Array(int arrsize){
            size = arrsize;
            length = 0;
            items = new int[arrsize];
        }
        // to fill the array with items (only if the number of items is less than the array size)
        void fill(){
            int numberOfItems;
            cout << "How many items you want to fill: ";
            cin >> numberOfItems;
            if(numberOfItems >= size){
                cout << "You cannot exceed the array size";
                return;
            }
            else{
                for (int i = 0; i < numberOfItems;i++){
                    cout << "Enter item num" << i <<": ";
                    cin >> items[i];
                    length++;
                }
            }
        }
        // Display the array content (print the array content)
        void Display(){
            cout << "Display Array content" << endl;
            for (int i = 0; i < length; i++)
            {
                cout << items[i] << "\t";
            }
            cout << endl << endl;
        }
        // Get the size of the array
        int getSize(){
            return size;
        }
        // Get the length of the array
        int getLength(){
            return length;
        }

        //
        int Search(int key){
            int index = -1;
            for (int i = 0; i < length;i++){
                if(items[i] == key){
                    index = i;
                    break;
                }
            }
            return index;
        }

        //Append (to add the new item to the Array in the end)
        void Append(int newItem){
            if(length <= size){
                items[length] = newItem;
                length++;
            }
            else
            {
                cout << "Array is full"<<endl;
            }
        }
};

int main(){
    //size of the array
    int arraySize;
    cout<< "Enter the array size: ";
    cin >> arraySize;
    Array myArray(arraySize);
    
    //fill the Array
    myArray.fill();
    
    //size of the array
    cout << "Array size = " << myArray.getSize()<<endl;
    cout << "while length = " << myArray.getLength() << endl;
    

    //search
    int key = 0;
    cout << "Enter the number you want to search about it: ";
    cin >> key;
    int index = myArray.Search(key);
    if(index == -1){
        cout << "Item not found" << endl;
    }
    else{
        cout << "item found position " << index << endl;
    }

    // print
    myArray.Display();

    //Append
    string add;
    cout << "Do you want to Enter a new index (yes or no ): ";
    cin >> add;
    if(add == "yes"){
        int newItem;
        cout << "Enter a new items: ";
        cin >> newItem;
        myArray.Append(newItem);
    }

    // print
    myArray.Display();
}
