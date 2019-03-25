#include <iostream>
#include <cstdlib>
#include <ctime>

int const N = 15;

void printOutArray(int A[N]) {
    for(int i = 0; i < N; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << "\n";
}

void swap(int A[N], int x, int y) {
    int tmp = A[x];
    A[x] = A[y];
    A[y] = tmp;
}

int partition(int A[N], int left, int right) {
    int pivot = A[right];
    int i = left;
    for(int q = left; q < right; q++) {
        if(A[q] <= pivot) {
            if(q != i)
                swap(A,i,q);
            i++;
        }
    }
    swap(A,i,right);
    return i;
}

void sort(int T[N], int i, int j) {
    //printOutArray(T,N);

    if(i < j) {
        int pivot = partition(T, i, j);
        sort(T, i, pivot - 1);
        sort(T, pivot + 1, j);
    }
}

int randomizedSelectMin(int A[N], int left, int right, int i) {
    if(left == right)
        return A[left];
    int q = partition(A,left,right);

    /// count the amount of numbers in the left subarray (from the left to the pivot inclusive)
    int numberLeftSubarray = q - left + 1;

    /// if pivot the i-th smallest number in array A
    if(numberLeftSubarray == i)
        return A[q];

    if(i < numberLeftSubarray)
        /// then i-th smallest number is in left subarray
        return randomizedSelectMin(A,left,q - 1,i);

    /// i-th smallest number is in right subarray
    return randomizedSelectMin(A,q + 1, right, i - numberLeftSubarray);

}


int main() {
    srand(time(nullptr));

    int A[N];
    int from,to;
    std::cin >> from >> to;


    for(int i = 0; i < N; i++) {
        A[i] = rand()%20;
    }

    printOutArray(A);

    int fromMin = randomizedSelectMin(A,0,N-1,from);
    int toMin = randomizedSelectMin(A,0,N-1,to);

    sort(A,0,N-1);
    printOutArray(A);

    int sum = 0;
    for(int i = 0; i < N; i++) {
        if(A[i] >= fromMin && A[i] <= toMin)
            sum+=A[i];
    }

    std::cout << "suma: " << sum;

    return 0;
}