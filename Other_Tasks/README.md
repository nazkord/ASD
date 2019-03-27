**Tasks** 
1. Dana jest posortowana tablica int A[N] oraz liczba x.
Napisac program, który stwierdza czy istnieją indeksy i oraz j,
takie ze A[i]+A[j]=x (powinno działać w czasie O(N))
2. Algorithm Hoare'a. (Randomized-Select)
3. //
4. //
5. Dana jestr struktura opisująca listę jednokierunkową dla liczb rzeczywistych:
struct Node{ Node* next; double value; }
Proszę zaimplementować funkcję void Sort( Node* list ), która otrzymuje na wejściu listę
liczb rzeczywistych (z wartownikiem), wygenerowaną zgodnie z rozkładem jednostajnym na
przedziale (0,10) i sortuje jej zawartość w kolejności niemalejącej. Funkcja powinna być możliwie
jak najszybsza (biorąc pod uwagę warunki zadania). Proszę oszacować złożoność
zaimplementowanej funkcji.
6. Proszę zaimplementować funkcję:
int SumBetween(int T[], int from, int to, int n);
Zadaniem tej funkcji jest obliczyć sumę liczb z n elementowej tablicy T, które w posortowanej
tablicy znajdywałyby się na pozycjach o indeksach od from do to (włącznie). Można przyjąć, że
liczby w tablicy T są parami różne (ale nie można przyjmować żadnego innego rozkładu danych).
Zaimplementowana funkcja powinna być możliwie jak najszybsza. Proszę oszacować jej złożoność
czasową (oraz bardzo krótko uzasadnić to oszacowanie).
7. Napisać funkcję: void sortString(string A[]); Funkcja sortuje tablicę n stringów różnej
długości. Można założyć, że stringi składają się wyłącznie z małych liter alfabetu łacińskiego
8. Proszę zaimplementować funkcję void SumSort(int A[], int B[], int n). Funkcja ta
przyjmuje na wejściu dwie n dwie n^2-elementowe tablice (A i B) i zapisuje w tablicy B taką permutację
elementów z A, że:
sum from: X−1 to: i=0 on: B[i] <= from: 2Xn−1 to: i=n on: B[i] <= ... <= from: nX2−1 to: i=n2−n on: B[i].
Proszę zaimplementować funkcję SumSort tak, by działała możliwie jak najszybciej. Proszę
oszacować i podać jej złożoność czasową.

