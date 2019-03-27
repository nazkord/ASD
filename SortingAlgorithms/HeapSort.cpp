#include <iostream>

int const N = 9;
int heapSize = N;


void swap(int T[N], int a, int b) {
    int temp = T[b-1];
    T[b-1] = T[a-1];
    T[a-1] = temp;
}

//Wrzuca element o indeksie i na swoje prawidlowe miejsce na dole
//aby kopiec o korzeniu i byl kopcem typu max
void maxHeapify(int T[N], int i) {
    if(i > heapSize/2)
        return;

    int l = 2*i;
    int r = 2*i + 1;
    int largest = i;
    if(l <= heapSize && T[l-1] > T[largest-1])
        largest = l;
    if(r <= heapSize && T[r-1] > T[largest-1])
        largest = r;
    if(largest != i) {
        swap(T,i,largest);
        maxHeapify(T,largest);
    } else
        return;
}

//Tworzy kopiec typu max, robiac | poczawszy od ostatniego elemenetu,
//ktory nie jest lisciem (N/2) | maxHeapify | az do korzenia calego kopca

//Czyli uporzadkowuje caly kopiec, aby byl typem max
void buildMaxHeap(int T[N]) {
    for(int i = N/2; i > 0; i--) {
        maxHeapify(T,i);
    }
}

void heapSort(int T[N]) {
    //Tworzymy kopiec typu max
    buildMaxHeap(T);

    for(int i = N; i > 1; i--) {
        swap(T,1,i);
        heapSize--;
        maxHeapify(T,1);
    }
}

void printOutArray(int T[N]) {
    for(int i = 0; i < N; i++) {
        std::cout << T[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    int A[N] = {5,3,17,10,84,19,6,22,9};

    heapSort(A);

    printOutArray(A);


    return 0;
}