#include <iostream>
#include <queue>

struct node { /// for neighboring list
    int id;
    int weight;
    node * next;
};

enum Color {
    white, /// for unvisited vertex
    gray, /// for vertex which are actually executed
    black /// for visited vertex
};

struct Vertex {
    node * neighbours; /// list with neighboring vertex (as node for decreasing memory cache)
    int id;
    Color color;
    int distance;
    Vertex * parent;
};

struct Graph {
    Vertex ** adjacent;
    int size;
};

void insertToEndOfList(node * tail, int valueToInserted) {
    node * newNode = new node;
    newNode -> id = valueToInserted;
    newNode -> next = nullptr;
    tail -> next = newNode;
}

Vertex * vertexInit(int id) {
    Vertex * newVertex = new Vertex;
    newVertex -> id = id;
    newVertex -> color = white;
    newVertex -> distance = 0;
    newVertex -> parent = nullptr;
    return newVertex;
}

Graph * graphInit() {
    Graph * graph1 = new Graph;
    int x = 0;

    std::cout << "Enter number of Vertex in Graph: ";
    std::cin >> graph1 -> size;
    graph1 -> adjacent = new Vertex *[graph1->size];

    for(int i = 0; i < graph1->size; i++) {
        graph1 -> adjacent[i] = vertexInit(i);

        node * p = graph1 -> adjacent[i]->neighbours = nullptr;

        std::cout << "Enter the neighbor of Vertex (end with -1) " << i << ": ";
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
                graph1 -> adjacent[i]->neighbours = p;
            }
        }
    }

    return graph1;
}

void Dijkstry(Graph * graph, Vertex * beginVertex) { /// size of distance array is equal to amount of vertex in graph

    bool * visited = new bool[graph->size];
    for(int i = 0; i < graph->size; i++) visited[i] = false;

    Vertex * u;
    Vertex * v;
    graph->adjacent[beginVertex->id]->distance = 0;

    for(int i = 0; i < graph->size; i++) {

        u = findMin(graph, visited); /// find the smallest one unvisited node
        visited[u->id] = true;

        node * temp = graph -> adjacent[u->id] -> neighbours;
        while(temp != nullptr) {
            v = graph -> adjacent[temp -> id];
            if(graph->adjacent[v->id]->distance > graph->adjacent[u->id]->distance + temp->weight) {
                graph->adjacent[v->id]->distance = graph->adjacent[u->id]->distance + temp->weight;
                graph->adjacent[v->id]->parent = u;
            }
            temp = temp -> next;
        }
    }

}

int main() {
    Graph * mainGraph = graphInit();
    int * distance = new int[mainGraph->size];
    for(int i = 0; i < mainGraph->size; i++) {
        mainGraph->adjacent[i]->distance = INT_MAX;
    }
    Dijkstry(mainGraph, mainGraph -> adjacent[0]);


    return 0;
}