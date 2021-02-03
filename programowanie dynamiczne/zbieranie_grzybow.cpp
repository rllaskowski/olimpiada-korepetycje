#include <iostream>
#include <algorithm>

using namespace std;

bool p[50000];
bool l[50000];
int wyn[50001][101];

int main() {
    int n, k, a, b, x;
    cin >> n >> k;
    cin >> a >> b;
    for(int i = 0;i<a;i++){
        cin >> x;
        l[x]=true;
    }
    for(int i = 0;i<b;i++){
        cin >> x;
        p[x]=true;
    }
    for(int i = 1;i<=n;i++){
        for(int j = 0;j<=k;j++){
            int grzyb = 0;
            if(j % 2 == 0 && l[i]){
                grzyb++;
            } else if(j & 2 != 0 && p[i]){
                grzyb++;
            }
            /*
            To jest przyjscie z poprzedniego segmentu
            z tej samej strony plotu
            */
            wyn[i][j]=wyn[i-1][j] + grzyb;
        }

        for(int j = 0;j<=k;j++){
            int grzyb = 0;
            if(j % 2 == 0 && l[i]){
                grzyb++;
                l[i]=false;
            }else if(j & 2 != 0 && p[i]){
                grzyb++;
                p[i]=false;
            }

            if (j > 0) {
            /*
            Przyjscie z tego samego segmentu z drugiej
            strony plotu przy pomocy wykonania jednego skoku
            */
                wyn[i][j] = max(wyn[i][j], wyn[i][j-1] + grzyb) ;
            }
        }
    }

    cout << max(wyn[n][k], wyn[n][k-1]);
    return 0;
}