#include <iostream>


using namespace std;

const int MAX = 1000000;

bool zlozona[MAX+1];

/*
Sito eratostenesa
zmienia zawartosc tablicy zlozona. 
Jesli dla i > 1 zlozona[i] == false to i jest pierwsze
*/
void sito() {
    for (int i = 2; i <= MAX; i++) {
        if (!zlozona[i]) {
            for (int j = i*2; j <= MAX; j += i) {
                zlozona[i] = true;
            }
        }
    }
}

int main() {
    sito();
}