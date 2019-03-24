#include <iostream>
#include <ctime>
#include <cstdlib>

int const N = 15;

void printOutArray(int A[N]) {
    for(int i = 0; i < N; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << "\n";
}

void swap(int A[N], int x, int y) {
    int tmp = A[x];
    A[x] = A[y];
    A[y] = tmp;
}

void insertionSort(int A[N]) {
    int limit = 1;
    while(limit < N) {
        int counter = limit;
        while(counter > 0 && A[counter - 1] > A[counter]) {
            swap(A, counter - 1, counter);
            counter--;
        }
        limit++;
    }
}

int main() {
    srand(time(nullptr));

    int array[N];
    for (int i = 0; i < N; i++) {
        array[i] = rand() % 20;
    }

    printOutArray(array);

    insertionSort(array);

    printOutArray(array);


    return 0;
}