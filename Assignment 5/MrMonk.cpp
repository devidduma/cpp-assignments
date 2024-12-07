/* The solution was tested and approved by the ACM website. */

#include <iostream>
using namespace std;

int main() {
    int numRows, numCols;
    cin >> numRows >> numCols;

    // create 2d array
    struct ArrayNode {
        int value;
        bool fixed;
        ArrayNode() :
            fixed(false)
        {}
    };

    ArrayNode** array = new ArrayNode*[numRows];
    for(int i = 0; i < numRows; i++) {
        array[i] = new ArrayNode[numCols]();
    }

    // input 2d array
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            cin >> array[i][j].value;
        }
    }

    // constraints
    int numConstraints;
    cin >> numConstraints;

    // input constraints
    for(int i = 0; i < numConstraints; i++) {
        int row, col;
        cin >> col >> row;
        array[row-1][col-1].fixed = true;
    }

    // selection sort for 2d array with fixed elements
    for(int currRowMarker = 0; currRowMarker < numRows; currRowMarker++) {
        for(int currColMarker = 0; currColMarker < numCols; currColMarker++) {
            //if fixed continue
            if(array[currRowMarker][currColMarker].fixed)
                continue;

            //find min
            int minRowAt = currRowMarker;
            int minColAt = currColMarker;
            for(int rowI = currRowMarker; rowI < numRows; rowI++) {
                for (int colI = rowI == currRowMarker ? currColMarker : 0; colI < numCols; ++colI) {
                    //if fixed continue
                    if(array[rowI][colI].fixed)
                        continue;
                    //if new min found
                    if(array[minRowAt][minColAt].value > array[rowI][colI].value) {
                        minRowAt = rowI;
                        minColAt = colI;
                    }
                }
            }

            // swap current element with min element
            swap(array[currRowMarker][currColMarker].value, array[minRowAt][minColAt].value);
        }
    }

    // output
    for(int i = 0; i < numRows; i++) {
        for(int j = 0; j < numCols; j++) {
            cout << array[i][j].value << " ";
        }
        cout << endl;
    }

}

/*
4 3
7 9 17
9 14 12
6 11 7
13 15 5
2
1 3
3 1
 */
