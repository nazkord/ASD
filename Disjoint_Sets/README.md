**Task:**
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
