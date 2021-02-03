#include <iostream>
#include <vector>

using namespace std;

/*
w tej tablicy trzymamy, czy wierzchołek już został odwiedzony
odw[x] == true jeśli wierzchołek o numerze x już został odwiedzony
*/
bool odw[100001];

/*
Tzw. listy sąsiedztwa - tablica vectorow

kraw[x] jest vektorem(czyli rozszerzalna tablicą), w którym
trzymane są wszystkie numery wierzchołków, do których da się dojść
z wierzchołka x 
*/
vector<int> kraw[100001];

void dfs(int v) {
    cout << "Jestem w wierzchołku " << v << endl;

    /* pęta foreach - przydatna, gdy chcemy przejrzeć wszystkie elementy vectora */
    for (int x : kraw[v]) {
        /* x jest numerem pewnego wierzchołka, który jest na liście sąsiedztwa
        wierzchołka v. Zatem istnieje krawędź v->x */

        if (!odw[x]) {
            /* Jeśli wierzchołek x nie jest odwiedzony - wejdźmy do niego 
            Wykonujemy to za pomocą wywołania dfs podając x w argumencie jako wierzchołek */
            dfs(x);
        }
    }

    /* Zakończenie funkcji jest równoważne wyjściu z wierzchołka,
    w którym aktualnie jesteśmy / wrócenie do wierzchołka, z którego przyszliśmy */
}

int main() {
    /* 
    n - ilość wierzchołków
    m - ilość krawędzi
    */
    int n, m;
    cin >> n >> m;

    int a, b;
    for (int i = 0; i < m; i++) {
        /* wczytanie wierzchołków połączonych krawędzią */
        cin >> a >> b;

        /* 
        Do krawędzi wierzchołka o numerze a dodajemy wierzchołek o numerze b
        oraz na odwrót.
        UWAGA! jeśli graf ma być nieskierowany, dodajemy tylko krawędź w jedną stronę!
        */
        kraw[a].push_back(b);
        kraw[b].push_back(a);
    }

    /* Rozpocznij przeszukiwanie w głąb od wierzchołka o numerze 1 */
    dfs(1);

    return 0;
}