# Geometria

## Nierówność trójkąta:

Jeśli oznaczymy boki trójkąta jako a,b,c - tak że 
``` 
a >= b >= c
```
to zachodzi nierówność
```math
b+c > a
```
Również w drugą stronę - trójkąt można zbudować, tylko jeśli suma krótszych boków jest większa
niż najdłuższy bok.

```cpp

bool czyTrojkat(int a, int b, int c) {
    int suma = a+b+c;
    int najdluzszy = max(a, max(b, c));

    return (suma-najdluzszy) > najdluzszy;
}
```
[Nierówność trójkąta](http://oblicz.com.pl/nierownosc-trojkata/)

## Tw. Pitagorasa

Jeśli długości boków trójkąta prostokątnego to a,b,c
oraz a,b - długości przyprostokątnych, c - długość przecwiprostokątnej

to zachodzi 

```
a^2+b^2 = c^2
```

Innymi suma kwadratów przyprostokątnych jest równa kwadratowi przecwiprostokątnej

[Tw. Pitagorasa](https://www.matemaks.pl/twierdzenie-pitagorasa.html)


## Odległość między punktami

Znajac współprzędne dwóch punktów:

(x1, y1) oraz (x2, y2)

możemy obliczyć odległość między tymi punktami korzystając ze wzoru Pitagorasa:


```cpp
float odlegosc(pair<int, int> p1, pair<int, int p2>) {
    int a = p1.first-p2.first;
    int b = p1.second-p2.second;

    return sqrt(a*a+b*b);
}
```

**UWAGA!**
W zdecydowanej większości zadań, nie jest nam potrzebna dokładna odległość między punktami, tylko informacja, czy ta odległość jest mniejsza/większa/równa jakiejś liczbie(ew. chcemy porównać dwie odległości). W tym celu nie musimy(wręcz nie powinniśmy) wyciągąć pierwiastka w ostatnim kroku. Należy zachować kwadrat odległości i porównać go z kwadratem odpowiedniej liczby:

```cpp

bool czyMniejsza(pair<int, int> p1, pair<int, int p2>, long long odleglosc) {
    /*
    Uwaga - używamy long longów, ponieważ podnosimy te zmienne do kwadratu. 
    Prawdopodobnie te wartości będą za duże na int'a
    */
    long long a = p1.first-p2.first;
    long long b = p1.second-p2.second;

    long long odlKwadrat = a*a+b*b;

    return odlKwadrat < odleglosc*odleglosc;
}
```

Dzięki temu unikamy używania typów zmiennoprzecinkowych: float, double, ...

[Odległość między punktami](https://matematykaszkolna.pl/strona/1248.html)



## Podobieństwo trójkątów

[Do przeczytania](https://www.matemaks.pl/podobienstwo-trojkatow.html)