#include <iostream>
#include <cmath>

using namespace std;

int odleglosc(int x1, int y1, int x2, int y2) {
    int a = y2 - y1;
    int b = x2 - x1;
    return (a*a+b*b);
}

int main() {
    int n;
    int m;
    cin >> n;
    cin >> m;
    int x;
    int y;
    int r;
    cin >> x >> y >> r;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if(odleglosc(x, y, i, j) <= r*r){
                cout << "#";
            }else{
                cout << '.';
            }
        }
        cout << endl;
    }
}