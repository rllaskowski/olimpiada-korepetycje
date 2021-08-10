#include <iostream>


using namespace std;

int tab[1000000];

int main() {
    int n, K;
    int minimalnaDlugosc = 1000000000;
    bool znalezionoWynik = false;
    
    cin >> n >> K;
    for(int i = 0;i<n;i++){
        cin >> tab[i];
    }

    int pocz = 0; // początek(głowa gąsiennicy)
    int suma = tab[0]; // suma liczb na gąsiennicy: suma liczb w tablicy na przedziale <kon, pocz>

    // początkowo nasza gąsiennica zawiera liczby z przedziału <0, 0>

    for (int kon = 0; kon < n; kon++) {
        /*
        Gąsiennica znajduje się na przedziale <kon, pocz>
        
        Chcemy rozciągać naszą gąsiennicą do przodu(dodawać do niej nowe liczby z prawej strony)
        dopóki suma znajdujących się na niej liczb jest za mała(warunek suma < K). 
        Uważamy jednak, żeby nie wyjść poza tablicę!(warunek pocz+1 < n)
        */
        while (pocz+1 < n && suma < K) {
            pocz++;
            suma += tab[pocz];
        }

        /* Jeśli suma liczb na gąsiennicy jest odpowiednia, 
        próbujemy poprawić nasz wynik aktualną długością gąsiennicy: pocz-kon+1*/
        if (suma >= K) {
            znalezionoWynik = true;
            minimalnaDlugosc = min(minimalnaDlugosc, pocz-kon+1);
        }

        /* Po każdym przejściu pętli koniec gąsienincy przesuwa się o 1 w prawo(usuwa się ostatni lewy element) */
        suma -= tab[kon];
    }


    if (znalezionoWynik) {
        cout << minimalnaDlugosc;
    } else {
        cout << "NIE";
    }
    return 0;
}