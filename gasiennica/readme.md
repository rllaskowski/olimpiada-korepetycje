# Gąsiennica

Metoda gąsiennicy przydaje się w zadaniach, w których pytamy o długość najdłuższego/najkrótszego
podciągu spełniającego pewne warunki(ew. sumie/maksimum/minimum wartości na tym podciągu) lub ilości podciagów o danej własności.

## Przykład zadania

Dla danego ciagu liczb nieujemnych o długości **n** znależć ilość podciągów, których suma elementów jest dokładnie równa **S** 

### Rozwiązanie brutalne

Oczywiście pierwszą myślą powinno być rozpatrzenie wszystkich możliwych podciągów i zliczenie tych, które spełniają nasz warunek.

```cpp
int liczby[1000000];

int n, S;
cin >> n >> S;

for (int i=0; i<n; i++) {
    cin >> liczby[i];
}

int wynik = 0;

for (int i = 0; i < n; i++) {
    /*
    teraz rozpatrujemy podciagi rozpoczynajace 
    się na indeksie i
    */
    int suma = 0; //
    for(int j = i; j < n; j++) {
        /* Roszerzamy nasz podciag w prawo */
        suma += liczba[i];

        if (suma == S) {
            wynik++;
        }

        if (suma >= S) {
            /*Ponieważ liczby są nieujemne, to dalej suma będzie tylko większa
            - dalej nie znajdziemy dobrego podciagu 
            więc przerywamy pętlę*/
            break;
        }
    } 
}

cout << wynik;
```

Oczywiście to podejście jest za wolne. Nasz algorytm działa w złożności kwadratowej ponieważ w pesmistycznym przypadku sprawdzi wszystkie możliwe podciągi, których dla ciągu o długości **n** jest około `n*n`

## Podejście metodą gąsiennicy

Zauważmy, że jeśli dla indeksu **p** znaleźliśmy takie **k**(k<=p), że suma liczb w ciągu od **k** do **p** jest równa lub większa **S**


```cpp

```