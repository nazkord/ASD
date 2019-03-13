#include <iostream>

int const N = 7;

void merge(int T[N], int P[N], int begin, int middle, int end) {
    int firstCounter = begin;
    int secondCounter = middle + 1;
    int mainCounter = begin;

    for(int i = begin; i <= end; i++)
        P[i] = T[i];

    while(firstCounter <= middle && secondCounter <= end) {
        if(P[firstCounter] >= P[secondCounter]) {
            T[mainCounter] = P[secondCounter];
            secondCounter++;
        } else {
            T[mainCounter] = P[firstCounter];
            firstCounter++;
        }
        mainCounter++;
    }

    while(firstCounter <= middle) {
        T[mainCounter] = P[firstCounter++];
        mainCounter++;
    }
}

void mergeSort(int T[N], int P[N], int begin, int endd) {
    //gdy mamy wiecej niz jeden element do posortowania
    if(begin < endd) {
        mergeSort(T, P, begin, (begin + endd) / 2);
        mergeSort(T, P, (begin + endd) / 2 + 1, endd);
        merge(T, P, begin, (begin + endd)/2, endd);
    }

    merge(T, P, begin, (begin + endd)/2, endd);
}

int main() {
    int A[N] = {9,4,6,1,5,8,3};
    int P[N] = {0,0,0,0,0,0,0};

    mergeSort(A,P,0,N-1);

    for(int i = 0; i < N; i++)
        std::cout << P[i] << " ";


    return 0;
}