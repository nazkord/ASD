#include <iostream>
#include <cmath>

const int N = 10;

struct node {
    int group;
    node * next;
};

void printOutList(node * first) {
    while (first != nullptr) {
        std::cout << first->group << " ";
        first = first->next;
    }
    std::cout << "\n";
}

void printOutArray(int A[N/2]) {
    for(int i = 0; i < N/2; i++)
        std::cout << A[i] << " ";
    std::cout << "\n";
}

int distanceToIdeal(node * head) {
    //green team
    int * A = new int[N/2];
    int counterA = 0;
    //blue team
    int * B = new int[N/2];
    int counterB = 0;

    //first step
    for(int i = 0; i < N; i++) {
        if(head->group == 0) {
            A[counterA++] = i+1;
        }
        else
            B[counterB++] = i + 1;
        head = head->next;
    }

    printOutArray(A);
    printOutArray(B);

    /// second step
    counterA = 0;
    counterB = 0;
    int mainCounter = 0;

    while(counterA < N/2) {
        bool flag = false;
        if(A[counterA] > N/2) {
            while(counterB < N/2 && !flag) {
                if(B[counterB] <= N/2) {
                    mainCounter = mainCounter + abs(B[counterB] - A[counterA]) * 2;
                    flag = true;
                }
                counterB++;
            }
        }
        counterA++;
    }

    return mainCounter;

    //return  0;
}


int main() {
    std::cout << "Hello, World!" << std::endl;

    node * first = nullptr;
    for(int i = 0; i < N; i++) {
        node * tmp = new node;
        std::cin>>tmp->group;
        tmp->next = first;
        first = tmp;
    }

    printOutList(first);

    std::cout << distanceToIdeal(first);


    return 0;
}