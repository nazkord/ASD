#include <iostream>
#include <queue>

struct node { /// for neighboring list
    int id;
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

void BFS(Graph * graph, Vertex * beginVertex) {
    std::queue<Vertex*> queueOfVertex;
    Vertex * u;
    Vertex * v;

    beginVertex -> color = gray;
    queueOfVertex.push(beginVertex);

    while(!queueOfVertex.empty()) {

        v = queueOfVertex.front();
        queueOfVertex.pop();

        node * temp = graph -> adjacent[v -> id] -> neighbours;
        while(temp != nullptr) {
            u = graph -> adjacent[temp -> id];
            if(u -> color == white) {
                u -> color = gray;
                u -> parent = v;
                u -> distance = v -> distance + 1;
                queueOfVertex.push(u);
            }
            temp = temp -> next;
        }
        std::cout << " " << v -> id;
        v -> color = black;
    }
}

int main() {

    Graph * mainGraph = graphInit();
    BFS(mainGraph, mainGraph -> adjacent[0]);

    return 0;
}