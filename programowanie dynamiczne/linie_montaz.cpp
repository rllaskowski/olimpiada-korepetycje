#include <iostream>


using namespace std;

int czasW[2][2000000]; // czas wyjscia ze stacji
int czas[2][2000000]; // czas czekania na stacji
int przejscia[2][2000000]; // czas przejscia ze stacji i do i+1

int main() {
    int n;
    cin >> n;
    
    for (int l = 0; l < 2; l++) {
        for (int s = 0; s < n; s++) {
            cin >> czas[l][s];
        }
        for (int p = 0; p < n-1; p++) {
            cin >> przejscia[l][p];
        }
    }
    
    czasW[0][0] = czas[0][0];
    czasW[1][0] = czas[1][0];


    for (int s = 1; s < n; s++) {
        // znamy czasy wyjscia dla stacji s-1
        // dla obu lini
        czasW[0][s] = min(czasW[0][s-1], czasW[1][s-1]+przejscia[1][s-1])+czas[0][s];
        czasW[1][s] = min(czasW[1][s-1], czasW[0][s-1]+przejscia[0][s-1])+czas[1][s];
    }

    cout << min(czasW[0][n-1], czasW[1][n-1]);

    return 0;
}
