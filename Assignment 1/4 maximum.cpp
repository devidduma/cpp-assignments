#include <fstream>
#include <iostream>
using namespace std;

int arraySize;
int matrixSize1, matrixSize2;

int maximum(int* array) {
    int max = array[0];

    for(int i = 0; i < arraySize; i++) {
        if(array[i] > max)
            max = array[i];
    }

    return max;
}

int maximum(int** matrix) {
    int max = matrix[0][0];

    for(int i = 0; i < matrixSize1; i++)
        for(int ii = 0; ii < matrixSize2; ii++)
            if(matrix[i][ii] > max)
                max = matrix[i][ii];
    
    return max;
}

int main() {
    ifstream fin;
    fin.open("input.txt");
    fin>>arraySize;
    fin>>matrixSize1>>matrixSize2;

    int* array = new int[arraySize];

    int** matrix = new int*[matrixSize1];
    for(int i = 0; i < matrixSize1; i++)
        matrix[i] = new int[matrixSize2];

    for(int i = 0; i < arraySize; i++) 
        fin>>array[i];

    for(int i = 0; i < matrixSize1; i++)
        for(int ii = 0; ii < matrixSize2; ii++)
            fin>>matrix[i][ii];

    cout<<"The largest element of the Array is: "<< maximum(array);
    cout<<"The largest element of the Matrix is: "<< maximum(matrix);

}
