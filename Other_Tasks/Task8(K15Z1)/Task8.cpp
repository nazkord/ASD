#include <iostream>
#include <cstdlib>
#include <ctime>

/// amount of data (numbers)
int const N = 5;
int const size = N*N;

struct piece {
    /// index of the beginning of the piece
    int index;

    /// sum of this piece
    int sum;
};

void printOutArray(int T[], int size) {
    for(int i = 0; i < size; i++) {
        std::cout << T[i] << " ";
    }
    std::cout <<"\n";
}

void swap(piece T[N], int x, int y) {
    piece tmp = T[x];
    T[x] = T[y];
    T[y] = tmp;
}

int partition(piece A[N], int left, int right) {
    int pivot = A[right].sum;
    int i = left;
    for(int q = i; q < right; q++) {
        if(A[q].sum <= pivot) {
            if(q != i)
                swap(A,i,q);
            i++;
        }
    }
    swap(A,i,right);
    return i;
}

void quickSort(piece A[N], int i, int j) {
    if(i < j) {
        int pivot = partition(A,i,j);
        quickSort(A,i,pivot - 1);
        quickSort(A,pivot + 1,j);
    }
}

void sumSort(int A[size], int B[size]) {

    /// declare array which contains pieces
    piece headOfPieces[N];

    /// first step: traverse through array A and count the sum of particular pieces
    for(int i = 0; i < size; i+=N) {
        headOfPieces[i/N].index = i;
        headOfPieces[i/N].sum = 0;
        for(int j = i; j < i + N; j++) {
            headOfPieces[i/N].sum += A[j];
        }
    }

    /// second step: sort array of pieces by sum of those pieces
    quickSort(headOfPieces,0,N-1);


    /// third step: assign numbers from pieces to final array B

    int counterB = 0;
    for(int i = 0; i < N; i++) {
        int tmpIndex = headOfPieces[i].index;
        for(int j = tmpIndex; j < tmpIndex + N; j++) {
            B[counterB++] = A[j];
        }
    }
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

    printOutArray(B, size);


    return 0;
}