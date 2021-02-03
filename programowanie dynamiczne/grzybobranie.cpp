#include <iostream>
using namespace std;


int grzyby[101][101];
int wyniki[101][101];

int main() {
    int n;
    int m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grzyby[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            wyniki[i][j] = grzyby[i][j] + max(wyniki[i][j-1], wyniki[i-1][j]);
        }
    }

    cout << wyniki[n][m] << endl;
    return 0;
}
