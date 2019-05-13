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

/// to random chose the height of node
int getRandomHeight(int max_h) {
    srand(time(nullptr));
    return rand() % max_h;
}
/// second function for random chose the height of node (in assumptions should be better)
int getHeight(int max_h) {
    srand(time(nullptr));
    double p = 1/2;
    int h = 1;
    while (h < max_h && drand48() < p)
        h++;
    return h;
}

void insert(SkipList skipList, int valueToInsert) {
    SLnode* p = skipList.head;

    /// create new node
    SLnode* newNode = new SLnode;
    newNode -> value = valueToInsert;
    int lvlOfNewNode = getRandomHeight(skipList.maxlvl);
    newNode -> next = new SLnode *[lvlOfNewNode];

    int lvl = skipList.maxlvl - 1;
    /// find the last node which value is less than insertedNode's value (by going down)
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

SLnode * findSLnode(SkipList skipList, int valueToFind) {
    SLnode * p = skipList.head;
    int lvl = skipList.maxlvl - 1;
    for( ; lvl >= 0; lvl--) {
        while (p->next[lvl] != nullptr && p->next[lvl]->value < valueToFind) {
            p = p->next[lvl];
        }
    }
    /// node after p should be the node we are looking for
    p = p -> next[0];

    if(p != nullptr) {
        if(p -> value == valueToFind)
            return p;
        else
            return nullptr;
    } else
        return nullptr;
    /// if doesn't exist return null
}

void deletefromSL(SkipList skipList, int valueToBeDeleted) {
    SLnode * p = skipList.head;
    SLnode * nodeToDelete;
    int lvl = skipList.maxlvl - 1;
    for( ; lvl >= 0; lvl--) {
        while (p->next[lvl] != nullptr && p->next[lvl]->value < valueToBeDeleted) {
            p = p->next[lvl];
        }
        if(p -> next[lvl] != nullptr && p -> next[lvl] -> value == valueToBeDeleted) {
            nodeToDelete = p -> next[lvl];
            p -> next[lvl] = nodeToDelete -> next[lvl];
            nodeToDelete -> next[lvl] = nullptr;
        }
    }

    /// if deleted value doesn't exist
    if (p -> next[0]-> value != valueToBeDeleted) return;
    delete nodeToDelete;
}

int max(int x, int y) {return (x > y ? x : y);}

SkipList mergeTwoSkipLists(SkipList S1, SkipList S2) {
    /// create new skipList (empty)
    int maxLevel = max(S1.maxlvl, S2.maxlvl);
    SkipList S3 = SkipList();
    S3.maxlvl = maxLevel;
    S3.head = new SLnode();
    S3.head -> next = new SLnode *[S3.maxlvl];
    for(int lvl = 0; lvl < maxLevel; lvl ++) {
        S3.head -> next[lvl] = nullptr;
    }

    SLnode* p1;
    SLnode* p2;
    int lvl = S3.maxlvl - 1;
    for( ; lvl >= 0; lvl--) {
        p1 = S1.head;
        p2 = S2.head;
        while(p1 -> next[lvl] != nullptr && p2 -> next[lvl] != nullptr) {
            int value1 = p1->next[lvl]->value;
            int value2 = p2->next[lvl]->value;
            if (value1 > value2) {
                insert(S3, value2);
                p2 = p2->next[lvl];
            } else {
                insert(S3, value1);
                p1 = p1->next[lvl];
            }
        }

        if(p1 -> next[lvl] == nullptr) {
            while(p2 -> next[lvl] != nullptr) {
                insert(S3, p2 -> next[lvl] -> value);
                p2 = p2 -> next[lvl];
            }
        } else if(p2 -> next[lvl] == nullptr) {
            while(p1 -> next[lvl] != nullptr) {
                insert(S3, p1 -> next[lvl] -> value);
                p1 = p1 -> next[lvl];
            }
        }
    }

    return S3;
}

int main() {

    /// first skipList
    int maxLevel = 5;
    SkipList S1 = SkipList();
    S1.maxlvl = maxLevel;
    S1.head = new SLnode();
    S1.head -> next = new SLnode *[S1.maxlvl];
    for(int lvl = 0; lvl < maxLevel; lvl ++) {
        S1.head -> next[lvl] = nullptr;
    }
    insert(S1, 1);
    insert(S1, 5);

    /// second skipList
    SkipList S2 = SkipList();
    S2.maxlvl = maxLevel;
    S2.head = new SLnode();
    S2.head -> next = new SLnode *[S2.maxlvl];
    for(int lvl = 0; lvl < maxLevel; lvl ++) {
        S2.head -> next[lvl] = nullptr;
    }

    insert(S2, 2);
    insert(S2, 3);
    insert(S2, 4);
    insert(S2, 7);

    std::cout << "Test of deleting and finding functions: " << "\n";
    SLnode * node = findSLnode(S2,3);
    if(node == nullptr) {
        std::cout << "cos poszlo nie tak";
    } else {
        std::cout << node -> value << "\n";
    }
    deletefromSL(S2, 3);
    node = findSLnode(S2,3);
    if(node == nullptr) {
        std::cout << "3 doesn't exist";
    } else {
        std::cout << node -> value;
    }

    std::cout << "\n" << "Test of merge function: " << "\n";
    SkipList S3 = mergeTwoSkipLists(S1,S2);
    /// result of merging is skipList contains: 1,2,4,5,7;

    node = findSLnode(S3,8);
    if(node == nullptr) {
        std::cout << "cos poszlo nie tak";
    } else {
        std::cout << node -> value;
    }

}