#include <iostream>
#include <ctime>
#include <cstdlib>

int const N = 15;

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
    if(headOfResult -> value >= inserted->value) {
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

node * insertionSortList(node * head) {
    node * result = new node;
    result -> value = head -> value;
    result -> next = nullptr;
    while(head -> next != nullptr) {
        node * tmp = head -> next;
        head -> next = tmp -> next;
        tmp -> next = nullptr;
        insertionToResult(result,tmp);
    }
    delete head;
    return result;
}

int main() {
    srand(time(nullptr));

    node * first = nullptr;
    for(int i = 0; i < N; i++) {
        node *tmp = new node;
        tmp->value = rand() % 10;
        tmp->next = first;
        first = tmp;
    }

    node * head2 = nullptr;

    printOutList(first);

    head2 = insertionSortList(first);

    printOutList(head2);


    return 0;
}