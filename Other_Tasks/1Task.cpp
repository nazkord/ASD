#include <iostream>

int const N = 10;

void printOutArray(int A[N]) {
    for(int i = 0; i < N; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << "\n";

}

bool sumOfElements(int A[N], int sum) {
    int j = N - 1;

    while(A[j] > sum)
        j--;

    /// now j point on the greatest element which is less or equal to sum

    if(A[0] > sum)
        return false;

    int i = 0;
    while(i != j) {
        int currentSum = A[i] + A[j];
        if(currentSum == sum) {
            std::cout << "Suma sie sklada z: " << A[i] << " i " << A[j] << "\n";
            return true;
        }

        if(currentSum > sum)
            j--;
        else
            i++;
    }
    return false;
}

int main() {

    int A[N] = {1,2,4,6,10,13,20,25,31,33};

    /*for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }*/

    int sum;
    std::cout << "Wpisz szukana sume: ";
    std::cin >> sum;

    printOutArray(A);

    if(sumOfElements(A,sum))
        std::cout << "TAK TAK TAAAK";
    else
        std::cout << "LIPSON";




    return 0;
}