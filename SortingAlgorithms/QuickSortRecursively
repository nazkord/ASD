#include <iostream>
#include <ctime>
#include <cstdlib>

int const N = 7;

void printOutArray(int T[], int size) {
    for(int i = 0; i < size; i++) {
        std::cout << T[i] << " ";
    }
    std::cout << "\n";
}

void swap(int Q[N], int a, int b) {
    int temp = Q[a];
    Q[a] = Q[b];
    Q[b] = temp;
}

int partition(int T[N], int low, int high) {
    int pivot = T[high];
    int i = low;
    for(int q = low; q < high; q++) {
        if(T[q] <= pivot) {
            if(q != i)
                swap(T,i,q);
            i++;
        }
    }
    swap(T,i,high);
    return i;
}

void sort(int T[N], int i, int j) {
    //printOutArray(T,N);

    if(i < j) {
        int pivot = partition(T, i, j);
        sort(T, i, pivot - 1);
        sort(T, pivot + 1, j);
    }
}

int main() {
    srand(time(nullptr));

    int A[N];
    for(int i = 0; i < N; i++) {
        A[i] = rand()%20;
    }

    printOutArray(A,N);

    sort(A,0,N-1);

    printOutArray(A,N);

    return 0;
}