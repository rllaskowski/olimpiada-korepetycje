#include <iostream>

using namespace std;

// zwraca ilosc dzielnikow liczby n
int dzielniki(int n) {
    int wynik = 0;

    for (int i = 1; i*i <= n; i++) {
        if (n % i == 0) {
            wynik += i*i == n? 1 : 2;
        }
    }

    return wynik;
}

bool czyPierwsza(int n) {
    return dzielniki(n) == 2; 
}


int main() {


    return 0;
}