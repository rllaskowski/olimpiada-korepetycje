# STL - Standard Template Library

## Struktury danych w STL

- [Para](/STL%20-%20Standard%20Template%20Library/readme.md#mapatablica-asosjacyjna-słownik)
- [Stos](/STL%20-%20Standard%20Template%20Library/readme.md#Stos)
- [Mapa](/STL%20-%20Standard%20Template%20Library/readme.md#mapatablica-asosjacyjna-słownik)
- [Zbiór](/STL%20-%20Standard%20Template%20Library/readme.md#zbiór)
### Para
Aby skorzystać ze par w C++ dodajemy do programu bibliotekę `utility`.

```cpp
#include <utility>
```

```cpp
/* Stworzenie pary trzymającej string oraz int */
pair<string, int> ocena;

/* Ustawienie pierwszego elementu pary */
ocena.first = "Jan";

/* Ustawienie drugiego elementu pary */
ocena.second = 5;

/* 
Błąd! Pierwszy element pary trzyma stringa 
ocena.first = 4;
*/

/* make_pair zwraca parę odpowiedniego typu */
ocena = make_pair("Krzyszof", 2);

/* 
Błąd! Przypisanie pary typu <int, string>
do pary typu <string, int>

ocena = make_pair(3, "Jacek");
*/

```

### Stos
Aby skorzystać ze stosu w C++ dodajemy do programu bibliotekę `stack`

```cpp
#include <stack>
```

[Opis działania stosu](/struktury%20danych/readme.md#Stos)

```cpp
/* stworzenie stosu trzymającego inty */
stack<int> stos;

/* dodaj na górę stosu wartości 3, 5 */
stos.push(3);
stos.push(5);

/* wypisze 2 */
cout << stos.size() << endl;

/*
Błąd! Stworzony stos trzyma int'y
stos.push("coś");
*/

/* wypisz ostatnią wartość na stosie - 5 */
cout << stos.top();

if (stos.empty()) {
    cout << "Stos jest pusty" << endl;
}

/* Zdejmij ostatnią wartość ze stosu x2 */
stos.pop();
stos.pop()

/*
Błąd! Na stosie nie ma już elementów 
stos.pop();
*/
```


### Mapa(tablica asosjacyjna, słownik)

Aby skorzystać z mapy w C++ dodajemy do programu bibliotekę `map`

```cpp
#include <map>
```
#### Mapa a tablica

Klasyczne tablice w C++ mają stałą w trakcie działania programu ilość trzymanych wartości oraz pozwalają na korzystanie tylko z indeksów liczbowych. Dodatkowo jeśli rozmiar tablicy to **R**, to zakres indeksów, z których możemy korzystać to **<0, R-1>**

```cpp
int tab[3000];

/* poprawne ponieważ 0 <= 222 < 3000 */
tab[222] = 4; 

/* poprawne ponieważ 0 <= 2999 < 3000 */
tab[2999] = 124; 

/* poprawne ponieważ 0 <= 0 < 3000 */
tab[0] = -15; 

/*
Błąd ponieważ 40124 > 3000
tab[40124] = 10;
*/

/*
Błąd ponieważ w tablicy indeksujemy elementy od 0, zatem ostatni element w tej tablicy ma indeks 2999
tab[3000] = 9;
*/

/*
Błąd ponieważ indeksami w tablicy są 
wyłącznie wartości liczbowe
tab["Napis"] = 10;
*/

/*
Błąd ponieważ indeksami w tablicy są liczby nieujemne
tab[-1] = 10;
*/
```
Korzystanie z mapy znosi oba ograniczenia. Tworząc mapę możemy zdecydować jakim typem będzie ona indeksowana, oraz
jaki będzie typ trzymanych wartości. Wielkość mapy zmienia się również dynamicznie w trakcie działania programu przy dodawaniu do niej nowego klucza/indeksu.

```cpp
/*
Tworzymy mapę indeksowaną przez int, 
która trzyma wartości typu string

int - klucz/indeks
string - wartość
*/
map<int, string> miejsce;

miejsce[1] = "Oskar";

/* Możemy korzystać z naprawdę dużych indeksów */
miejsce[12312411] = "Maciej";

/* A nawet z indeksów ujemnych */ 
miejsce[-1233] = "Bartosz";

/*
Błąd! indeksy stworzonej przez nas mapy mają być typu int 
miejsce["Ala"] = "Błażej"
*/

/* Stwórzmy mapę indeksowaną przez string, trzymającą wartości typu int */
map<string, int> ocena;

/* Teraz jest dobrze. */
ocena["Ala"] = 5;

/* A teraz mapa indeksowana przez string, trzymająca zmienne typu string */
map<string, string> kolega;

kolega["Andrzej"] = "Maciej";
```

Pamiętajmy jednak, że korzystanie z map zamiast tablic, kosztuje nas dłuższym czasem działania. Jedna operacja na mapie(znalezienie szukanego elementu) wykonuje się w czasie logarytmicznym od ilości wstawionych do mapy kluczy.
Nie nadużywajmy ich jeśli są niepotrzebne, a rozwiązanie da się zapisać za pomocą zwykłych tablic.

### Zbiór

Aby skorzystać z zbiorów w C++ dodajemy do programu bibliotekę `set`

```cpp
#include <set>
```

Zbiór(**ang. set**) jest strukturą, która daje nam następujące funkcje: 
- dodanie nowej wartości 
- sprawdzenie czy dana wartość już w nim występuje 
- wzięcie najmniejszej/największej wartości
- ilość róznych dodadnych wartości
- usunięcie wartości
 
Każda wartość w zbiorze występuje w nim dokładnie raz. Dodanie jej drugi raz nie powoduje zmiany.

```cpp
/* Tworzymy nowy zbiór trzymający wartości typu int */
set<int> zbior;

/* Dodaj do zbioru wartości 3, 5, 10 */
zbior.insert(3);
zbior.insert(5);
zbior.insert(10);

/* Ta instrukcja nie będzie miala wpływu na nasz zbiór, ponieważ zawiera on już wartość 5 */
zbior.insert(5);

/* 
Błąd! Nasz zbiór trzyma zmienne typu int
zbiór.insert("napis");
*/

/* Możemy sprawdzić jaka jest wielkość naszego zbioru funkcją size() */
if (zbior.size() == 3) {
    cout << "Ten tekst zostanie wypisany, ponieważ do zbioru należą 3 wartości: 3, 5, 10";
}

/* Sprawdzenie czy wartość jest w zbiorze */
if (zbior.count(5) > 0) {
    cout << "Zbiór zawiera wartość 5";
}

/* Usuń ze zbioru wartość 5 */
zbior.erase(5);

/* Wzięcie najmniejszej wartości */
int najmniejsza = *zbior.begin();

/* Wzięcie największej wartości */
int największa = *zbior.rbegin();

```