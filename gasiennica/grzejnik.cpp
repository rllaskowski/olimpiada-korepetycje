#include <iostream>


using namespace std;

int tab[1000000];

int main() {
    int n, K;
    int w = 1000000000;
    bool wyn = false;
    
    cin >> n >> K;
    for(int i = 0;i<n;i++){
        cin >> tab[i];
    }
    int p = 0;
    int k = 0;
    int s = 0;
    while(p <= n){
        s += tab[p];
        while(s-tab[k]>=K){
            s-=tab[k];
            k++;
        }
        if(s>=K){
            if(p-k < w){
                w = p-k+1;
                wyn = true;
            }
        }
        p++;
    }
    if(wyn){
        cout << w;
    }else{
        cout << "NIE";
    }
    return 0;
}