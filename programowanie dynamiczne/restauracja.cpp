#include <iostream>

using namespace std;

int cena[1000001];
int kalorie[1000001];

int main(){
    int n, a, b;
    cin >> n >> a >> b;
    for(int i = 0;i<n;i++){
        cin >> kalorie[i];
    }
    for(int i = 0;i<n;i++){
        cin >> cena[i];
    }

    long long najmniej = 1000000000000000LL;
    long long najwiecej = 0;
    bool c = false;
    long long sumak = 0;
    long long sumac = 0;
    int k = 0; // pozycja konca gasiennicy

    for (int p=0; p < n; p++) {
        // p pozycja glowy gasiennicy
        sumak+=kalorie[p];
        sumac+=cena[p];
        while(sumak-kalorie[k] >= a){
            k++;
            sumak -= kalorie[k-1];
            sumac -= cena[k-1];
        }
        if(sumak>=a && sumak<=b && sumac<najmniej){
            najmniej = sumac;
            c = true;
        }
    }
    sumak = 0;
    sumac = 0;
    k = 0;
    for(int p=0;p<n;p++){
        sumak+=kalorie[p];
        sumac+=cena[p];
        while(sumak > b){
            k++;
            sumak -= kalorie[k-1];
            sumac -= cena[k-1];
        }
        if(sumak >= a){
            najwiecej = sumac;
            c = true;
        }
    }

    if(c){
        cout << najmniej << " " << najwiecej;
    }else{
        cout << "NIE";
    }
    return 0;
}
