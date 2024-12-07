#include <iostream>
using namespace std;

int insertionSorting(int* array, int arraySize) {
    int counter = 0;
    // set a marker separating sorted from unsorted array
    for(int marker = 0; marker < arraySize; marker++) {
        for(int current = marker; current >= 1; current--) {
            counter++;
            // if smaller, swap
            if(array[current] < array[current - 1])
                swap(array[current], array[current - 1]);
            // else break
            else
                break;
        }
    }

    return counter;
}

int selectionSorting(int* array, int arraySize) {
    int counter = 0;
    // set a marker separating sorted from unsorted array
    for(int marker = 0; marker < arraySize; marker++) {
        // find min from unsorted part of array
        int minAt = marker;
        for(int current = marker; current < arraySize; current++) {
            counter++;
            if(array[minAt] > array[current])
                minAt = current;
        }
        //swap element at marker with minimum
        swap(array[marker], array[minAt]);
    }

    return counter;
}

struct SearchReturn {
    int counter;
    int first;
    int last;
    SearchReturn() :
        counter(0),
        first(-1),
        last(-1)
    {}
};

SearchReturn sequentialSearching(int* array, int arraySize, int searchFor) {
    SearchReturn searchReturn;

    // find first match
    int first = 0;
    while(first < arraySize) {
        searchReturn.counter++;
        if(array[first] == searchFor)
            break;
        first++;
    }

    //find last match
    int last = first;
    while(last < arraySize - 1 && array[last + 1] == searchFor) {
        searchReturn.counter++;
        last++;
    }

    searchReturn.first = first;
    searchReturn.last = last;
    return searchReturn;
}

SearchReturn binarySearching(int* array, int arraySize, int searchFor, int start, int end) {
    SearchReturn searchReturn;

    if(end >= start) {
        int mid = (start + end) / 2;

        // check middle element
        searchReturn.counter++;
        if(array[mid] == searchFor) {
            // iterate left
            int iterate = mid;
            while(iterate >= 0 && array[iterate - 1] == searchFor) {
                searchReturn.counter++;
                iterate--;
            }
            searchReturn.first = iterate;

            //iterate right
            iterate = mid;
            while(iterate < arraySize && array[iterate + 1] == searchFor) {
                searchReturn.counter++;
                iterate++;
            }
            searchReturn.last = iterate;
            return searchReturn;
        }

        // check left subarray
        else if(array[mid] > searchFor) {
            return binarySearching(array, arraySize, searchFor, start, mid - 1);
        }

        // check right subarray
        else {
            return binarySearching(array, arraySize, searchFor, mid + 1, end);
        }
    }
    // element not found
    else {
        searchReturn.first = -1;
        searchReturn.last = -1;
        return searchReturn;
    }
}


struct ArrayWrapper {
    int* array;
    int size;
    ArrayWrapper(int* array, int size) :
            array(array),
            size(size)
    {}
};

ArrayWrapper copyArray(const int* array, int arraySize) {
    ArrayWrapper arrayWrapper(new int[arraySize], arraySize);
    for(int i = 0; i < arrayWrapper.size; i++) {
        arrayWrapper.array[i] = array[i];
    }
    return arrayWrapper;
}

void printArray(int* array, int arraySize) {
    cout << "Array: [ ";
    for(int i = 0; i < arraySize; i++) {
        cout << array[i] << " ";
    }
    cout << "]" << endl;
}

void deleteDuplicates(ArrayWrapper& arrayWrapper, int start, int last) {
    int newSize = arrayWrapper.size - (last - start);
    int* newArray = new int[newSize];
    for(int i = 0, index = 0; i < arrayWrapper.size; i++) {
        if(i >= start + 1 && i <= last)
            continue;
        newArray[index++] = arrayWrapper.array[i];
    }
    delete[] arrayWrapper.array;
    arrayWrapper.array = newArray;
    arrayWrapper.size = newSize;
}

int main() {
    /*
     * 1) Insertion sorting iterates through less elements than selection sorting and is therefore faster because we work with the sorted array,
     * that allows us to break the iterating loop when the current element finds it's place.
     * In selection sorting iterating loops do not break since we work with an unsorted array and can not know where the minimal value is.
     * 2) Binary searching is faster than sequential searching because we iterate through (log2)N elements in worst case,
     * while on sequential searching we iterate through N/2 elements on average, where N is the size of the array.
     */
    // create array
    int arraySize = 12;
    int* array = new int[arraySize]
            {7, 9, 17, 9, 14, 12, 6, 11, 7, 13, 15, 5};

    printArray(array, arraySize);

    int counter = 0;
    ArrayWrapper arrayWrapper = copyArray(array, arraySize);
    counter += insertionSorting(arrayWrapper.array, arrayWrapper.size);
    //printArray(arrayWrapper.array, arrayWrapper.size);
    for(int i = 0; i < arrayWrapper.size; i++) {
        SearchReturn searchReturn = sequentialSearching(arrayWrapper.array, arrayWrapper.size, arrayWrapper.array[i]);
        counter += searchReturn.counter;
        deleteDuplicates(arrayWrapper, searchReturn.first, searchReturn.last);
        // after deleting duplicates, current i points to only one element without duplicates
        // so next i moves on to the next element
    }
    cout << "insertion sorting & sequential searching: " << counter << endl;

    counter = 0;
    arrayWrapper = copyArray(array, arraySize);
    counter += selectionSorting(arrayWrapper.array, arrayWrapper.size);
    //printArray(arrayWrapper.array, arrayWrapper.size);
    for(int i = 0; i < arrayWrapper.size; i++) {
        SearchReturn searchReturn = sequentialSearching(arrayWrapper.array, arrayWrapper.size, arrayWrapper.array[i]);
        counter += searchReturn.counter;
        deleteDuplicates(arrayWrapper, searchReturn.first, searchReturn.last);
        // after deleting duplicates, current i points to only one element without duplicates
        // so next i moves on to the next element
    }
    cout << "selection sorting & sequential searching: " << counter << endl;

    counter = 0;
    arrayWrapper = copyArray(array, arraySize);
    counter += insertionSorting(arrayWrapper.array, arrayWrapper.size);
    //printArray(arrayWrapper.array, arrayWrapper.size);
    for(int i = 0; i < arrayWrapper.size; i++) {
        SearchReturn searchReturn = binarySearching(arrayWrapper.array, arrayWrapper.size, arrayWrapper.array[i], 0, arrayWrapper.size);
        counter += searchReturn.counter;
        deleteDuplicates(arrayWrapper, searchReturn.first, searchReturn.last);
        // after deleting duplicates, current i points to only one element without duplicates
        // so next i moves on to the next element
    }
    cout << "insertion sorting & binary searching: " << counter << endl;

    counter = 0;
    arrayWrapper = copyArray(array, arraySize);
    counter += selectionSorting(arrayWrapper.array, arrayWrapper.size);
    //printArray(arrayWrapper.array, arrayWrapper.size);
    for(int i = 0; i < arrayWrapper.size; i++) {
        SearchReturn searchReturn = binarySearching(arrayWrapper.array, arrayWrapper.size, arrayWrapper.array[i], 0, arrayWrapper.size);
        counter += searchReturn.counter;
        deleteDuplicates(arrayWrapper, searchReturn.first, searchReturn.last);
        // after deleting duplicates, current i points to only one element without duplicates
        // so next i moves on to the next element
    }
    cout << "selection sorting & binary searching: " << counter << endl;

}