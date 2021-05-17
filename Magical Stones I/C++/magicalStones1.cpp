#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> solve(n);
    for(int i=1;i<=n;i++) solve[i-1] = i;
    vector<int> ar(n);
    for(auto &x:ar) cin>>x;
    int query;
    cin>>query;
    vector<int> qrys(query);
    for(auto &x:qrys) cin>>x;
    unordered_map<int, int> fin;
    fin[n] = 0;
    for(int j=1;j<=n;j++) {
        int we=solve.size();
        for(int i=0;i<we;i++) {
            solve[i] = ar[solve[i]-1];
        }
        set<int> s;
        for(auto x:solve) s.insert(x);
        if(fin.find(s.size()) != fin.end()) break;
        fin[s.size()] = j;
        solve.clear();
        for(auto x:s) solve.push_back(x);
    }
    for(int i = 0;i<query;i++) {
        if (fin.find(qrys[i]) != fin.end()) {
            cout<<fin[qrys[i]]<<'\n';
        } else {
            cout<<-1<<'\n';
        }
    }
    return 0;
}
