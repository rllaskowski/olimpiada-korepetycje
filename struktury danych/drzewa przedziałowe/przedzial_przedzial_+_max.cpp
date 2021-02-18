#include <iostream>

using namespace std;

const int M = 1 << 20;

/*
m - maksymalna wartosc w poddrzewie wierzchołka
s - wartość dodana na przedziale wierzchołka
*/
typedef struct {
    long long m;
    long long s;
} node;

node tree[M*2];

/*
<l,r> - przedzial operacji
val - dodawana wartość
v - nr wierzchołka
<a,b> - przedział wierzchołka
*/
void add(int l, int r, int val, int v, int a, int b) {
    if (l <= a && b <= r) {
        tree[v].s += val;
        tree[v].m += val;
    } else {
        int mid = (a+b)/2;

        if (l <= mid) {
            add(l, r, val, v*2, a, mid);
        } 

        if (mid+1 <= r) {
            add(l, r, val, v*2+1, mid+1, b);
        }

        tree[v].m = max(tree[v*2].m, tree[v*2+1].m) + tree[v].s;
    }
}

void add(int l, int r, int val) {
    return add(l, r, val, 1, 0, M-1);
}

/*
<l,r> - przedzial zapytania
v - nr wierzchołka
<a,b> - przedział wierzchołka
*/
long long getMax(int l, int r, int v, int a, int b) {
    if (l <= a && b <= r) {
        return tree[v].m;
    } else {
        int mid = (a+b)/2;
        long long res = 0;

        if (l <= mid) {
            res = getMax(l, r, v*2, a, mid);
        } 

        if (mid+1 <= r) {
            res = max(res, getMax(l, r, v*2+1, mid+1, b));
        }
        return res;
    }
}

long long getMax(int l, int r) {
    return getMax(l, r, 1, 0, M-1);
}

int main() {
    add(1, 3, 2);
    add(2, 7, 3);
    add(2, 6, 5);
    add(3, 8, -1);
    add(1, 4, -2);
    
    cout << getMax(1, 10);


    return 0;
}