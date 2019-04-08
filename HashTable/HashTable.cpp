#include <iostream>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
#include <term.h>

int const N = 10;
//some prime number to be used as a const in hashing probing
int const c = 3;

int elementInHashTable = 0;

struct Person {
    std::string name = "";
    int age = 0;
    bool occupied = false;
    bool deleted = false;
};

// function fot creating new person with given arguments
Person CreatePerson(std::string name, int age) {
    Person person;
    person.name = name;
    person.age = age;
    person.occupied = false;
    person.deleted = false;
    return person;
}

unsigned int functionNumerasing(std::string key) {
    unsigned int sum = 0;
    for(int i = 0; i < key.size(); i++) {
        sum += key[i]<<(i%4)*8;
    }
    return sum;
}

double getFillingLevel() {
    return (double)elementInHashTable/N*100;
}

void printOutArray(Person * HashTable, int size) {
    for(int i = 0; i < size; i++) {
        std::cout << HashTable[i].name << " " << HashTable[i].age << "\n";
    }
}

int hashFunction(int key, int size) {
    return key%size;
}

int probingFunction(int key, int probe, int size) {
    return (hashFunction(key,size) + c*probe*probe)%size;
}

void insertToHashTable(Person* HashTable, int size, Person person) {

    //take input (key) from user
    int keyAge = person.age;
    //find key's hash
    int hash;
    int probe = 0;
    do {
        hash = probingFunction(keyAge,probe,size);
        probe++;
    } while(HashTable[hash].occupied);

    //insert
    person.occupied = true;
    HashTable[hash] = person;
    //change and print the level of filling
    elementInHashTable++;
    std::cout << "Filling level is equal: " << getFillingLevel() << "%\n";
}

void deleteFromHashTable(Person* HashTable, int size, int key) {
    int hash;
    int probe = 0;
    // find hash for which key is equal to age of Person
    do {
        hash = probingFunction(key,probe,size);
        probe++;
    } while(HashTable[hash].age != key && probe != size);
    //delete (rewrite) person from founded hash
    if(probe != size) {
        Person person;
        person.deleted = true;
        person.occupied = false;
        HashTable[hash] = person;
        elementInHashTable--;
    }
}

int findAPerson(Person * HashTable, int size, int key) {
    for(int i = 0; i < N; i++) {
        int hash = probingFunction(key,i,size);
        // find the deleted object -> move forward
        if(HashTable[hash].deleted) continue;
        if(HashTable[hash].age == key) return hash;
    }
    return -1;
}

Person* reHashing(Person* oldHashTable, int sizeOld, Person* newHashTable, int sizeNew) {
    std::cout << ("\n***Rehashing Started***\n");

    // find a Person in "old" HashTable, make hash to and put it to "new" HashTable
    elementInHashTable = 0;
    for(int i = 0; i < sizeOld; i++) {
        if(oldHashTable[i].occupied) {
            //found a Person
            insertToHashTable(newHashTable, sizeNew, oldHashTable[i]);
        }
    }
    return newHashTable;
}

void console(Person* usedHashTable, int size) {
    bool flag = false;
    while(!flag) {
        int input;
        std::cout << "Delete element -> press 1: \n";
        std::cout << "Find element -> press 2: \n";
        std::cout << "Insert element -> press 3: \n";
        std::cout << "Rehashing  -> press 4: \n";
        std::cout << "Exit -> press not 1,2,3 \n";
        std::cin >> input;
        switch ( input )
        {
            case 1: {
                // delete case
                printOutArray(usedHashTable, size);
                std::cout << "Chose and write the age of person you want to delete: ";
                std::cin >> input;
                deleteFromHashTable(usedHashTable, size, input);
                printOutArray(usedHashTable, size);
                break;
            }
            case 2: {
                //find case
                printOutArray(usedHashTable, size);
                std::cout << "Enter the age of person you want to find: ";
                std::cin >> input;
                std::cout << usedHashTable[findAPerson(usedHashTable, size, input)].name << "\n";
                break;
            }
            case 3: {
                //insert case
                std::string name;
                int age;
                std::cout << "Enter name: ";
                std::cin >> name;
                std::cout << "Enter age: ";
                std::cin >> age;
                Person person = CreatePerson(name,age);
                insertToHashTable(usedHashTable, size, person);
                printOutArray(usedHashTable, size);
                break;
            }
            case 4: {
                //rehashing case
                flag = true;
            }
            default: {
                flag = true;
            }
        }

    }
}

int main() {

    Person hashTable[N];
    console(hashTable,N);
    Person hashTable2[2*N];
    reHashing(hashTable,N,hashTable2,2*N);
    console(hashTable2,2*N);


    return 0;
}