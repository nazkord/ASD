#include <iostream>

int const N = 5;

struct node {
    int value;
    node * next;
};


node * removeMax(node * &head) {
    if(head->next == nullptr) {
        node * p = head;
        head = nullptr;
        return p;
    }

    node *prev = head;
    node *prevMax = head;
    node *p = head ->next;
    int maxValue = head ->value;
    while(p != nullptr) {
        if(p ->value > maxValue) {
            maxValue = p ->value;
            prevMax = prev;
        }
        p = p ->next;
        prev = prev -> next;
    }

    if(maxValue == head ->value) {
        head = head -> next;
        prevMax -> next = nullptr;
        return prevMax;
    } else {
        node * q = prevMax -> next;
        prevMax -> next = prevMax -> next -> next;
        return  q;
    }

}

//Sorting list by selection decreasing

node * selectionSortList(node * &head) {
    node *head2 = nullptr;
    while(head != nullptr) {
        node * temp = removeMax(head);
        temp -> next = head2;
        head2 = temp;
    }

    return head2;
}

void printOutList(node *head) {
    while(head != nullptr) {
        std::cout << head -> value << " ";
        head = head ->next;
    }
}

int main() {

    //The entrance(provided by user) list
    node *head = nullptr;
    for(int i = 0; i < N; i++) {
        node * temp = new node;
        std::cin >> temp ->value;
        temp -> next = head;
        head = temp;
    }

    std::cout << "Entrance list: " << "\n";
    printOutList(head);

    node *head2 = selectionSortList(head);
    std::cout << "Final list: " << "\n";
    printOutList(head);
    std::cout << "\n";
    printOutList(head2);

    return 0;
}