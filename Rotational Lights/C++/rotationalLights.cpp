#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int n,t,count=0;
    cin>>n>>t;
    string str;
    
    for (long long int i=0; i<t; i++)
        str.push_back('F');
        
    int p;
    while(cin>>p)
        str[p]='T';
    
    string org(str.begin(),str.end());
    
    for (long long int i=0; i<t; i++)
    {
        str.insert(str.begin()+0,str[str.size()-1]);
        str.erase(str.size()-1,1);
        
        if(org==str)
            break;
        count++;
    }
    
    cout<<count;
    return 0;
}
