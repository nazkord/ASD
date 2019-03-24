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

void insertionToResult(node * &head, node * inserted) {

    /// option when we should insert before head or list is empty
    if(head == nullptr || head -> value >= inserted->value) {
        inserted -> next = head;
        head = inserted;
    } else {

        node *tmp = head;
        while (tmp->next != nullptr && tmp->next->value < inserted->value) {
            tmp = tmp->next;
        }
        /// insert the node
        inserted->next = tmp->next;
        tmp->next = inserted;
    }
}

void insertionSortList(node * A[100], int i) {
    node * head = A[i];
    node * result = nullptr;
    node * p = head;
    while(p != nullptr) {
        node * next = p -> next;
        insertionToResult(result,p);
        p = next;
    }
    A[i] = result;
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
        tmp -> next = A[(int)((phead->value)*10)];
        A[(int)((phead->value)*10)] = tmp;
        phead = phead -> next;
    }

    /// sort each bucket using insertionSort

    node * traverseList = head;
    for(int i = 0; i < 100; i++) {
        if(A[i] != nullptr) {//&& A[i] -> next != nullptr)
            insertionSortList(A,i);

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