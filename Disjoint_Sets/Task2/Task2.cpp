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

int countRoutes(bool A[n][m], int x, int y) {
    node * setsArray[n][m];
    /// make as many setTrees(disjoint) as possible
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(A[i][j]) {
                setsArray[i][j] = makeSetTree(A[i][j]);
                /// union with left and up cell if possible
                if(i > 0 && A[i-1][j]) {
                    unionTrees(setsArray[i-1][j], setsArray[i][j]);
                }
                if(j > 0 && A[i][j-1]) {
                    unionTrees(setsArray[i][j-1], setsArray[i][j]);
                }

            }
        }
    }

    /// check how much element are being contain in setTree with our point x,y

    int counter = 0;
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(A[i][j] && findSetTree(setsArray[i][j]) == findSetTree(setsArray[x][y]))
                counter++;
        }
    }

    return counter;
}

int main() {
    bool A[n][m] = {0,0,0,0,0,
                   0,0,1,0,0,
                   1,1,1,0,0,
                   1,0,0,1,0,
                   0,0,0,0,0};

    std::cout << countRoutes(A,2,0);

}