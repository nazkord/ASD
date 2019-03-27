#include <iostream>
#include <cstdlib>
#include <ctime>

/// amount of data (numbers)
int const N = 15;

/// range of data: [0,N^2-1]

/// base of radix Sort
int const base = N;

void printOutArray(int T[], int size) {
    for(int i = 1; i < size; i++) {
        std::cout << T[i] << " ";
    }
    std::cout << "\n";
}

/// x - number, pos - position to get
int getDigitFromNumber(int x, int pos) {
    if(pos == 1)
        return x%base;
    int i = 1;
    x /= base;
    int dig = 0;

    while (x != 0 && i != pos) {
        dig = x%base;
        x /= base;
        i++;
    }
    return  dig;
}

void countingSort(int A[N], int B[N], int position) {
    /// position - position in number by which the array A will sort

    int C[N];

    /// fill array C with 0
    for(int i = 0; i < N; i++)
        C[i] = 0;

    /// main loop, which counts appears of numbers from array A
    for(int i = 1; i < N; i++) {
        int digit = getDigitFromNumber(A[i],position);
        C[digit]++;
    }

    /// count the number of elements (numbers) before element (number) in each cell of array C
    for(int i = 1; i < N; i++) {
        C[i] += C[i-1];
    }

    for(int i = N - 1; i > 0; i--) {
        int digit = getDigitFromNumber(A[i],position);
        B[C[digit]] = A[i];
        C[digit]--;
    }
}

/// the sorting method which based on countingSort
/// sort by particular position in number
///  Sort n elements array z numbers range from [0, n^p-1]
void radixSort(int A[N], int B[N], int pos) {
    for(int j = 1; j <= pos; j++) {
        countingSort(A, B, j);
    }
}

int main() {
    srand(time(nullptr));

    int A[N];
    for(int i = 1; i < N; i++) {
        A[i] = rand()%(N*N-1);
    }

    int B[N];
    for(int i = 1; i < N; i++) {
        B[i] = 0;
    }

    printOutArray(A,N);

    radixSort(A,B,2);

    printOutArray(B,N);


    return 0;
}
