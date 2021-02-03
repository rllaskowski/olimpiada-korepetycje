#include <iostream>
#include <algorithm>

using namespace std;

int tablica[1001][1001];

/*
5 6
3 4 2 6 7 6
5 6 4 7 4 3
7 9 4 2 5 2
5 3 8 9 3 2
6 5 7 2 8 1

*/

int main() {
    int n, m;
    int nw = 0;
    int w = 0;
    cin >> n >> m;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin >> tablica[i][j];
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            for(int a = 0;a<n;a++){
                for(int b = 0;b<m;b++){
                    if(a!=i && b!=j){
                        nw = max(tablica[a][b]+tablica[i][j], nw);
                    }
                }
            }
        }
    }
    cout << nw;
    return 0;
}