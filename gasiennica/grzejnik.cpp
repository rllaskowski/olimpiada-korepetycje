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
    int kon = 0; // koniec gąsiennicy
    int suma = 0; // suma liczb na gąsiennicy: suma liczb w tablicy na przedziale <kon, pocz>

    while (pocz <= n) {
        /* Głowa gąsiennicy weszła na nową liczbę - dodajemy ją do sumy */
        suma += tab[pocz];
       
        /* Zauważmy, że chcemy aby suma liczb na gąsiennicy była większa lub równa K, ale również gąsiennica powinna być jak najkrótsza.
        (wynika to z treści zadania: chcemy poznać długość najkrótszego przedziału, na którym suma jest >= K)
        Zatem jeśli suma > K to chcielibyśmy gąsiennicę skracać, przesuwając jej koniec do przodu(usuwając ostanti element). 
        Robimy to dopóki usunięcie ostatniego elementu gąsiennicy nie sprawi, że suma zejdzie poniżej K.

        Warunek pętli przeczytamy tak: dopóki można skrócić gąsiennicę o jej koniec, tak aby suma nie zeszła poniżej K */
        while (suma-tab[kon] >= K) {
            suma -= tab[kon];
            kon++;
        }


        /* Skróciliśmy gąsiennicę maksymalnie jak się dało. Sprawdzamy teraz czy suma jest odpowiednio duża.
        Jeśli jest to próbujemy poprawić wynik aktualną długością gąsiennicy: pocz-kon+1 */
        if (suma >= K) { 
            minimalnaDlugosc = min(minimalnaDlugosc, pocz-kon+1);
            znalezionoWynik = true;
        }
        
        pocz++;
    }

    if (znalezionoWynik) {
        cout << minimalnaDlugosc;
    } else {
        cout << "NIE";
    }
    return 0;
}