#include<bits/stdc++.h>
using namespace std;

int main() {
    int n , costB , costP , b , p , black=0 , pink=0;
    cin >> n >> costB >> costP;
    
    while(n--) {
        cin >> b >> p;
        black += b;
        pink += p;
    }
    
    b = black;
    p = pink;
    
    black /= 10;
    pink /= 10;
    
    b%10 ? (costB *= (black+1)) : (costB *= black) ;
    p%10 ? (costP *= (pink+1)) : (costP *= pink) ;
    
    cout << costB+costP;
    return 0;
}