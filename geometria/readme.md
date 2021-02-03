# Geometria

### Nierówność trójkąta:

Jeśli oznaczymy boki trójkąta jako **a**,**b**,**c** tak że:
<!-- $$
a >= b >= c
$$ --> 

<div align="center"><img style="background: white;" src="../svg/88fCE5EyTM.svg"></div>

to zachodzi nierówność:

<!-- $$
b+c > a
$$ --> 

<div align="center"><img style="background: white;" src="../svg/jyEiZp1QVi.svg"></div>

Również w drugą stronę - trójkąt można zbudować, tylko jeśli suma krótszych boków jest większa
niż najdłuższy bok.

```cpp

bool czyTrojkat(int a, int b, int c) {
    int suma = a+b+c;
    int najdluzszy = max(a, max(b, c));

    return (suma-najdluzszy) > najdluzszy;
}
```

### Tw. Pitagorasa

Jeśli długości boków trójkąta prostokątnego to **a**,**b**,**c**
oraz **a**,**b** - długości przyprostokątnych, **c** - długość przecwiprostokątnej

to zachodzi 

<!-- $$
a^2+b^2 = c^2
$$ --> 

<div align="center"><img style="background: white;" src="../svg/enAKzc7DOZ.svg"></div>

Innymi suma kwadratów przyprostokątnych jest równa kwadratowi przecwiprostokątnej


<div align="center"><img style="background: white;" src="/zdjecia/tw_pitagorasa.png"></div>

### Odległość między punktami

Znajac współprzędne dwóch punktów:

<!-- $$
\begin{aligned}
P_1 = (x_1; y_1) \\
P_2 = (x_2; y_2) 
\end{aligned}
$$ --> 

<div align="center"><img style="background: white;" src="../svg/e5hHAvLSV3.svg"></div>

Aby obliczyć odległość między punktami tworzymy trójkąt prostokątny podobnie jak na rysunku


<div align="center"><img style="background: white;" src="/zdjecia/odl_punkty.png"></div>

Wprowadźmy oznaczenia
<!-- $$
\begin{aligned}
a = y_2-y_1 \\ 
b = x_2-x_1 \\
\end{aligned}
$$ --> 

<div align="center"><img style="background: white;" src="../svg/2O41L9IIWv.svg"></div>

Teraz korzystając ze tw. Pitagorasa wyliczmy długość przeciwprostokątnej - oznaczmy ją przez **c**
<!-- $$
c^2 = a^2+b^2
$$ --> 

<div align="center"><img style="background: white;" src="../svg/LEjqYbzDad.svg"></div>
więc

<!-- $$
c = \sqrt{a^2+b^2}
$$ --> 

<div align="center"><img style="background: white;" src="../svg/bDRzqb99rm.svg"></div>

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

