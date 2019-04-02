#include <iostream>
#include <ctime>
#include <cstdlib>

int const N = 10;
//some prime number to be used as a const in hashing probing
int const c = 3;

int addedElement = 0;

struct Person {
    std::string name;
    int age;
    bool occupied = false;
    bool deleted = false;
};

//global hashTable
Person hashTable[N];

// function fot creating new person with given arguments
Person CreatePerson(std::string name, int age) {
    Person person;
    person.age = age;
    person.name = name;
    person.occupied = false;
    person.deleted = false;
    return person;
}

double getFillingLevel() {
    return (double)addedElement/N*100;
}

void printOutArray() {
    for(int i = 0; i < N; i++) {
        std::cout << hashTable[i].name << " " << hashTable[i].age << "\n";
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

    Person person = CreatePerson(name,keyAge);

    //find key's hash
    int hash;
    int probe = 0;
    do {
        hash = probingFunction(keyAge,probe);
        probe++;
    } while(hashTable[hash].occupied);

    //insert
    person.occupied = true;
    hashTable[hash] = person;
    //change and print the level of filling
    addedElement++;
    std::cout << "Filling level is equal: " << getFillingLevel() << "%\n";
}

void deleteFromHashTable(int key) {
    int hash;
    int probe = 0;
    // find hash for which key is equal to age of Person
    do {
        hash = probingFunction(key,probe);
        probe++;
    } while(hashTable[hash].age != key);

    //delete (rewrite) person from founded hash
    Person person;
    person.deleted = true;
    person.occupied = false;
    hashTable[hash] = person;
}

int findAPerson(int key) {
    for(int i = 0; i < N; i++) {
        int hash = probingFunction(key,i);
        // find the deleted object -> move forward
        if(hashTable[hash].deleted) continue;
        if(hashTable[hash].age == key) return hash;
    }
    return -1;
}

int main() {
    //srand(time(nullptr));


    for(int i = 0; i < N/4*3; i++) {
        insertToHashTable();
    }

    printOutArray();

    std::cout << "Chose and write the age of person you want to delete: ";
    int deleteAge;
    std::cin>>deleteAge;
    deleteFromHashTable(deleteAge);
    printOutArray();
    std::cin>>deleteAge;
    deleteFromHashTable(deleteAge);
    printOutArray();

    int findbyAge;
    std::cin>>findbyAge;
    std::cout << hashTable[findAPerson(findbyAge)].name;


    return 0;
}