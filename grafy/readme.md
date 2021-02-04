# Grafy

### Oznaczenia
- `a->b` - Krawędź prowadząca z wierzchołka a do wierzchołka b 

## Terminologia

### Ścieżka
Ciąg wierzchołków, w którym wszystkie sąsiadujące wierzchołki są połączone ze sobą
krawędzią. (droga przechodząca po wierzchołkach przez łączące je krawędzie)

Zaznaczona na rysunku ścieżka:
`2->0->3->4->1`

![sciezka](/zdjecia/sciezka.png)

### Cykl
Ścieżka niezerowej długości, która rozpoczyna i kończy się w jednym wierzchołku

Jeden z cykli na rysunku poniżej: `1->3->4->2->1`

![cykl](/zdjecia/cykl.png)

### Graf nieskierowany
Graf, w którym wszystkie krawedzie prowadzą w obie strony.

Innymi słowy, jeśli istnieje krawędź `a->b` to istnieje również krawędź `b->a`

![Graf nieskierowany](/zdjecia/nieskierowany.png)

### Graf skierowany
Graf, w którym krawędzie prowadzą w jedną stronę.

Innymi słowy, jeśli z istnienia krawędzi `a->b` nie wynika istnienie krawędzi `b->a`

![Graf skierowany](/zdjecia/skierowany.png)
### Graf spójny
Graf nieskierowany, w którym istnieje conajmniej jedna ścieżka między każdą parą wierzchołków

### Graf acykliczny
Graf, w którym nie istnieje cykl

### Drzewo 
Graf nieskierowany, acykliczny, którym istnieje dokładnie jedna ścieżka pomiędzy każdą parą wierzchołków

## Podstawowe algorytmy

### DFS
Algorytm **DFS**(ang. **Depth First Search** - przeszukiwanie w głąb), opiera się na bardzo prostej zasadzie:

- Jeśli z aktualnego wierzchołka można przejść wychodzącą z niego krawędzią do
wierzchołka, który nie został wcześniej odwiedzony - przejdź tą krawędzią
- W przeciwnym przypadku wróć skąd przyszedłeś

Najczęstsza [implementacja](/grafy/dfs.cpp) tego algorytmu wykorzystuje rekurencję 

![DFS animacja](/zdjecia/dfs_animation.png)

### BFS
Algorytm **BFS**(ang. **Breadth First Search** - przeszukiwanie wszerz) będzie nam służył przede wszystkim do znajdowania najkrótszych ścieżek w grafie, w którym wszystkie krawędzie są tej samej długości.

W trakcie działania BFS najpierw zostaną odwiedzone wszystkie wierzchołki w odległości 0 od wierzchołka startowego, potem wszystkie w odległości 1, potem wszystkie w odległości 2....

W algorytmie wykorzystywana jest kolejka. [Implementacja](/grafy/bfs.cpp). 

```niewazony
dodaj na kolejkę wierzchołek startowy
ustaw odległość 0 wierzchołkowi startowemu

Dopóki kolejka niepusta:
    zdejmij z kolejki wierzchołek v

    Dla każdej krawędzi v->x:
        Jeśli x nie ma ustawionej odległości:
            ustaw x odległość o 1 większą niż odległość v
            wstaw x na kolejkę
```

![BFS animacja](/zdjecia/bfs_animation.gif)


### DFS a BFS

![DFS vs BFS](/zdjecia/dfs-vs-bfs.gif)

## Reprezentacja grafu w kodzie

### Macierz sąsiedztwa
W macierzy(tablicy dwuwymiarowej) sąsiedztwa będzie zapisywali krawędzie w następujący sposób(niech naszą macierzą będzie tablica `kraw`):

Jeśli istnieje krawędź `a->b`:
`kraw[a][b] = 1` 
W przeciwnym przypadku:
`kraw[a][b] = 0`


**Przykład**

![macierz](/zdjecia/nieskierowany.png)
|  nr | 1 | 2 | 3 | 4 |  
|:---:|:-:|:-:|:-:|:-:|
|**1**| 0 | 1 | 1 | 0 | 
|**2**| 1 | 0 | 1 | 0 |
|**3**| 1 | 1 | 0 | 0 |
|**4**| 0 | 0 | 1 | 0 |

```cpp
/* Macierz sąsiedztwa początkowo wypełniona zerami */
int kraw[1000][1000];
...

int a, b;
for (int i = 0; i < m; i++) {
    /* wczytanie wierzchołków połączonych krawędzią */
    cin >> a >> b;

    /* 
    Zaznaczamy w macierzy istnienie krawędzi a->b oraz b->a
    UWAGA! jeśli graf ma być nieskierowany, dodajemy tylko krawędź w jedną stronę!
    */
    kraw[a][b] = 1;
    kraw[b][a] = 1;
}
```
Zauważmy, że to podejście wymaga od nas stworzenia tablicy, której całkowity rozmiar jest kwadratem ilości wierzchołków w grafie. Jeśli graf będzie rzadki(będzie miał mało krawędzi) to większość miejsc tej tablicy będzie nieużywana. Natomiast plusem tego podejścia jest fakt, że możemy w czasie stałym sprawdzić czy istnieje pewna krawędź.

### Listy sąsiedztwa
W tym podejściu dla każdego wierzchołka chcemy zapisać listę wszystkich wierzchołków, do których da się z niego przejść krawędzią.

Innymi słowy, jeśli istnieje krawędź `a->b`
to `b` będzie na liście sąsiedztwa wierzchołka `a`.

To podejście możemy zrealizować za pomocą tablicy vectorów(rozszerzalne tablice w C++). Dla każdego numeru wierzchołka, w jego osobnym vectorze, zapiszemy wszystkie numery wierzchołków, do których prowadzi krawędź.

**Przykład**

![lista sąs](/zdjecia/nieskierowany.png)

| nr  | lista sąsiedztwa(vector) |
|-----| :--------------  |
|**1**| 2, 3             |
|**2**| 3, 1             |
|**3**| 2, 1             |
|**4**| 3                |
```cpp

/*
Listy sąsiedztwa - tablica vectorow

kraw[x] jest vectorem(czyli rozszerzalna tablicą), w którym
trzymane są numery wierzchołków, do których da się dojść
z wierzchołka x 
*/
vector<int> kraw[100001];
...

int a, b;
for (int i = 0; i < m; i++) {
    /* wczytanie wierzchołków połączonych krawędzią */
    cin >> a >> b;

    /* 
    Do krawędzi wierzchołka a dodajemy wierzchołek b
    oraz na odwrót.
    UWAGA! jeśli graf ma być nieskierowany, dodajemy tylko krawędź w jedną stronę!
    */
    kraw[a].push_back(b);
    kraw[b].push_back(a);
}
```