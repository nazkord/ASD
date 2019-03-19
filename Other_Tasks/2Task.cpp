#include <iostream>
#include <cstdlib>
#include <ctime>

const int N = 10;

void swap(int A[N], int x, int y) {
    int temp = A[x];
    A[x] = A[y];
    A[y] = temp;
}

int partition(int A[N], int left, int right) {
    int pivot = A[right];
    int i = left;
    for(int q = left; q < right; q++) {
        if(A[q] < pivot) {
            if(q != i)
                swap(A,q,i);
            i++;
        }
    }

    swap(A,i,right);
    return  i;
}

void quickSort(int A[N], int left, int right) {
    if(left < right) {
        int pivot = partition(A,left,right);
        quickSort(A, left, pivot-1);
        quickSort(A, pivot + 1, right);
    }
}

int algorithmHoare(int A[N], int left, int right, int i) {
    if(left == right)
        return i;
    int q = partition(A,left,right);

    /// count the amount of numbers in the left subarray (from the left to the pivot inclusive)
    int numberLeftSubarray = q - left + 1;

    /// if pivot the i-th smallest number in array A
    if(numberLeftSubarray == i)
        return i;

    if(i < numberLeftSubarray)
        /// then i-th smallest number is in left subarray
        return algorithmHoare(A,left,numberLeftSubarray - 2,i);

    /// i-th smallest number is in right subarray
    return algorithmHoare(A,numberLeftSubarray + 1, right, i);

}

int main() {
    srand(time(nullptr));

    int A[N];
    for(int i = 0; i < N; i++)
        A[i] = rand()%10+1;
    for(int i = 0; i < N; i++)
        std::cout << A[i] << " ";
    std::cout << "\n";

    int i;
    std::cout << "Enter k-th smallest element you want to find: ";
    std::cin >> i;

    quickSort(A,0,N-1);

    for(int i = 0; i < N; i++)
        std::cout << A[i] << " ";
    std::cout << "\n";

    std::cout << i << "-th smallest element in array is: " << A[i-1] << "\n";

    std::cout << i << "-th smallest element in array is (using Hoare'a): " << A[algorithmHoare(A,0,N-1,i)];


    return 0;
}