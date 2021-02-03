#include <iostream>

using namespace std;

/*
9 20
9 = 3*3
20 = 2*2*5

9 60
60 9
6  9
9  6
3  3
0  3
3  0

*/

int nwd(int a, int b) {
    if (a < b) {
        swap(a, b);
    }
    while (b != 0) {
        a = a % b;
        swap (a, b);    
    }
    return a;
}

int main() {
    int n;
    int a;
    int b;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        if (nwd(a, b) == 1) {
            cout << "TAK" << endl;
        } else {
            cout << "NIE" << endl;
        }
    }

    return 0;
}