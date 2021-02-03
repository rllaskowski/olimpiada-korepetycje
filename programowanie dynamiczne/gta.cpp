#include <iostream>

using namespace std;

int ulice[16][16];

int main() {
    int n;
    cin >> n;

    ulice[0][1] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ulice[i][j] = ulice[i][j-1] + ulice[i-1][j];
        }
    }

    cout << ulice[n][n] << endl;

    return 0;
}