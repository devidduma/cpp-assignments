// dduma19
// http://acm.epoka.edu.al:8888/en/problem-pid-c60d?ps=15&smt=7&smpwid=0
// ProblemID-35: 3ed-Accepted -  Cell Removal

#include <iostream>
#include <vector>
using namespace std;

struct Children {
	int children[2];	//we either have 0 or 2 children in this problem
	int currentSize = 0;
};

Children *a;

int SearchTree(int pos, int &delcell, int counter) {	
    // if the cell was not killed
    if(pos!=delcell) {
        // if the cell does not have any children, it is a terminal cell
        if(a[pos].currentSize==0)
            counter++;  // count terminal cell
        // if the cell does have children, it is not terminal
        else
            // ierate through all it's children
            for(int i=0;i<a[pos].currentSize;i++)
                // continue counting for subtree and update current counter
                counter= SearchTree(a[pos].children[i],delcell,counter);
    }

    // return our counter for subtree with head pos
    return counter;
}

int main()
{
    int n,delcell;
    cin>>n>>delcell;

    a= new Children[n];
    int x,head;

    // input stuff
    for(int i=0;i<n;i++) {
        cin>>x;
        if(x==-1) head=i;
        else {
			a[x].children[a[x].currentSize++] = i;
		}
    }
    // start from head cell, specify the killed cell and start counting from 0 how many cells we have in total
    cout<<SearchTree(head,delcell,0);

    return 0;
}
