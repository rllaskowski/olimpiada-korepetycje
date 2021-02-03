#include <iostream>

using namespace std;

int ileRoznic[2000001];

int main() {
    int n;
    long long w = 0;
    char a;
    int roznica = 1000000;
    ileRoznic[roznica] = 1;
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> a;
        if(a == 'J'){
            roznica++;
        }else{
            roznica--;
        }

        /*
            Chcemy policzyc ile spojnych przedzialow konczy
            sie w tym miejscu i roznica jest 1

            w takim razie musimy odciac jakis fragment z poczatku

            Teraz roznica jest "r", w takim razie musimy odciac
            fragment na ktorym roznica byla (roznica-1)
            Ile ich bylo? to mamy zapisane w tab[roznica-1]
        */
       ileRoznic[roznica]++;
       w+=ileRoznic[roznica-1];
    }
    cout << w;
    return 0;
}