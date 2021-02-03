/**
 * Rozwiązanie zadania Halloween 
 * Podejście wzorcowe - obliczanie sum na przedziale
 * korzystając z sum prefiksowych
**/

#include <iostream>
using namespace std;

int cukierki[100001];

int main() { 
    int t, n;
    int pocz, kon;
    int suma;

    cin >> t;
    cin >> n;
    
    for (int i = 1; i <= n; i++){
        cin >> cukierki[i];
        
        cukierki[i] += cukierki[i-1];
    }    

    for(int i = 0 ; i < t ; i++){
        cin >> pocz;
        cin >> kon;
        
        suma = 0;
       
        cout << cukierki[kon]-cukierki[pocz-1] << endl;
    }
    
    return 0;
}