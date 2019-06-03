 **Breadth-first search (BFS)** is an algorithm for traversing or searching tree or graph data structures. 
 It starts at the tree root (or some arbitrary node of a graph, sometimes referred to as a 
 'search key') and explores the neighbor nodes first, before moving to the next level neighbors.
 Implement **BFS** using pseudocode from Cormen, this why my vertex structure has three different colors.
 @see <a href="https://en.wikipedia.org/wiki/Breadth-first_search">Breadth-First Search (Wikipedia)</a>
 
 
 Dijkstry is algorithm for finding the shortest paths between one node in a graph, and every other.
 @see <a href="https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm">Dijkstry algorithm (Wikipedia)</a> 

 **Dijsktry** file implements this algorithm with n^2 complexity using two additional array of visited nodes 
 and with distance of all nodes.
 
 **Dijkstry2** file implements this algorithm with nlogn complexity in worst case using heap 
 (dynamic array with pointer to Vertex from mainGraph) as priority queue of Vertex with additional attribute -> distance.
 
 **Dijkstry3** file implements this algorithm with nlogn complexity in worst case using normal priority queue and some interesting c++ library such as pair or vector.
 
 
