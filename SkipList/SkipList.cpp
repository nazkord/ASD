#include <iostream>
#include <cstdlib>
#include <ctime>

struct SLnode {
    int value;
    SLnode ** next;
};

struct SkipList {
    SLnode * head;
    SLnode * tail;
    int maxlvl;
};

/// to random chose the high of node
int getRandomHeight(int max_h) {
    srand(time(nullptr));
    return rand()%max_h;
}

void insert(int valueToInsert, SkipList skipList) {
    SLnode* p = skipList.head;

    /// create new node
    SLnode* newNode = new SLnode;
    newNode -> value = valueToInsert;
    int lvlOfNewNode = getRandomHeight(skipList.maxlvl);
    newNode -> next = new SLnode *[lvlOfNewNode];

    int lvl = skipList.maxlvl - 1;
    /// find the last node which value is less than insertedNode's value (going down)
    for( ; lvl >= 0; lvl--) {
        while (p->next[lvl] != nullptr && p->next[lvl]->value < valueToInsert) {
            p = p -> next[lvl];
        }
        /// insert node by pinning particular p's level with newNode's level
        if(lvl < lvlOfNewNode) {
            newNode -> next[lvl] = p -> next[lvl];
            p -> next[lvl] = newNode;
        }
    }
}

int main() {

    int maxLevel = 5;
    SkipList S1 = SkipList();
    S1.maxlvl = maxLevel;
    S1.head = new SLnode();
    S1.head -> next = new SLnode *[S1.maxlvl];
    for(int lvl = 0; lvl < maxLevel; lvl ++) {
        S1.head -> next[lvl] = nullptr;
    }

}