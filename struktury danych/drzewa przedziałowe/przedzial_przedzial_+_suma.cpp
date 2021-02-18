#include <iostream>

using namespace std;

const int M = 1 << 20;

/*
S - suma wartosci w poddrzewie wierzchołka
s - wartość dodana na przedziale wierzchołka
*/
typedef struct {
    long long S;
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
        tree[v].S += val*(b-a+1);
    } else {
        int mid = (a+b)/2;

        if (l <= mid) {
            add(l, r, val, v*2, a, mid);
        } 

        if (mid+1 <= r) {
            add(l, r, val, v*2+1, mid+1, b);
        }

        tree[v].S = tree[v*2].S+tree[v*2+1].S+tree[v].s*(b-a+1);
    }
}

void add(int l, int r, int val) {
    return add(l, r, val, 1, 0, M-1);
}

/*
<l,r> - przedzial zapytania
v - nr wierzchołka
<a,b> - przedział wierzchołka
S - suma wartości 's' na sciezce do korzenia
*/
long long sum(int l, int r, int v, int a, int b, int S) {
    if (l <= a && b <= r) {
        return tree[v].S+(b-a+1)*S;
    } else {
        int mid = (a+b)/2;
        long long res = 0;

        if (l <= mid) {
            res = sum(l, r, v*2, a, mid, S+tree[v].s);
        } 

        if (mid+1 <= r) {
            res += sum(l, r, v*2+1, mid+1, b, S+tree[v].s);
        }
        return res;
    }
}

long long sum(int l, int r) {
    return sum(l, r, 1, 0, M-1, 0);
}

int main() {
    add(1, 5, 2);
    add(2, 4, 7);

    
    cout << sum(1, 2);


    return 0;
}