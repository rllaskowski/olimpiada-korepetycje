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

## Algorytmy

### DFS
Algorytm **DFS**(ang. **Depth First Search** - przeszukiwanie w głąb), opiera się na bardzo prostej zasadzie:

- Jeśli z aktualnego wierzchołka można przejść wychodzącą z niego krawędzią do
wierzchołka, który nie został wcześniej odwiedzony - przejdź tą krawędzią
- W przeciwnym przypadku wróć skąd przyszedłeś

Najczęstsza [implementacja](/grafy/dfs.cpp) tego algorytmu wykorzystuje rekurencję 

![DFS animacja](/zdjecia/dfs_animation.png)

### BFS
Algorytm **BFS**(ang. **Breadth First Search** - przeszukiwanie wszerz) służy do znajdowania najkrótszych ścieżek w grafie, w którym wszystkie krawędzie są tej samej długości.

W algorytmie wykorzystywana jest kolejka. [Implementacja](/grafy/bfs.cpp). 

```
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

