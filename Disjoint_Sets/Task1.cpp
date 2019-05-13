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

bool roadToPort(int A[n][m]) {
    node * setsArray[n][m];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(A[i][j] > T) {
                setsArray[i][j] = makeSetTree(A[i][j]);
                /// union with left cell if possible
                if(i > 0 && A[i-1][j] > T) {
                    unionTrees(setsArray[i-1][j], setsArray[i][j]);
                }
                if(j > 0 && A[i][j-1] > T) {
                    unionTrees(setsArray[i][j-1], setsArray[i][j]);
                }

            }
        }
    }

    return (findSetTree(setsArray[0][0]) == findSetTree(setsArray[n-1][m-1]));
}

int main() {
    int A[n][m] = {11,12,0,0,0,
                   12,0,13,0,0,
                   15,15,15,0,0,
                   20,0,20,11,0,
                   21,0,0,11,12};

    if(roadToPort(A))
        std::cout << "CAP IS THE BEST";
    else
        std::cout << "CAP SUCKS";

}