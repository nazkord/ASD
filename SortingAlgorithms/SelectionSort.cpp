#include <iostream>

int const N = 8;

//Sorting by selection decreasing

void selectionSort(int t[N]) {
    int index;
    for(int i = 0; i < N - 1; i++) {
        index = i;
        for(int j = i + 1; j < N; j++) {
            if(t[j] < t[index])
                index = j;
        }
        int temp = t[i];
        t[i] = t[index];
        t[index] = temp;
    }
}

void printOut(int A[N]) {
    for(int i = 0; i < N; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    int A[N];
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    printOut(A);

    selectionSort(A);

    printOut(A);

    return 0;
}