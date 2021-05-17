#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long test;
    cin >> test;
    while(test--) {
        long long int floors , rooms , sOff , x;
        cin >> floors >> rooms >> sOff;
        vector<long long int> correct;
        while(floors--) {
            cin >> x;
            correct.push_back(x);
        }
        
        sort(correct.begin() , correct.end());
        
        for(int i=0 ; i<sOff ; i++)
            correct[i] = rooms-correct[i];
            
        cout << accumulate(correct.begin() , correct.end() , 0) << "\n";
    }
    return 0;
}