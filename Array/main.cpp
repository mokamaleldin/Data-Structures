#include <iostream>
#include <string>
using namespace std;

class Array {
    private:
        int size;   // حجم المصفوفة
        int length; // عدد العناصر المخزنة حاليًا في المصفوفة
        int *items;

    public:
        // **دالة المنشئ** لتحديد حجم المصفوفة عند الإنشاء
        Array(int arrsize) {
            size = arrsize; // تخزين الحجم المحدد
            length = 0; 
            items = new int[arrsize]; // إنشاء مصفوفة جديدة بالحجم المحدد
        }

        //دالة تعبئة المصفوفة 
        void fill() {
            int numberOfItems;
            cout << "How many items you want to fill: ";
            cin >> numberOfItems;

            // التحقق من تجاوز عدد العناصر للحجم المحدد
            if (numberOfItems > size) {
                cout << "You cannot exceed the array size";
                // إنهاء الدالة إذا كان العدد أكبر من الحجم
                return;
            } else {
                // إدخال العناصر وتحديث الطول
                for (int i = 0; i < numberOfItems; i++) {
                    cout << "Enter item num" << i << ": ";
                    cin >> items[i];
                    length++;
                }
            }
        }

        // **دالة عرض محتوى المصفوفة**
        void Display() {
            cout << "Display Array content" << endl;
            for (int i = 0; i < length; i++) {
                cout << items[i] << "\t"; 
            }
            cout << endl << endl;
        }

        // **إرجاع الحجم الأصلي للمصفوفة**
        int getSize() {
            return size;
        }

        // **إرجاع عدد العناصر المخزنة حاليًا**
        int getLength() {
            return length;
        }

        // **البحث عن عنصر في المصفوفة**
        int Search(int key) {
            int index = -1;
            for (int i = 0; i < length; i++) {
                if (items[i] == key) {
                    index = i;
                    break;
                }
            }
            return index;
        }

        // **إضافة عنصر جديد في نهاية المصفوفة**
        void Append(int newItem) {
            if (length < size) {
                items[length] = newItem;
                length++;
            } else {
                cout << "Array is full" << endl;
            }
        }

        // **إدراج عنصر في موقع معين**
        void Insert(int index, int value) {
            if (index >= 0 && index < size) { 
                for (int i = length; i > index; i--) {
                    items[i] = items[i - 1]; // إزاحة العناصر
                }
                items[index] = value;
                length++;
            } else {
                cout << "Array is full" << endl;
            }
        }

        // **حذف عنصر من فهرس معين**
        void Delete(int index) {
            if (index >= 0 && index < length) {
                for (int i = index; i < length - 1; i++) {
                    items[i] = items[i + 1]; // إزاحة العناصر
                }
                length--;
            } else {
                cout << "we don't have this index!!";
            }
        }

        // **تكبير حجم المصفوفة**
        void Enlarge(int newSize) {
            if (newSize <= size) {
                cout << "New size must be larger than current size" << endl;
                return;
            } else {
                int *oldArray = items; // حفظ المصفوفة القديمة
                items = new int[newSize]; // إنشاء مصفوفة جديدة
                for (int i = 0; i < length; i++) {
                    items[i] = oldArray[i]; // نسخ العناصر
                }
                delete[] oldArray; // حذف المصفوفة القديمة
                size = newSize; // تحديث الحجم
            }
        }

        // **دمج مصفوفتين معًا**
        void Merge(Array other) {
            int newSize = size + other.getSize(); // حساب الحجم الجديد
            int *myOldArray = items;
            items = new int[newSize]; // إنشاء مصفوفة جديدة
            // نسخ العناصر من المصفوفة الحالية
            int i;
            for (i = 0; i < length; i++) {
                items[i] = myOldArray[i];
            }
            delete[] myOldArray;
            // نسخ العناصر من المصفوفة الثانية
            int j = i;
            for (int k = 0; k < other.getLength(); k++) {
                items[j++] = other.items[k];
                length++;
            }
        }
};


int main() {
    // تحديد حجم المصفوفة
    int arraySize;
    cout << "Enter the array size: ";
    cin >> arraySize;
    Array myArray(arraySize); // إنشاء مصفوفة

    // تعبئة المصفوفة
    myArray.fill();

    // البحث عن عنصر
    int key = 0;
    cout << "Enter the number you want to search about it: ";
    cin >> key;
    int index = myArray.Search(key);
    if (index == -1) {
        cout << "Item not found" << endl;
    } else {
        cout << "Item found at position " << index << endl;
    }

    // عرض المصفوفة
    myArray.Display();

    // إضافة عنصر جديد
    string add;
    cout << "Do you want to Enter a new index (yes or no): ";
    cin >> add;
    if (add == "yes") {
        int newItem;
        cout << "Enter a new item: ";
        cin >> newItem;
        myArray.Append(newItem);
    }

    // إدراج عنصر في فهرس معين
    int indexadd, value;
    cout << "Insert a new value" << endl;
    cout << "Enter the index: ";
    cin >> indexadd;
    cout << "Enter the value: ";
    cin >> value;
    myArray.Insert(indexadd, value);

    // حذف عنصر
    int indexDelete;
    cout << "Enter the index you want to Delete: ";
    cin >> indexDelete;
    myArray.Delete(indexDelete);

    // عرض الحجم والطول
    cout << "Array size = " << myArray.getSize() << endl;
    cout << "Length = " << myArray.getLength() << endl;

    // تكبير الحجم
    string isSize;
    cout << "Do you want to make a new size for the current array size (yes or no): ";
    cin >> isSize;
    if (isSize == "yes") {
        int size;
        cout << "Enter the new size of the array: ";
        cin >> size;
        myArray.Enlarge(size);
    }

    // دمج مع مصفوفة أخرى
    Array other(3); // مصفوفة جديدة
    other.fill(); // تعبئتها
    myArray.Merge(other); // دمجها مع المصفوفة الحالية

    // عرض الحجم والطول بعد الدمج
    cout << "Array size = " << myArray.getSize() << endl;
    cout << "Length = " << myArray.getLength() << endl;

    // عرض المصفوفة النهائية
    myArray.Display();

    return 0;
}