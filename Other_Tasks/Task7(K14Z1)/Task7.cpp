#include <iostream>

int const N = 10;
int const M = 30;
int const range = 65;
int const theLongest = 4;

void printOutArray(std::string A[N]) {
    for(int i = 0; i < N; i++)
        std::cout << A[i] << "\n";
}

void countingSortByLengths(std::string A[N], std::string B[N]) {
    int C[M];

    for(int i = 0; i < M; i++)
        C[i] = 0;

    for(int i = 1; i < N; i++)
        C[A[i].size()] += 1;

    for(int i = 1; i < M; i++)
        C[i] += C[i-1];

    for(int i = N - 1; i > 0; i--) {
        B[C[A[i].size()]] = A[i];
        C[A[i].size()]--;
    }
}

void countingSortByLeters(std::string A[N], std::string B[N], int position) {
    int C[M];

    for(int i = 0; i < M; i++)
        C[i] = 0;

    for(int i = 1; i < N; i++) {
        int indexOfLeter = ((int) (A[i][position])) - range;
        if(indexOfLeter != -65)
            C[indexOfLeter] += 1;
    }

    for(int i = 1; i < M; i++)
        C[i] += C[i-1];

    for(int i = N - 1; i > 0; i--) {
        int indexOfLeter = ((int) (A[i][position])) - range;
        if(indexOfLeter != -65) {
            B[C[indexOfLeter]] = A[i];
            C[indexOfLeter]--;
        }
    }
}

void radixSort(std::string A[N], std::string B[N]) {

    for(int i = theLongest; i >= 0; i--) {
        countingSortByLeters(A,B,i);
    }
}

int main() {
    std::string A[N] = {"", "TAKOW", "ABAAK", "WAK", "COKWR", "CAWK", "TWOJA", "WAWEL", "WOWL", "AAJ"};
    std::string B[N];

    printOutArray(A);

    countingSortByLengths(A,B);

    for(int i = 0 ;i < N; i++)
        A[i] = B[i];

    radixSort(A,B);

    std::cout << "After Sort" << "\n";
    printOutArray(B);

    return 0;
}