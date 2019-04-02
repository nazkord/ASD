#include <iostream>
#include <ctime>
#include <cstdlib>

int const N = 10;
//some prime number to be used as a const in hashing probing
int const c = 3;

int addedElement = 0;

struct person {
    std::string name;
    int age = 0;
    bool occupied = false;
    bool deleted = false;
};

//global hashTable
person hashTable[N];

double getFillingLevel() {
    return (double)addedElement/N*100;
}

void printOutArray() {
    for(int i = 0; i < N; i++) {
        std::cout << hashTable[i].name << hashTable[i].age << "\n";
    }
}

int hashFunction(int key) {
    return key%N;
}

int probingFunction(int key, int probe) {
    return (hashFunction(key) + c*probe*probe)%N;
}

void insertToHashTable() {

    //take input (key) from user
    int keyAge;
    std::string name;
    std::cout << "Wpisz imie: ";
    std::cin >> name;
    std::cout << "Wpisz wiek: ";
    std::cin >> keyAge;

    //find key's hash
    int hash;
    int probe = 0;
    do {
        hash = probingFunction(keyAge,probe);
        probe++;
    } while(hashTable[hash].occupied);

    //insert
    hashTable[hash].name = name;
    hashTable[hash].age = keyAge;
    hashTable[hash].occupied = true;

    //change and print the level of filling
    addedElement++;
    std::cout << "Filling level is equal: " << getFillingLevel() << "%\n";
}

void deleteFromHashTable(int key) {
    int hash;
    int probe = 0;
    // find hash for which key is equal to age of person
    do {
        hash = probingFunction(key,probe);
        probe++;
    } while(hashTable[hash].age != key);


}

int main() {
    //srand(time(nullptr));


    for(int i = 0; i < N/4*3; i++) {
        insertToHashTable();

    }

    printOutArray();




    return 0;
}