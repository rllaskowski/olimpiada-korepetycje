#include<iostream>

using namespace std;

int tab[100001];

int pref[21][100001];

int suma(int a, int p, int k){
    return pref[a][k] - pref[a][p-1];
}


int main(){
    int n;
    cin >> n;
    for(int i = 1;i <= n;i ++){
        cin >> tab[i];
        for(int j = 1;j <= 20;j++){
            pref[j][i] = pref[j][i-1];
        }
        pref[tab[i]][i] += 1;
    }
    int m;
    int a;
    int b;
    cin >> m;
    for(int i = 0;i < m;i++){
        cin >> a >> b;

        int maks = 0;
        int ile = 0;

        for(int j = 1;j <= 20;j++){
           if (suma(j, a, b) > maks){
               maks = suma(j, a, b);
               ile = 1;
           } else if (suma(j, a, b) == maks) {
               ile++;
           }
        }
        cout << ile << " ";
        for(int t = 1;t <= 20;t++){
            if (suma(t, a, b) == maks){
                cout << t << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}