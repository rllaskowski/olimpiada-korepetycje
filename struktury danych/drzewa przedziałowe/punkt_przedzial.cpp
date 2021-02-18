#include <iostream>

using namespace std;

const int M = 1 << 20;

long long tree[M*2];

/*
x - punkt operacji
val - dodawana wartość
*/
void add(int x, int val) {
    x += M;

    while (x >= 1) {
        tree[x] += val;
        x /= 2;
    }
}

/*
<l,r> - przedzial zapytania
v - nr wierzchołka
<a,b> - przedział wierzchołka
*/
long long sum(int l, int r, int v, int a, int b) {
    if (l <= a && b <= r) {
        return tree[v];
    }

    int mid = (a+b)/2;
    long long res = 0;

    if (l <= mid) {
        res = sum(l, r, v*2, a, mid);
    } 

    if (mid+1 <= r) {
        res += sum(l, r, v*2+1, mid+1, b);
    }

    return res;
}

long long sum(int l, int r) {
    return sum(l, r, 1, 0, M-1);
}

int main() {
    add(1, 3);
    add(2, 7);
    add(3, 8);
    add(4, 1);
    
    cout << sum(2, 10);


    return 0;
}