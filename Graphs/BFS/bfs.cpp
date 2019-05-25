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

int main() {

    return 0;
}