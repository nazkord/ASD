#include <iostream>

struct node {
    node * left;
    node * right;
    node * parent;
    int value;
};

void insertToBST(node * parent, node *& child, int k) {
    /// k - the value to be inserted
    /// parent - is the parent of the current node (firstly null)
    /// child - is root of the tree (in first call of insert function)

    /// if find empty "space" add k there
    if(child == nullptr) {
        child = new node;
        child -> left = child -> right = nullptr;
        child -> value = k;
        child -> parent = parent;
        return;
    }

    /// if k is lesser than current node value then go to left subtree, otherwise to right
    if(k < child -> value) {
        insertToBST(child,child -> left, k);
    } else {
        insertToBST(child,child -> right, k);
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

node * findMin(node * p) {
    while(p -> left != nullptr) {
        p = p->left;
    }
    return p;
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

/// find the next node that will be visited by passing through in-order
node * findConsequentNode(node * p) {

    /// first possibility when node contains right subtree (son)
    if(p -> right != nullptr) {
        return findMin(p -> right);
    }

    /// second possibility when node doesn't have right subtree
    /// go up through the tree and find the first node to which we came from left subtree
    /// if q will equal to null that means p was the largest element in the tree and doesn't have next(consequent) node
    node * q = p -> parent;
    while(q != nullptr && q -> left != p) {
        p = q;
        q = q -> parent;
    }
    return q;
}

/// k'th smallest element to find
/// assumed that tree isn't empty
node * kthSmallest(node * p, int k, int &counter) {
    /// p - firstly root
    /// make this done by using in-order passing through the tree and keep counter
    /// of number nodes that were came across until counter will equal to k
    if(p == nullptr)
        return nullptr;

    node * leftSubtree = kthSmallest(p -> left, k, counter);
    if(leftSubtree != nullptr) {
        return leftSubtree;
    }

    if(++counter == k)
        return p;

    return kthSmallest(p -> right, k, counter);
}

node * findKthSmallestNode(node * p, int k) {
    int counter = 0;
    return kthSmallest(p,k,counter);
}

int main() {
    node * root = nullptr;
    int n;
    std::cin >> n;


    int inputDate[12] = {9,5,15,4,7,10,18,1,6,8,12,19};

    for(int i = 0; i < n; i++) {
        insertToBST(nullptr, root, inputDate[i]);
    }

    node * p = findKthSmallestNode(root, 9);
    if(p -> value == 12)
        std::cout << "TAK TAK TAAK";

    return 0;
}