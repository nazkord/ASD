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
    //printOutList(head);
}

void insertionSortList(node * head, node * &result) {
    node * p = head;
    while(p != nullptr) {
        node * next = p -> next;
        insertionToResult(result,p);
        p = next;
    }
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

    insertionSortList(first,head2);

    printOutList(head2);


    return 0;
}