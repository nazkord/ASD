#include <iostream>
#include <cstdlib>
#include <ctime>

//size of main array
int const N = 9;

//range of data, from 0 to M
int const M = 20;

void printOutArray(int T[], int size) {
    for(int i = 0; i < size; i++) {
        std::cout << T[i] << " ";
    }
    std::cout << "\n";
}

void countingSort(int A[N], int B[N]) {
    //size of B array = range of data
    int C[M];

    //fill array C with 0
    for(int i = 0; i < M; i++)
        C[i] = 0;

    //main loop, which counts appears of numbers from array A
    for(int i = 1; i < N; i++) {
        C[A[i]]++;
    }

    for(int i = 1; i < M; i++) {
        C[i] = C[i] + C[i-1];
    }

    for(int i = N - 1; i > 0; i--) {
        B[C[A[i]]] = A[i];
        C[A[i]]--;
    }
}

int main() {
    srand(time(nullptr));

    int A[N];
    int B[N];
    for(int i = 1; i < N; i++) {
        A[i] = rand()%M;
    }

    for(int i = 1; i < N; i++) {
        B[i] = 0;
    }

    printOutArray(A,N);

    countingSort(A,B);

    printOutArray(B,N);

    return 0;
}