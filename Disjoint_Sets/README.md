**disjoint_sets**
Implementions of disjoint sets using tree with union by rank and path compression for better complexity.

**Task 1:**
Kapitan pewnego statku zastanawia się, czy może wpłynąć do portu mimo tego, że nastąpił
odpływ. Do dyspozycji ma mapę zatoki w postaci tablicy:
int n = ...
int m = ...
int A[m][n];
gdzie wartość A[y][x] to głębokość zatoki na pozycji (x, y). Jeśli jest ona większa niż pewna
wartość int T to statek może się tam znaleźć. Początkowo statek jest na pozycji (0, 0) a port
znajduje się na pozycji (n − 1, m − 1). Z danej pozycji statek może przepłynąć bezpośrednio
jedynie na pozycję bezpośrednio obok (to znaczy, na pozycję, której dokładnie jedna ze
współrzędnych różni się o jeden). Proszę napisać funkcję rozwiązującą problem kapitana.


**Task 2:**
Dana jest tablica:
int n = ...
int m = ...
bool A[m][n];
Gracz początkowo znajduje się na (zadanej) pozycji (x, y), dla której zachodzi A[y][x] == true.
Z danej pozycji wolno bezpośrednio przejść jedynie na pozycję, której dokładnie jedna
współrzędna różni się o 1, oraz której wartość w tablicy A wynosi true. Proszę napisać program
obliczający do ilu różnych pozycji może dojść gracz startując z zadanej pozycji (x, y).
