#include <iostream>
#include <string>

struct node {
    int key;
    node * left = nullptr;
    node * right = nullptr;
    bool is_end = false;
};

struct Set {
    node * root = nullptr;
};

Set createSet(std::string A[], int n) {
    Set set = Set();
    set.root = new node;
    set.root -> key = -1; /// to be able to recognize the root;
    for(int i = 0; i < n; i++) {
        std::string number = A[i];
        node * q = set.root;
        for(int j = 0; j < number.size(); j++) {
            if(number[j] == '0') {
                if(q -> left != nullptr)
                    q = q -> left;
                else {
                    /// if left son (0) doesnt exist, create new node with key value 0
                    node *tmp = new node;
                    tmp->key = 0;
                    q->left = tmp;
                    q = tmp;
                }
            } else {
                if(q -> right != nullptr)
                    q = q -> right;
                else {
                    /// if right son (0) doesnt exist, create new node with key value 1
                    node *tmp = new node;
                    tmp->key = 1;
                    q->right = tmp;
                    q = tmp;
                }
            }
            /// check whether A[j] is the end of number
            if(j == number.size() - 1)
                q -> is_end = true;
        }
    }
    return set;
}

bool contains(Set a, std::string s) {
    node * q = a.root;
    int i = 0;
    while(q != nullptr && i < s.size()) {
        if(s[i] == '0')
            q = q -> left;
        else
            q = q -> right;
        i++;
    }

    if(q == nullptr)
        return false;
    else
        return (q -> is_end);
}

int main() {
    int n = 5;

    std::string A[5];
    A[0] = "0";
    A[1] = "00000110";
    A[2] = "10101";
    A[3] = "111001";
    A[4] = "1111";

    Set set = createSet(A, n);

    if(contains(set, "0000110"))
        std::cout << "TAK tAK TAKK";
    else
        std::cout << "Nope";

    return 0;
}