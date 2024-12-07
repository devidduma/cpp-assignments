/*
 * Problem:
 * Parliament
 * http://acm.epoka.edu.al:8888/en/problem-pid-c602?ps=15&smt=7&smpwid=0
 *
 * Solution:
 *
 * insults can be represented in a tree-like schema:
 * assume we have a root deputy, this deputy is insulted by x,y,z...
 * x,y,z are themselves insulted by other deputies, and so on recursively
 * we can see that if we split the tree's planes (consisting of deputies in the same depth in the tree)
 * and assign deputies at depth i and i+2 in group 1 and deputies in depth i+1 and i+3 in group 2 and so on recursively
 * we do not have any conflicts inside a group. so in this case we need 2 groups.
 * the only other special case is:
 * we might have a leaf being insulted by the root, resulting in a loop of insults
 * note that any node in a loop of insults is a valid root node for a tree of insults without losing information, the schema of the tree simply rearranges for different root nodes
 * we use the function findRoot() to define for us an arbitrary root
 * if the loop of insults contains an odd number of deputies, we can not split them in at most 2 groups, we need a third group
 * we assign the third group to the root deputy and we won't have any conflicts anymore
 * and we are done
 * note that we can have multiple trees of insults, if we arbitrarily merge their deputies at group i, we don't have conflicts
 * note that we could have deputies that are not elements of any tree of insults. so we assign them arbitrarily to group 1
 *
 * Validity:
 * The code was tested and approved by the ACM website.
*/


#include <iostream>
#include <vector>
using namespace std;


struct ProblemInformation {
	int* groupAssigned;
	// saves which deputy was insulted deputyInsultedFrom the deputy at index i
	int* deputyInsultedFrom;
	//	saves the insultors of deputy at index i in a vector
	vector<int>* insultorsOf;
	int* checkedForRoot;
	int* numGroups;
	
	// constructor
	ProblemInformation(const int* numDeputies, const int* numInsults) :
		groupAssigned(new int[*numDeputies+1] {}),
		deputyInsultedFrom(new int[*numDeputies+1] {}),
		insultorsOf(new vector<int>[*numDeputies+1] {}),
		checkedForRoot(new int[*numDeputies+1] {}),
		numGroups(new int)
	{
		*this->numGroups = 1;
		if(*numInsults > 0)
			*this->numGroups = 2;
	}
};

void enterInsults(const int* numInsults, vector<int>* insultorsOf, int* deputyInsultedFrom);
void sortTree(int deputyIndex, ProblemInformation* info);
int* findRoot(int deputyIndex, const int* deputyInsultedFrom, int* checkedForRoot);
void sortTreeRecursive(int parentDeputy, int groupNum, const int* rootIndex, const vector<int>* insultorsOf, int* groupAssigned);


int main()
{
    int* numDeputies = new int;
    int* numInsults = new int;
    cin >> *numDeputies >> *numInsults;
    
    ProblemInformation* info = new ProblemInformation(numDeputies, numInsults);
	
	//enter the insults
	enterInsults(numInsults, info->insultorsOf, info->deputyInsultedFrom);
    
    // loop through the deputies
    for(int deputyIndex = 1; deputyIndex <= *numDeputies; deputyIndex++) {

        // if groupAssigned is == 0, deputy has not been assigned a group
        // this means, there is a tree of insults that has not been split into groups
        if (info->groupAssigned[deputyIndex] == 0) {

            // let's assign groups to all the deputies that are elements of this tree of insult, not only the current deputy
            // this makes the algorithm efficient
            sortTree(deputyIndex, info);
        }
    }
	
	// output results
    cout << *info->numGroups;
    for(int deputyIndex = 1; deputyIndex <= *numDeputies; deputyIndex++)
		cout << endl << info->groupAssigned[deputyIndex];
    cout << endl;

    return 0;
}

void enterInsults(const int* numInsults, vector<int>* insultorsOf, int* deputyInsultedFrom) {
	// deputy X insulted deputy Y
	// deputy X insulted only one person
    int x, y;
    for(int i=0; i < *numInsults; i++) {
		  // enter insults
          cin >> x >> y;
          deputyInsultedFrom[x] = y;
          insultorsOf[y].push_back(x);
    }
}

void sortTree(int deputyIndex, ProblemInformation* info) {
		// find the root of the tree
		// it returns 'deputyIndex' itself if no other root found
		int* rootIndex = findRoot(deputyIndex, info->deputyInsultedFrom, info->checkedForRoot);
		
		// assign group to root
		info->groupAssigned[*rootIndex] = 1;
		// assign group to other elements
		sortTreeRecursive(*rootIndex, 2, rootIndex, info->insultorsOf, info->groupAssigned);
		
		// if root has insulted someone
		//even though it works without this if statement, it is much more intuitive this way
		if(info->deputyInsultedFrom[*rootIndex] != 0) {
			// if deputy insulted from root and root are in the same group, we have a loop of insults
			// solve it by arbitrarily assigning root to group 3
			if(info->groupAssigned[ info->deputyInsultedFrom[*rootIndex] ] == info->groupAssigned[*rootIndex]) {
				info->groupAssigned[*rootIndex] = 3;
				*info->numGroups = 3;
			}
		}
}


int* findRoot(int deputyIndex, const int* deputyInsultedFrom, int* checkedForRoot) {
	// returns 'deputyIndex' itself if no other root found
	// deputyIndex is intended as a consumable variable, don't use pointer
	
	// let's go upwards in the tree of insults
	// checkedForRoot makes sure we don't loop infinitely in a loop of insults
    while(deputyInsultedFrom[deputyIndex] != 0 && !checkedForRoot[deputyIndex]) {
		// assign 1 to every node we visited
        checkedForRoot[deputyIndex] = 1;
        // go upwards
        deputyIndex = deputyInsultedFrom[deputyIndex];
    }
	
	int* resultIndex = new int;
	*resultIndex = deputyIndex;
    return resultIndex;
}

void sortTreeRecursive(int parentDeputy, int groupNum, const int* rootIndex, const vector<int>* insultorsOf, int* groupAssigned) {
	// let's go downwards in the tree of insults
	// looping through all insultors of parentDeputy
    for(int i = 0; i < insultorsOf[parentDeputy].size(); i++) {
		int insultorIndex = insultorsOf[parentDeputy][i];
		
        if(insultorIndex != *rootIndex) {
            groupAssigned[ insultorIndex ] = groupNum;
			
			int nextGroupNum = groupNum%2 + 1;
            sortTreeRecursive(insultorsOf[parentDeputy][i], nextGroupNum, rootIndex, insultorsOf, groupAssigned);
        }
    }
}

