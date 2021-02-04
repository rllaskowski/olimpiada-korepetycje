# STL - Standard Template Library
- [Struktury danych w STL](/STL%20-%20Standard%20Template%20Library/readme.md#struktury-danych)
    - [Para](/STL%20-%20Standard%20Template%20Library/readme.md#mapatablica-asosjacyjna-słownik)
     - [Kolejka](/STL%20-%20Standard%20Template%20Library/readme.md#Kolejka)
    - [Stos](/STL%20-%20Standard%20Template%20Library/readme.md#Stos)
    - [Vector](/STL%20-%20Standard%20Template%20Library#vector)
    - [Mapa](/STL%20-%20Standard%20Template%20Library/readme.md#mapatablica-asosjacyjna-słownik)
    - [Zbiór](/STL%20-%20Standard%20Template%20Library/readme.md#zbiór)
- [Przydatne funkcje](/STL%20-%20Standard%20Template%20Library/readme.md#przydatne-funkcje)

## Struktury danych

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
### Kolejka
Aby skorzystać ze stosu w C++ dodajemy do programu bibliotekę `queue`

```cpp
#include <queue>
```
[Opis działania kolejki](/struktury%20danych/readme.md#Kolejka)

```cpp
/* stworzenie kolejki trzymającej stringi */
queue<string> kolejka;

/* dodaj na koniec kolejki wartości "Jan", "Andrzej", "Latawiec" */
kolejka.push("Jan");
kolejka.push("Andrzej");
kolejka.push("Latawiec");

/* wypisze 3 */
cout << kolejka.size() << endl;

/*
Błąd! Stworzona kolejka trzyma stringi
kolejka.push(123);
*/

/* wypisz pierwszą wartość na kolejce - "Jan" */
cout << kolejka.front();


if (!kolejka.empty()) {
    cout << "Kolejka nie jest pusta" << endl;
}

/* Zdejmij pierwszą wartość z kolejki x3 */
kolejka.pop();
kolejka.pop();
kolejka.pop()

/*
Błąd! Na kolejka nie ma już elementów 
kolejka.pop();
*/
```
Szczegółowa dokumentacja:
  - [Kolejka na Cpp0x](https://cpp0x.pl/kursy/Kurs-STL-C++/Adapter-kolejki-std-queue/117)

  - [Kolejka na cplusplus](https://www.cplusplus.com/reference/queue/queue/) 


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

/* Zdejmij ostatnią wartość ze stosu x2 */
stos.pop();
stos.pop();

if (stos.empty()) {
    cout << "Stos jest pusty" << endl;
}

/*
Błąd! Na stosie nie ma już elementów 
stos.pop();
*/
```
Szczegółowa dokumentacja:
  - [Stos na Cpp0x](https://cpp0x.pl/kursy/Kurs-STL-C++/Adapter-stosu-std-stack/116)

  - [Stos na cplusplus](https://www.cplusplus.com/reference/stack/stack/) 

### Vector
Aby skorzystać z vectorów w C++ dodajemy do programu bibliotekę `vector`

```cpp
#include <vector>
```

Vector to nic innego jak tablica o dynamicznie zmieniającym się, w trakcie działania programu, rozmiarze. 

```cpp
/* Tworzymy pusty vector trzymający inty */
vector<int> wektor;
/* wektor = {} */

/* Dodaj na koniec vectora wartości 82, 3, 4 automatycznie zwiększając jego rozmiar */
wektor.push_back(82);
wektor.push_back(6);
wektor.push_back(4);
/* wektor = {82, 6, 4}  */

/* wypisze 3 */
cout << wektor.size() << endl();

/* Wypisze 6 */
cout << wektor[1] << endl;

/* Zmienia rozmiar vectora na 5 */
wektor.resize(5);
/* wektor = {82, 6, 4, 0, 0} */

/* 
Błąd! wektor ma rozmiar 5
cout << wektor[5];
*/

/*
Błąd! Stworzony vector trzyma inty
wektor[2] = "Abc";
*/

wektor[4] = 123;
/* wektor = {82, 6, 4, 0, 123} */

/* Zmień rozmiar vectora, a nowe miejsca wypełnij wartością -3 */
wektor.resize(7, -3);
/* wektor = {82, 6, 4, 0, 123, -3, -3} */

/* pętla foreach
przydatna do przeglądania po kolei wartości vectora 
wypisze: 82, 6, 4, 0, 123, -3, -3
*/
for (int x : wektor) {
    cout << x << ", ";
}

/* to samo za pomocą zwykłego fora */
for (int i = 0; i < wektor.size(); i++) {
    cout << wektor[i] << ", ";
}

/* Tworzy vector stringów z początkowym rozmiarem 1000 */
vector<string> duzyWektor(1000);
/* duzyWektor = {"", "", "",...""} */

duzyWektor[2] = "Tekst";
/* duzyWektor = {"", "", "Tekst",...""} */

/* Możemy też zmniejszyć rozmiar vectora. Ostatnie elementy usuną się */
duzyWektor.resize(2);
/* duzyWektor = {"", ""}
```

Szczegółowa dokumentacja:
  - [Vector na Cpp0x](https://cpp0x.pl/dokumentacja/standard-C++/vector/819)

  - [Vector na cplusplus](https://www.cplusplus.com/reference/vector/vector/) 
### Mapa(tablica asosjacyjna, słownik)

Aby skorzystać z mapy w C++ dodajemy do programu bibliotekę `map`

```cpp
#include <map>
```
#### Mapa a tablica

Klasyczne tablice w C++ mają stałą w trakcie działania programu rozmiar oraz pozwalają na korzystanie tylko z indeksów liczbowych. Dodatkowo jeśli rozmiar tablicy to **R**, to zakres indeksów, z których możemy korzystać to **<0, R-1>**

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

Ograniczenia w postaci stałego rozmiaru możemy się pozbyć za pomocą vectorów. Natomiast wciąż pozostaje problem dotyczący zakresu indeksów oraz ich typów. 
Korzystanie z mapy znosi oba ograniczenia. Tworząc mapę możemy zdecydować jakim typem będzie ona indeksowana, oraz
jaki będzie typ trzymanych wartości. Wielkość mapy zmienia się również dynamicznie w trakcie działania programu przy dodawaniu do niej nowego klucza/indeksu.

```cpp
/*
Stworzenie mapy indeksowanej przez int, 
która trzyma wartości typu string

int - klucz/indeks
string - wartość
*/
map<int, string> mapa;
/* mapa = {} */

mapa[1] = "Oskar";
/* mapa = { 1: "Oskar" } */

/* Możemy korzystać z naprawdę dużych indeksów */
mapa[12312411] = "Maciej";
/*
mapa = {
    1: "Oskar",
    12312411: "Maciej"
}
*/

/* A nawet z indeksów ujemnych */ 
mapa[-1233] = "Bartosz";
/*
mapa = {
    -1233: "Bartosz",
    1: "Oskar",
    12312411: "Maciej"
}
*/

/*
Błąd! indeksy stworzonej przez nas mapy mają być typu int 
mapa["Ala"] = "Błażej"
*/

/* Stwórzmy mapę indeksowaną przez string, trzymającą wartości typu int */
map<string, int> ocena;
/* ocena = {} */

/* Teraz jest dobrze. */
ocena["Ala"] = 5;
/* ocena = { "Ala": 5 } */

/* A teraz mapa indeksowana przez string, trzymająca zmienne typu string */
map<string, string> kolega;
/* kolega = {} */

kolega["Andrzej"] = "Maciej";
/* kolega = { "Andrzej": "Maciej" } */

```

Pamiętajmy jednak, że korzystanie z map zamiast tablic, kosztuje nas dłuższym czasem działania. Jedna operacja na mapie(znalezienie szukanego elementu klucz->wartość) wykonuje się w czasie logarytmicznym od ilości wstawionych do mapy kluczy.
Nie nadużywajmy ich jeśli są niepotrzebne, a rozwiązanie da się zapisać za pomocą zwykłych tablic.

Szczegółowa dokumentacja:
  - [Mapa na Cpp0x](https://cpp0x.pl/kursy/Kurs-C++/Poziom-5/Kontenery-asocjacyjne-std-set-i-std-map/589)

  - [Mapa na cplusplus](https://www.cplusplus.com/reference/map/map/) 
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
/* zbior = {} */

/* Dodaj do zbioru wartości 3, 10, 5 */
zbior.insert(3);
zbior.insert(10);
zbior.insert(5);
/* zbior = {3, 5, 10} */

/* Ta instrukcja nie będzie miala wpływu na nasz zbiór, ponieważ zawiera on już wartość 5 */
zbior.insert(5);
/* zbior = {3, 5, 10} */

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
/* zbior = {3, 10} */

/* Wzięcie najmniejszej wartości = 3 */
int najmniejsza = *zbior.begin();

/* Wzięcie największej wartości = 10 */
int największa = *zbior.rbegin();

```
Operacje dodawania, usuwania i liczenia występowań wartości w zbiorze są wykonywane w czasie logarytmicznym od wielkości zbioru.

Szczegółowa dokumentacja:
  - [Set na Cpp0x](https://cpp0x.pl/kursy/Kurs-C++/Poziom-5/Kontenery-asocjacyjne-std-set-i-std-map/589)

  - [Set na cplusplus](https://www.cplusplus.com/reference/set/set/) 
  
## Przydatne funkcje