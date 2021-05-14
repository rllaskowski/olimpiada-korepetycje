#include <iostream>

using namespace std;

// NAJWIEKSZY WSPOLNY DZIELNIK
int nwd(int a, int b) {
    if (a < b) {
        swap(a, b);
    }

    return nwd(a%b, b);
}

// NAJMNIEJSZA WSPOLNA WIELOKROTNOSC
long long nww(int a, int b) {
    return (long long)a*b/nwd(a,b);
}

int main() {


    return 0;
}