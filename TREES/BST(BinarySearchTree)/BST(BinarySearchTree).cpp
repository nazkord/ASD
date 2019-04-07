#include <iostream>

struct node {
    node * left;
    node * right;
    node * parent;
    int value;
};




/// #TODO - make parent used!
void insertToBST(node *& p, int k) {
    /// k - the value to be inserted
    /// p - is root of the tree (in first call of insert function)

    /// if find empty "space" add k there
    if(p == nullptr) {
        p = new node;
        p -> left = p -> right = nullptr;
        p -> value = k;
        return;
    }

    /// if k is lesser than current node value then go to left subtree, otherwise to right
    if(k < p -> value) {
        insertToBST(p -> left, k);
    } else {
        insertToBST(p -> right, k);
    }
}


node * findRecursivelyInBST(node * p, int valueToFind) {
    /// p - firstly root

    /// if find correct node or don't find at all
    if(p == nullptr || p -> value == valueToFind) {
        return p;
    }

    /// if k is lesser than current node value then go find to left subtree, otherwise to right
    if(valueToFind < p -> value) {
        return findRecursivelyInBST(p -> left, valueToFind);
    } else {
        return findRecursivelyInBST(p -> right, valueToFind);
    }
}

node * findIterativelyInBST(node * p, int valueToFind) {
    /// p - firstly root
    while(p != nullptr && p -> value != valueToFind) {
        if(valueToFind < p -> value) {
            p = p -> left;
        } else {
            p = p -> right;
        }
    }
    return p;
}

int main() {
    node * root = nullptr;
    int n;
    std::cin >> n;


    int inputDate[12] = {9,5,15,4,7,10,18,1,6,8,12,19};

    for(int i = 0; i < n; i++) {
        insertToBST(root,inputDate[i]);
    }

    node * tmp = findRecursivelyInBST(root, 18);
    if(tmp -> right ->value == 193)
        std::cout << "TAK TAK TAAK";

    return 0;
}