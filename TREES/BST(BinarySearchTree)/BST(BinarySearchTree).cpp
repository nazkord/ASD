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

void deleteFromBST(node *& root, node * deletedNode) {
    /// first case: when node is leaf just remove his parent connection and himself
    if(deletedNode -> left == nullptr && deletedNode -> right == nullptr) {
        if(deletedNode -> parent -> left == deletedNode) {
            deletedNode -> parent -> left = nullptr;
        } else {
            deletedNode -> parent -> right = nullptr;
        }
        delete deletedNode;
        return;
    }

    /// second case: if node has only one child, delete him and make connection work again
    node * sonNode = nullptr;
    if(deletedNode -> left == nullptr) {
        sonNode = deletedNode -> right;
    } else if(deletedNode -> right == nullptr) {
        sonNode = deletedNode -> left;
    }

    if(sonNode != nullptr) {
        if(deletedNode -> parent -> left == deletedNode) {
            deletedNode -> parent -> left = sonNode;
        } else {
            deletedNode -> parent -> right = sonNode;
        }
        delete deletedNode;
        return;
    }

    ///third case: when node has two sons, then find successor and exchange them deleting successor from his place
    node * toExchange = findConsequentNode(deletedNode);
    deletedNode -> value = toExchange -> value;
    deleteFromBST(root,toExchange);
}


/// k'th smallest element to find
/// assumed that tree isn't empty
node * kthSmallest(node *p, int &k) {
    /// p - firstly root
    /// make this done by using in-order passing through the tree and keep counter
    /// of number nodes that were came across until counter will equal to k
    if (p == nullptr)
        return nullptr;

    node *leftSubtree = kthSmallest(p->left, k);
    if (leftSubtree != nullptr) {
        return leftSubtree;
    }

    if(--k == 0)
        return p;

    return kthSmallest(p->right, k);
}

node * findKthSmallest(node * root, int k) {
    return kthSmallest(root,k);
}

int main() {
    node * root = nullptr;
    int n;
    std::cin >> n;


    int inputDate[12] = {9,5,15,4,7,10,18,1,6,8,12,19};

    for(int i = 0; i < n; i++) {
        insertToBST(nullptr, root, inputDate[i]);
    }


    deleteFromBST(root, findRecursivelyInBST(root, 9));
    if(findRecursivelyInBST(root,10) -> left -> value == 5)
        std::cout << "TAK TAK TAAK";

    return 0;
}