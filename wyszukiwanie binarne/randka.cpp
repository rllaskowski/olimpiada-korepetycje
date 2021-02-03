#include <iostream>
#include <algorithm>
using namespace std;

int n;

pair<int, string> osoby[200001];


int szukaj (int a) {
    int p = 0;
    int k = n-1;
    int s;

    while (p <= k) {
        s = (p+k)/2;
        if (osoby[s].first < a) {
            p = s + 1;
        } else if (osoby[s].first > a) {
            k = s - 1;
        } else {
            return s;
        }
    }

    return -1;
}


int main() {
    string napis;
    
    int s;
    cin >> n >> s;

    for (int i = 0; i < n; i++) {
        cin >> osoby[i].second >> osoby[i].first;
    }
    
    sort(osoby, osoby+n);

    for (int i = 0; i < n; i++) {
        int pkt = s - osoby[i].first;
        int nr0soby = szukaj(pkt);

        if (nr0soby != -1) {
            cout << osoby[i].second << " " << osoby[nr0soby].second;
            return 0;
        }

    }

    cout << "NIE";
    return 0;
}