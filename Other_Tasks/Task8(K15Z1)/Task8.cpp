#include <iostream>
#include <cstdlib>
#include <ctime>

/// amount of data (numbers)
int const N = 5;
int const size = 25;

struct piece {
    /// index of the beggining of the piece
    int n;

    /// sum of this piece
    int sum;
};

void printOutArray(int T[], int size) {
    for(int i = 0; i < size; i++) {
        std::cout << T[i] << " ";
    }
    std::cout << "\n";
}

void sumSort(int A[size], int B[size]) {

    /// declare array which contains pieces
    piece headOfPieces[N];

    /// first step: traverse through array A and count the sum of particular pieces
    for(int i = 0; i < size; i+=N) {
        headOfPieces[i/N].n = i;
        headOfPieces[i/N].sum = 0;
        for(int j = i; j < i + N; j++) {
            headOfPieces[i/N].sum += A[j];
        }
    }

    std::cout << "SUMY: ";
    for(int j = 0; j < N; j++)
        std::cout << headOfPieces[j].sum << "\n";
}

int main() {
    //srand(time(nullptr));

    int A[size];
    for (int i = 0; i < size; i++) {
        A[i] = rand() % 10;
    }

    int B[size];
    for (int i = 0; i < size; i++) {
        B[i] = 0;
    }

    printOutArray(A, size);

    sumSort(A,B);

    //printOutArray(B, size);


    return 0;
}