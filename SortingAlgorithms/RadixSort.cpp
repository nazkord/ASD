#include <iostream>
#include <cstdlib>
#include <ctime>

/// amount of data (numbers)
int const N = 10;

/// range of data: from 0 to M
int const M = N*N-1;

int getAmountOfDigitInNumber(int x) {
    int counter = 0;
    while(x > 0) {
        counter++;
        x/=10;
    }
    return counter;
}

int power(int n, int q) {
    /// return n^q
    int number = 1;
    for(int i = 0; i < q; i++) {
        number*=n;
    }
    return number;
}

void printOutArray(int T[], int size) {
    for(int i = 0; i < size; i++) {
        std::cout << T[i] << " ";
    }
    std::cout << "\n";
}

/// n - number, k - number of digit to get
int getDigitFromNumber(int n, int k) {
    return (k==1)?n%10:n%power(10,k)/power(10,k-1);
}

void countingSort(int A[N], int B[N], int k) {
    /// k - number of digit by which the array A will sort

    /// size of B array = range of data
    int C[M];

    /// fill array C with 0
    for(int i = 0; i < M; i++)
        C[i] = 0;

    /// main loop, which counts appears of numbers from array A
    for(int i = 1; i < N; i++) {
        int digit = getDigitFromNumber(A[i],k);
        C[digit]++;
    }

    //printOutArray(C,N);

    /// count the number of elements (numbers) before element (number) in each cell of array C
    for(int i = 1; i < M; i++) {
        C[i] = C[i] + C[i-1];
    }

    //printOutArray(C,N);

    for(int i = N - 1; i > 0; i--) {
        int digit = getDigitFromNumber(A[i],k);
        B[C[digit]] = A[i];
        C[digit]--;
    }
}

/// the sorting method which based on countingSort
/// sort by particular digits in number
void radixSort(int A[N], int B[N]) {
    /// count max amount of digit in number (M) - maximum number in data

    int amountOfDigits = getAmountOfDigitInNumber(M);

    for(int j = 1; j <= amountOfDigits; j++) {
        countingSort(A, B, j);
    }
}

int main() {
    srand(time(nullptr));

    int A[N];
    for(int i = 1; i < N; i++) {
        A[i] = rand()%M;
    }

    int B[N];
    for(int i = 1; i < N; i++) {
        B[i] = 0;
    }

    printOutArray(A,N);

    radixSort(A,B);

    printOutArray(B,N);


    return 0;
}