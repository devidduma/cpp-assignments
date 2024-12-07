/*
 * Problem:
 * Hot Potato Revisited
 * http://acm.epoka.edu.al:8888/en/problem-pid-c65c?ps=29&smt=7&smpwid=0
 *
 * Solution:
 * The solution is quite simple. Just simulate the game and show who won.
 *
 * Validity:
 * The code was tested and approved by the ACM website (with 0 instead of nullptr to be compatible with Mingw 4.7.1)
 */


#include <iostream>
using namespace std;

struct ListNode {
    int index;
    int randomNum;
    ListNode* next;
    ListNode* prev;

    ListNode(int index, int randomNum) :
        index(index),
        randomNum(randomNum),
        next(nullptr),
        prev(nullptr)
    {}
};

// doubly linked and circular List
struct List {
    ListNode* current;
    int size;
    List() :
        current(nullptr),
        size(0)
    {}
};

// adds an element to the end of the list
// make sure the resulting list is circular and doubly linked
void push_back(List* list, ListNode* listNode) {
    if(list->current == nullptr) {
        list->current = listNode;
        list->current->next = list->current;
        list->current->prev = list->current;
    }
    // doubly link left
    ListNode* tail = list->current->prev;
    tail->next = listNode;
    listNode->prev = tail;
    // doubly link right
    list->current->prev = listNode;
    listNode->next = list->current;
    // update list size
    list->size++;
}

// removes the player at list.current
// then restores the integrity of the list
// in the end, it updates the current node based on the direction of the jump action that was executed before
void removeCurrentPlayer(List* list, char direction = 'r') {
    if(list->current == nullptr) {
        return;
    }
    if(list->current->prev == list->current) {
        return;
    }

    ListNode* left = list->current->prev;
    ListNode* right = list->current->next;

    left->next = right;
    right->prev = left;

    // update list size
    list->size--;

    // update current
    if(direction == 'r') {
        list->current = right;
    }
    else {
        list->current = left;
    }
}

// jump to the next player according to the current player's random number
char jumpToNextPlayer(List* list) {
    int numIterations = list->current->randomNum;
    if(numIterations >= 0)
        numIterations = numIterations % list->size;
    else
        numIterations = numIterations % list->size - list->size;

    char direction;
    if(numIterations >= 0)
        direction = 'r';
    else {
        direction = 'l';
        numIterations *= -1;
    }

    for(int i = 0; i < numIterations; i++) {
        if(direction == 'r')
            list->current = list->current->next;
        else
            list->current = list->current->prev;
    }

    return direction;
}

// main
int main() {
    int numPlayers;
    cin >> numPlayers;

    List* list = new List();

    // input information
    for(int i = 1; i <= numPlayers; i++) {
        int randomNum;
        cin >> randomNum;

        push_back(list, new ListNode(i, randomNum));
    }

    // play the game until we have a winner
    while(list->current != list->current->next) {
        char direction = jumpToNextPlayer(list);
        removeCurrentPlayer(list, direction);
    }

    // output the winner
    cout << list->current->index;
}