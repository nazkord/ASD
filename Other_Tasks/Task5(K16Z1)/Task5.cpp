#include <iostream>

struct node {
    double value;
    node * next;
};

void printOut(node * A[100]) {
    for(int i = 0; i < 100; i++) {
        node * tmp = A[i];
        while(tmp != nullptr) {
            std::cout << tmp -> value << " ";
            tmp = tmp ->next;
        }
        std::cout << "\n";
    }
}

void insertionSortList(node *A[100], int i) {
    node * head = A[i];


}

void sort(node * head) {

    // declare auxiliary variable for head
    node * phead = head;

    //array of buckets
    node * A[100];
    //make all indicator NULL
    for(int i = 0; i < 100; i++)
        A[i] = nullptr;

    // fill each bucket of particular numbers
    while(phead != nullptr) {
        node * tmp = new node;
        tmp -> value = phead -> value;
        tmp -> next = A[(int)((phead->value)*10)];
        A[(int)((phead->value)*10)] = tmp;
        phead = phead -> next;
    }

    for(int i = 0; i < 100; i++) {
        if(A[i] != nullptr)
            insertionSortList(A,i);
    }


}

int main() {
    node * first = nullptr;
    for(int i = 0; i < 10; i++) {
        node * tmp = new node;
        std::cin >> tmp -> value;
        tmp ->next = first;
        first = tmp;
    }

    sort(first);

    return 0;
}