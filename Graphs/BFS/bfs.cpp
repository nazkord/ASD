#include <iostream>

struct node { /// for neighboring list
    int id;
    node * next;
};

enum Color {
    white, /// for unvisited vertex
    gray, /// for vertex which are actually executed
    black /// for visited vertex
};

struct vertex {
    node * neighbours; /// list with neighboring vertex (as node for decreasing memory cache)
    int id;
    Color color;
};

struct graph {
    vertex ** adjacent;
    int size;
};

void insertToEndOfList(node * tail, int valueToInserted) {
    node * newNode = new node;
    newNode -> id = valueToInserted;
    newNode -> next = nullptr;
    tail -> next = newNode;
}

graph * graphInit() {
    graph * graph1 = new graph;
    int x = 0;

    std::cout << "Enter number of vertex in graph: ";
    std::cin >> graph1 -> size;
    graph1 -> adjacent = new vertex *[graph1->size];

    for(int i = 0; i < graph1->size; i++) {
        graph1 -> adjacent[i] = new vertex;
        graph1 -> adjacent[i] -> id = i;
        graph1 -> adjacent[i] -> color = white;
        node * p = graph1 -> adjacent[i]->neighbours = nullptr;

        std::cout << "Enter the neighbor of vertex (end with -1) " << i << ": ";
        while(true) {
            std::cin >> x;
            if(x == -1)
                break;

            if(p != nullptr) {
                insertToEndOfList(p, x);
                p = p -> next;
            }
            else {
                p = new node;
                p -> id = x;
                p -> next = nullptr;
            }
        }
    }

    return graph1;
}

int main() {

    graph * mainGraph = graphInit();


    return 0;
}