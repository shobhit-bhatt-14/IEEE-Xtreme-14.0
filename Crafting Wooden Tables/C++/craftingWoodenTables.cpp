#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int  tWood, nPocket, pWood, wTotal, tables=0;
    cin >> tWood >> nPocket >> pWood >> wTotal;
    while(wTotal/tWood > 0)
    {
        wTotal -= tWood;
        tables++;
        if(ceil(wTotal/pWood)+tables >= nPocket)
            break;
    }
    cout << tables;
    return 0;
}