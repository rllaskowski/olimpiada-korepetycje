#include <iostream>

using namespace std;

const int M = 1 << 20;

long long tree[M*2];

/*
x - punkt zapytania
*/
long long sum(int x) {
    x += M;
    long long res = 0;

    while (x >= 1) {
        res += tree[x];
        x /= 2;
    }

    return res;
}

/*
<l,r> - przedzial operacji
val - dodawana wartość
v - nr wierzchołka
<a,b> - przedział wierzchołka
*/
void add(int l, int r, int val, int v, int a, int b) {
    if (l <= a && b <= r) {
        tree[v] += val;
    } else {
        int mid = (a+b)/2;
        long long res = 0;

        if (l <= mid) {
            add(l, r, val, v*2, a, mid);
        } 

        if (mid+1 <= r) {
            add(l, r, val, v*2+1, mid+1, b);
        }
    }
}

void add(int l, int r, int val) {
    return add(l, r, val, 1, 0, M-1);
}

int main() {
    add(1, 3, 2);
    add(2, 7, 3);
    add(3, 8, -1);
    add(1, 4, -2);
    
    cout << sum(2);


    return 0;
}