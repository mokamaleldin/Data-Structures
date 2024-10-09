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
            if(numberOfItems > size){
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

        //search about any number i want in the items
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

        //Add a number to the items but in the index i wnat
        void Insert(int index,int value){
            if(index < size && index>=0){
                for (int i = length; i > index;i--){
                    items[i] = items[i - 1];
                }
                items[index] = value;
                length++;
            }else{
                cout << "Array is full" << endl;
            }
        }

    // Delete item with index
    void Delete(int index){
        if(index >=0 && index < size){
            for (int i = index; i < length;i++){
                items[index] = items[index + 1];
            }
            length--;
        }
    }

    //make the size of the array more big (for example if the size is 5 make it 10)
    void Enlarge(int newSize){
        if(newSize <= size){
            cout << "New size must be lager than current size" << endl;
            return;
        }else{
            size = newSize;
            int *oldArray = items;
            items = new int[newSize];
            for (int i = 0; i < length;i++){
                items[i] = oldArray[i];
            }
        delete[]oldArray;
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

    //Insert
    int indexadd, value;
    cout << "Enter the index: ";
    cin >> indexadd;
    cout << "Enter the value: ";
    cin >> value;
    myArray.Insert(indexadd, value);

    // Delete
    int indexDelete;
    cout << "Enter the index you want to Delete: ";
    cin >> indexDelete;
    myArray.Delete(indexDelete);

    //size of the array
    cout << "Array size = " << myArray.getSize()<<endl;
    cout << "while length = " << myArray.getLength() << endl;

    //Enlarge
    string isSize;
    cout << "Do you want to make a new size for the current array size (yes or no ): ";
    cin >> isSize;
    if(isSize == "yes"){
        int size;
        cout << "Enter the new size of the array: ";
        cin >> size;
        myArray.Enlarge(size);
    }

    //size of the array
    cout << "Array size = " << myArray.getSize()<<endl;
    cout << "while length = " << myArray.getLength() << endl;

    // print
    myArray.Display();
}