#include <iostream>
using namespace std;

struct ArrayWrapper {
    int* array;
    int size;
    int capacity;
    ArrayWrapper(int* array, int size) :
        array(array),
        size(size),
        capacity(size)
    {}
};

void setEntry(ArrayWrapper& arrayWrapper, int index, int value) {
    if(index < 0 || index >= arrayWrapper.size)
        return;

    arrayWrapper.array[index] = value;
}

void push_back(ArrayWrapper& arrayWrapper, int element) {
    // manipulate capacity if necessary
    if(arrayWrapper.capacity == arrayWrapper.size) {
        // create new array with twice the capacity
        int* newArray = new int[arrayWrapper.capacity*2];
        for(int i = 0; i < arrayWrapper.size; i++) {
            newArray[i] = arrayWrapper.array[i];
        }
        delete[] arrayWrapper.array;
        arrayWrapper.array = newArray;
        arrayWrapper.capacity *= 2;
    }
    // add element to the end and increment size
    arrayWrapper.array[arrayWrapper.size++] = element;
}

void remove(ArrayWrapper& arrayWrapper, int index) {
    if(index < 0 || index >= arrayWrapper.size)
        return;

    int newSize = arrayWrapper.size - 1;
    int newCapacity = arrayWrapper.capacity;
    if(newSize == newCapacity/2)
        newCapacity = newCapacity/2;

    int* newArray = new int[newCapacity];
    // copy elements to their respective places
    for(int i = 0; i < index; i++) {
        newArray[i] = arrayWrapper.array[i];
    }
    // skip element at index
    for(int i = index + 1; i < arrayWrapper.size; i++) {
        newArray[i - 1] = arrayWrapper.array[i];
    }

    arrayWrapper.array = newArray;
    arrayWrapper.capacity = newCapacity;
    arrayWrapper.size = newSize;
}

int selectionSorting(ArrayWrapper& arrayWrapper) {
    // set a marker separating sorted from unsorted array
    for(int marker = 0; marker < arrayWrapper.size; marker++) {
        // find min from unsorted part of array
        int minAt = marker;
        for(int current = marker; current < arrayWrapper.size; current++) {
            if(arrayWrapper.array[minAt] > arrayWrapper.array[current])
                swap(arrayWrapper.array[minAt], arrayWrapper.array[current]);
        }
    }
}

void doubleArray(ArrayWrapper& arrayWrapper) {
    int size = arrayWrapper.size;
    for(int i = 0; i < size; i++) {
        push_back(arrayWrapper, arrayWrapper.array[i]);
    }
}

void insert(ArrayWrapper& arrayWrapper, int index, int value) {
    // manipulate capacity if necessary
    int newCapacity;
    if(arrayWrapper.capacity == arrayWrapper.size) {
        newCapacity = arrayWrapper.capacity * 2;
    } else {
        newCapacity = arrayWrapper.capacity;
    }
    // create new array
    int* newArray = new int[newCapacity];

    // copy elements to their respective places
    for(int i = 0; i < index; i++) {
        newArray[i] = arrayWrapper.array[i];
    }
    for(int i = index; i <= arrayWrapper.size; i++) {
        // shift right
        newArray[i + 1] = arrayWrapper.array[i];
    }
    // insert element
    newArray[index] = value;

    delete[] arrayWrapper.array;
    arrayWrapper.array = newArray;
    arrayWrapper.capacity = newCapacity;
    arrayWrapper.size++;
}

void printArray(ArrayWrapper arrayWrapper) {
    cout << "[ ";
    for(int i = 0; i < arrayWrapper.size; i++) {
        cout << arrayWrapper.array[i] << " ";
    }
    cout << "]" << endl;
}

int main() {
    ArrayWrapper arrayWrapper(new int[3]{8,9,10}, 3);

    setEntry(arrayWrapper, 1, 17);
    push_back(arrayWrapper, 4);
    push_back(arrayWrapper, 5);
    push_back(arrayWrapper, 6);
    remove(arrayWrapper, 0);
    selectionSorting(arrayWrapper);
    doubleArray(arrayWrapper);
    insert(arrayWrapper, 3, 25);

    printArray(arrayWrapper);

}