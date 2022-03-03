#include <iostream>
#include <tuple>
#include <algorithm>
#include <vector>

using namespace std;

int p[1000001];
int r[1000001];
// krawędź to krotka długości 3 - waga i łaczone wierzchołki
vector<tuple<int, int, int>> edges;


int find(int x) {
    if (p[x] == 0) {
        return x;
    }
    return (p[x] = find(p[x]));
}


// zwraca true jeśli udalo się połączyć zbiory
// lub false jeśli elementy były już w tym samym zbiorze
bool uni(int a, int b) {
    int repr_a = find(a);
    int repr_b = find(b);

    if (repr_a == repr_b) {
        return false;
    }

    if (r[repr_a] < r[repr_b]) {
        swap(repr_a, repr_b);
    }

    r[repr_a] += r[repr_b];
    p[repr_b] = repr_a;

    return true;
}



int main() {
    int n, m, a, b, c;

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        edges.push_back(make_tuple(c, a, b));
    }

    int tree_size = 1;
    int mdr = 0;

    sort(edges.begin(), edges.end());


    for (auto edge : edges) {
        int weight = get<0>(edge);
        int u = get<1>(edge);
        int v = get<2>(edge);

        if (uni(u, v)) {
            // wierzchołki nie były w tym samym zbiorze
            // do minimalnego drzewa rozpinającego 
            // dodajemy wartość nowej krawędzi
            mdr += c;
            tree_size += 1;

            if (tree_size == n) {
                // utworzono już całe drzewo
                // nie ma co dalej liczyć
                break;
            }
        }   
    }

    if (tree_size != n) {
        // wejściowy graf nie był spójny i nie udało się 
        // utworzyć minimalnego drzewa rozpinającego
        cout << "NIE" << endl;
    }

    cout << mdr;

    return 0;
}