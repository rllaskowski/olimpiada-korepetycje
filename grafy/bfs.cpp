#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
odw[x] == true jeśli wierzchołek o numerze x ma już ustawioną odległość
odw[x] == false w przeciwnym przypadku
*/
bool odw[100001];

/*
odl[x] - odleglość x od wierzchołka startowego
*/
int odl[100001];

/* Listy sąsiedztwa */
vector<int> kraw[100001];

void bfs(int s) {
    queue<int> wierz;

    /* dodaj na kolejkę wierzchołek startowy */
    wierz.push(s);
    /* ustaw odległość 0 wierzchołkowi startowemu */
    odl[s] = 0;

    /* dopóki kolejka niepusta */
    while (!wierz.empty()) {
        /* zdejmij z kolejki wierzchołek v */
        int v = wierz.front();
        wierz.pop();

        /* pętla foreach - przydatna do przejrzenia wszystkich
        elemenentów vectora
        
        Dla każdej krawędzi v->x*/
        for (int x : kraw[v]) {
            /* jeśli x nie ma ustawionej odległości */
            if (!odw[x]) {
                /* ustaw x odległość o 1 większą niż odległość v */
                odl[x] = odl[v]+1;
                odw[x] = true;
                /* wstaw x na kolejkę */
                wierz.push(x);
            }
        }
    }
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
        cin >> a >> b;

        kraw[a].push_back(b);
        kraw[b].push_back(a);
    }

    /* Rozpocznij przeszukiwanie wszerz od wierzchołka 1 */
    bfs(1);
    
    for (int i = 1; i <= n; i++) {
        if (odw[i]) {
            cout << i << ": " << odl[i] << endl;
        } else {
            cout << i << ": ----" << endl;
        }
        
    }

    return 0;
}