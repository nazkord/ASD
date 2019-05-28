#include <iostream>
#include <queue>

struct node { /// for neighboring list
    int id;
    int weight;
    node * next;
};

struct Vertex {
    node * neighbours; /// list with neighboring vertex (as node for decreasing memory cache)
    int id;
    int distance;
    Vertex * parent;
};

struct Graph {
    Vertex ** adjacent;
    int size;
};

void swap(Vertex * T[], int a, int b) {
    Vertex * temp = T[b-1];
    T[b-1] = T[a-1];
    T[a-1] = temp;
}

//Wrzuca element o indeksie i na swoje prawidlowe miejsce na dole
//aby kopiec o korzeniu i byl kopcem typu max
void minHeapify(Vertex * T[], int heapSize, int i) {
    if(i > heapSize/2)
        return;

    int l = 2*i;
    int r = 2*i + 1;
    int smallest = i;
    if(l <= heapSize && T[l-1]->distance < T[smallest-1]->distance)
        smallest = l;
    if(r <= heapSize && T[r-1]->distance < T[smallest-1]->distance)
        smallest = r;
    if(smallest != i) {
        swap(T,i,smallest);
        minHeapify(T,heapSize,smallest);
    } else
        return;
}

//Tworze kopiec typu min, robiac | poczawszy od ostatniego elemenetu,
//ktory nie jest lisciem (N/2) | minHeapify | az do korzenia calego kopca

//Czyli uporzadkowuje caly kopiec, aby byl typem max
void buildMinHeap(Vertex * T[], int heapSize) {
    for(int i = heapSize/2; i > 0; i--) {
        minHeapify(T,heapSize,i);
    }
}

void insertToEndOfList(node * tail, int valueToInserted, int weight) {
    node * newNode = new node;
    newNode -> id = valueToInserted;
    newNode -> weight = weight;
    newNode -> next = nullptr;
    tail -> next = newNode;
}

Vertex * vertexInit(int id) {
    Vertex * newVertex = new Vertex;
    newVertex -> id = id;
    newVertex -> distance = 0;
    newVertex -> parent = nullptr;
    return newVertex;
}

Graph * graphInit() {
    Graph * graph1 = new Graph;
    int x = 0;
    int weight = 0;

    std::cout << "Enter number of Vertex in Graph: ";
    std::cin >> graph1 -> size;
    graph1 -> adjacent = new Vertex *[graph1->size];

    for(int i = 0; i < graph1->size; i++) {
        graph1 -> adjacent[i] = vertexInit(i);

        node * p = graph1 -> adjacent[i]->neighbours = nullptr;

        std::cout << "Enter the neighbor of Vertex and the weight of edge (end with -1) " << i << ": ";
        while(true) {
            std::cin >> x;
            if(x == -1)
                break;
            std::cin >> weight;

            if(p != nullptr) {
                insertToEndOfList(p, x, weight);
                p = p -> next;
            }
            else {
                p = new node;
                p -> id = x;
                p -> weight = weight;
                p -> next = nullptr;
                graph1 -> adjacent[i]->neighbours = p;
            }
        }
    }

    return graph1;
}

void Dijkstry2(Graph * graph, Vertex * beginVertex, Vertex * heapVertex[], int heapSize) { /// size of distance array is equal to amount of vertex in graph

    Vertex * u;
    Vertex * v;
    graph->adjacent[beginVertex->id]->distance = 0;

    for(int i = 0; i < graph->size; i++) {

        buildMinHeap(heapVertex,heapSize); /// find the smallest one unvisited node (buildMinHeap)
        u = heapVertex[0]; /// get the first element (the smallest one after building minHeap)

        if(heapSize == 0)
            break;

        swap(heapVertex,1,heapSize);
        heapSize--;
        minHeapify(heapVertex,heapSize,1);

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

void findPath(Vertex * beginVertex, Vertex * endVertex) {
    Vertex * temp = endVertex;
    while(temp != beginVertex) {
        std::cout << temp -> id << " ";
        temp = temp -> parent;
    }
    std::cout << temp -> id;
}

int main() {
    Graph * mainGraph = graphInit();

    Vertex ** heapVertex = new Vertex*[mainGraph->size];

    for(int i = 0; i < mainGraph->size; i++) {
        mainGraph->adjacent[i]->distance = INT_MAX;
        heapVertex[i] = mainGraph->adjacent[i];
    }

    Dijkstry2(mainGraph, mainGraph -> adjacent[0], heapVertex, mainGraph->size);

    for(int i = 0; i < mainGraph->size; i++) {
        std::cout << heapVertex[i]->distance << " ";
        // or -> std::cout << mainGraph->adjacent[i]->distance << " ";
    }

    findPath(mainGraph -> adjacent[0], mainGraph -> adjacent[3]);

    return 0;
}