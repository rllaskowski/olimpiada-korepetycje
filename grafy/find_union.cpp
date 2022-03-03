#include <iostream>

using namespace std;

// p[x] - bezpośredni ojciec wierzchołka x
int p[1000001];

// r[x] - wielkość zbioru, ktorego reprezentantem jest x
int r[1000001];

int find(int x) {
    if (p[x] == 0) {
        // wartość 0 oznacza, że wierzchołek
        // sam jest swoim ojcem. Dzieki temu unikamy ustawiania na początku
        // wykonania algorytmu p[x] = x dla każdego x
        return x;
    }
    
    // rekurencyjne szukanie reprezentanta
    int repr = find(p[x]);
    // przepięcie krawędzi bezpośrednio do reprezentanta
    p[x] = repr;

    return repr;
}

// niestety nazwa union jest słowem kluczowym w cpp ;)
void uni(int a, int b) {
    // znajdujemy reprezentatów zbiorów, które chcemy połączyć
    int repr_a = find(a);
    int repr_b = find(b);

    if (repr_a == repr_b) {
        // a i b były już w tym samym zbiorze
        return;
    }

    if (r[repr_a] < r[repr_b]) {
        // dla ułatwienia niech rank_a będzie
        // reprezentantem większego zbioru
        swap(repr_a, repr_b);
    }

    // licznośc zbioru reprezentowanego przez repr_a się zwiększa
    // o liczność zbioru reprezentowanego przez repr_b
    r[repr_a] += r[repr_b];

    // łączymy oba zbiory
    // ich reprezentantem jest repr_a
    p[repr_b] = repr_a;
}



int main() {
    int n, q, a, b;
    char op;
    
    cin >> n >> q;

    for (int i = 0; i < q; i++) {
        cin >> op >> a >> b;
        if (op == 'U') {
            // łączymy zbiory, w których znajdują się a i b
            uni(a, b);
        } else if (op == 'Q') {
            // czy a i b są w tym samym zbiorze?
            if (find(a) == find(b)) {
                cout << "TAK" << endl;
            } else {
                cout << "NIE" << endl;
            }
        }
    }

    return 0;
}