# Sumy prefiksowe

Dosyć często w trakcie rozwiązywania zadania przydatna okazuje się informacja o sumie liczb na przedziale w pewnym ciagu

[Przykładowe zadanie](halloween.pdf)

Prostym i brutalnym rozwiązaniem jest przejście pętlą po zadanym przedziale i sumowanie znajdujących się tam liczb.

### Przykład
```cpp
int cukierki[MAX];
...
// początek oraz koniec przedziału z zapytania
int pocz, kon; 
...
cin >> pocz >> kon;

int suma = 0;
for (int i = pocz; i <= kon; i++) {
    suma += cukierki[i];
}

cout << suma << endl;
```
Często jednak takie zapytania są wieloktrotnie powtarzane.
Rozwiązanie brutalne, polegające przechodzeniu przez wszystkie liczby z przedziału może okazać się niewystarczająco
optymalne czasowo. Wydaje się, że niektóre obliczenia niepotrzebnie powtarzamy przy każdym zapytaniu.

### Przykład 
```cpp
int cukierki[MAX];
...
int zapytania; // ilość zapytań w teście
int pocz, kon; // początek oraz koniec przedziału z zapytania
...
cin >> zapytania;

for (int z = 0; z < zapytania; z++) {
    cin >> pocz >> kon;

    int suma = 0;
    for (int i = pocz; i <= kon; i++) {
        suma += cukierki[i];
    }

    cout << suma << endl;
}

```

Uprośćmy nasz problem: początek przedziału zawsze będzie znajdował się na pierwszej liczbie z ciągu.
Jak możemy teraz usprawnić działanie algorytmu? 

Zauważmy, że suma liczb w ciągu na przedziale 
`<1, n>` jest równa sumie liczb na przedziale 
od `<1, n-1>` + n-ta liczba z ciągu.

Korzystając z tej prostej obserwacji spamiętajmy sumy liczb na **prefiksach** (początkowych elementach) ciągu.
Zróbmy to przed pierwszym zapytaniem. Teraz przy każdym zapytaniu możemy odnieść się do spamiętanych wcześniej wyników.


### Przykład 
```cpp
int cukierki[MAX];
int sumy[MAX];
...
sumy[0] = 0;
for (int i = 1; i < MAX; i++) {
    sumy[i] = sumy[i-1]+cukierki[i];
}
...
int zapytania; // ilość zapytań w teście
int kon; // koniec przedziału z zapytania
...
cin >> zapytania;

for (int z = 0; z < zapytania; z++) {
    cin >> kon;

    cout << sumy[kon] << endl;
}

```
Przykładowa zawartość tablicy cukierki oraz odpowiadającej jej tablicy sumy:


|indeksy |0  |1  |2  |4  |5  |6  |8  |9  |
|--------|---|---|---|---|---|---|---|---|
|cukierki|0  |4  |2  |1  |15 |3  |8  |1  |
|sumy    |0  |4  |6  |7  |22 |25 |33 |34 |


Obliczone sumy nazywamy od teraz **sumami prefiksowymi**.

Wracamy do oryginalnego problemu. Jak możemy wykorzystać sumy prefiksowe, kiedy początek przedziału nie zawsze
znajduje się na pierwszej wartości?

Chcemy korzystając z powyżej tabeli móc natychmiast odpowiedzieć na pytania postaci: jaka jest suma liczb na dowolnym przedziale <a, b>

Zauważmy, że suma liczb na przedziale <1,b> ` = sumy[ b ]` jest równa sumie liczb na przedziale <1,a-1> `= sumy[ a-1 ]`  +
suma liczb na przedziale <a,b>.

Przekształcając odpowiednio powyższe równanie otrzymujemy pokazujemy, że suma liczb na przedziale <a,b> jest równa
```
sumy[b]-sumy[a-1]
```

```cpp
int cukierki[MAX];
int sumy[MAX];
...
// Obliczamy sumy prefiksowe
sumy[0] = 0;
for (int i = 1; i < MAX; i++) {
    sumy[i] = sumy[i-1]+cukierki[i];
}
...
int zapytania; // ilość zapytań w teście
int pocz, kon; // początek i koniec przedziału z zapytania
...
cin >> zapytania;

for (int z = 0; z < zapytania; z++) {
    cin >> pocz >> kon;

    cout << sumy[kon]-sumy[pocz-1]<< endl;
}
```

Teraz odpowiadamy w na zapytania w czasie stałym.