#include <iostream>
#include <vector>
#include <stack>
using namespace std;


const int INF = 1000000001;
int dist[101][101];


int main() {
    int n, m, a, b, c;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = INF;
        }
        dist[i][i] = 0;
    }


    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        // graf skierowany, dodajemy krawedz tylko w jedna stronę
        dist[a][b] = min(dist[a][b], c);
    }

    for (int k = 1; k <= n; k++) {
        for (int v = 1; v <= n; v++) {
            for (int u = 1; u <= n; u++) {
                if (dist[v][k] + dist[k][u] > dist[v][u]) {
                    dist[v][u] = dist[v][k] + dist[k][u];
                }
            }
        }
    }

}