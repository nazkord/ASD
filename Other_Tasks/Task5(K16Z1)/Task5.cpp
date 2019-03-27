#include <iostream>

struct node {
    double value;
    node * next;
};

void printOutList(node * first) {
    while(first != nullptr) {
        std::cout << first ->value << " ";
        first = first ->next;
    }
    std::cout << "\n";
}

void insertionToResult(node * &headOfResult, node * inserted) {
    /// option when we should insert before head
    if(headOfResult == nullptr || headOfResult -> value >= inserted->value) {
        inserted -> next = headOfResult;
        headOfResult = inserted;
    } else {
        /// pointer for traversing through the list
        node *p = headOfResult;
        while (p->next != nullptr && p->next->value < inserted->value) {
            p = p->next;
        }
        /// insert the node
        inserted->next = p->next;
        p->next = inserted;
    }
}

void bucketSort(node * head) {

    /// declare auxiliary variable for head
    node * phead = head;

    //array of buckets
    node * A[100];
    //make all indicator NULL
    for(int i = 0; i < 100; i++)
        A[i] = nullptr;

    /// fill each bucket of particular numbers
    while(phead != nullptr) {
        node * tmp = new node;
        tmp -> value = phead -> value;
        /// add number to bucket in sorted way
        insertionToResult(A[(int)((phead->value)*10)], tmp);
        phead = phead -> next;
    }


    node * traverseList = head;
    for(int i = 0; i < 100; i++) {
        if(A[i] != nullptr) {

            /// rewriting sorted bucket into main list
            node * tmp = A[i];
            while(tmp != nullptr) {
                traverseList -> value = tmp -> value;
                traverseList = traverseList -> next;
                tmp = tmp -> next;
            }
        }
    }

    /// print out main list
    printOutList(head);

}

int main() {
    node * first = nullptr;
    for(int i = 0; i < 10; i++) {
        node * tmp = new node;
        std::cin >> tmp -> value;
        tmp ->next = first;
        first = tmp;
    }

    bucketSort(first);

    return 0;
}