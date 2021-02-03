# Struktury danych w C++

## Mapy

Aby skorzystać z mapy w C++ dodajemy do programu bibliotekę `map`

```cpp
#include <map>
```
### Mapy a tablice
Klasyczne tablice w C++ mają z góry określoną, stałą wielkość oraz pozwalają na korzystanie tylko z indeksów liczbowych.
Ze względu na swój ograniczony rozmiar, odniesienie się do za dużych indeksów poskutkuje błądem wykonania programu.

```cpp
int tab[3000];

// poprawne ponieważ 222 < 3000
tab[222] = 4; 

// Błąd ponieważ 40124 > 3000
tab[40124] = 10;

// Błąd ponieważ w tablicy indeksujemy elementy od 0,
// zatem ostatni element w tej tablicy ma indeks 2999
tab[3000] = 9;

// Błąd ponieważ indeksami w tablicy są 
// wyłącznie wartości liczbowe
tab["Napis"] = 10;
```

Korzystanie z mapy znosi oba ograniczenia. Tworząc mapę możemy zdecydować jakim typem będzie ona indeksowana, oraz
jaki będzie typ trzymanych wartości. Wielkość mapy zmienia się również dynamicznie w trakcie działania programu.

```cpp
// Tworzymy mapę indeksowaną przez int, która trzyma zmienne typu string
map<int, string> miejsce;

miejsce[1] = "Oskar";

// Świetnie! możemy korzystać z naprawdę dużych indeksów
miejsce[12312411] = "Maciej";

// A nawet z indeksów ujemnych! 
miejsce[-1233] = "Bartosz";

// Błąd... indeksy stworzonej przez nas mapy mają być typu int!
miejsce["Ala"] = "Błażej"

// Stwórzmy tablicę indeksowaną przez typ string, trzymającą wartości typu int
map<string, int> ocena;

// Teraz jest dobrze.
ocena["Ala"] = 5;

// A teraz mapa indeksowana przez string, trzymająca zmienne typu string
map<string, string> kolega;

kolega["Andrzej"] = "Maciej";
```

Pamiętajmy jednak, że korzystanie z map zamiast tablic, będzie kosztuje nas dłuższym czasem działania. Jedna operacja na mapie(znalezienie szukanego elementu) wykonuje się w czasie logarytmicznym od ilości elementów w mapie. 
Nie nadużywajmy ich jeśli są niepotrzebne, a rozwiązanie da się zapisać za pomocą zwykłych tablic.

## Zbiory

Aby skorzystać z zbiorów w C++ dodajemy do programu bibliotekę `set`

```cpp
#include <set>
```

Zbiór(**ang. set**) jest kolejną strukturą w C++, która w przeciwieństwie do tablic, nie posiada stałego rozmiaru.
Najważniejszymi funkcjami z jakich będziemy korzystali, jest dodawanie do niego nowych wartości, sprawdzanie czy jakaś wartość już w nim występuje lub wzięcie najmniejszej wartości ze zbioru.
Ważną rzeczą w zbiorach jest to, że każda wartość występuje w nim dokładnie raz. Dodanie drugi raz tej samej wartości do zbioru nie powoduje zmiany.


```cpp
// Tworzymy nowy zbiór trzymający wartości typu int
set<int> zbior;

// Do zbioru możemy dodawać nowe wartości funkcją insert()
zbior.insert(3);
zbior.insert(5);
zbior.insert(10);

// Ta instrukcja nie będzie miala wpływu na nasz zbiór, ponieważ zawiera on już wartość 5
zbior.insert(5);

// Błąd! Nasz zbiór trzyma zmienne typu int
zbiór.insert("napis");

// Możemy sprawdzić jaka jest wielkość naszego zbioru funkcją size()
if (zbior.size() == 3) {
    cout << "Ten tekst zostanie wypisany, ponieważ do zbioru należą 3 wartości: 3, 5, 10";
}


// Sprawdzenie czy wartość jest w zbiorze
if (zbior.count(5) > 0) {
    cout << "Zbiór zawiera wartość 5";
}

```