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
Ścieżka, niezerowej długości, która rozpoczyna i kończy się w jednym wierzchołku

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
Algorytm DFS inaczej przeszukiwanie grafu w głąb opiera się na bardzo prostej zasadzie:

- Jeśli z danego wierzchołka możesz przejść wychodzącą z niego krawędzią do
wierzchołka, który nie został wcześniej odwiedzony - przejdź tą krawędzią
- W przeciwnym przypadku wróć skąd przyszedłeś

Najczęstsza(i najprostsza) [implementacja](/grafy/dfs.cpp) tego algorytmu wykorzystuje rekurencję 

![DFS animacja](/zdjecia/dfs_animation.png)