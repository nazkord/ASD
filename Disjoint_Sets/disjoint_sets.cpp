#include <iostream>
const int T = 10;
const int n = 5;
const int m = 5;

struct node {
    node * parent;
    int value;
    int rank; /// for making union by rank (for better complexity)
};

node * makeSetTree(int key) {
    node * newNode = new node;
    newNode -> parent = newNode;
    newNode -> value = key;
    newNode -> rank = 0;
    return newNode;
}

node * findSetTree(node * p) {  /// using path compression for better complexity
    if(p -> parent != p)
        p -> parent = findSetTree(p -> parent); /// find father of the tree and pin to p's father;
    return p -> parent;
}

void unionTrees(node * x, node * y) {
    node * reprOfX = findSetTree(x); /// repr - representant
    node * reprOfY = findSetTree(y);
    /// union using rank
    if(reprOfX -> rank > reprOfY -> rank) {
        reprOfY -> parent = reprOfX;
    } else {
        reprOfX -> parent = reprOfY;
        if(reprOfX -> rank == reprOfY -> rank)
            reprOfX -> rank += 1;
    }
}

int main() {
    return 0;
}
