#include <bits/stdc++.h>
using namespace std;

bool canChange(std::string
  const & strA, std::string
  const & strB) {
  bool single_mismatch = false;
  if (strA.size() == strB.size()) {
    typedef std::string::const_iterator ci;
    typedef std::pair < ci, ci > mismatch_result;

    ci begA(strA.begin()), endA(strA.end());

    mismatch_result result = std::mismatch(begA, endA, strB.begin());

    if (result.first != endA)
    {
      std::advance(result.first, 1);
      std::advance(result.second, 1);

      single_mismatch = (std::mismatch(result.first, endA, result.second).first == endA);
    }
  }
  return single_mismatch;
}

int main() {
    int t;
    cin>>t;
    
    vector<string> sv;
    while(t--) {
        string str;
        cin>>str;
        sv.push_back(str);
    }
    int count = 0;
    for(int i=0;i<sv.size();i++) {
        for(int j=i+1;j<sv.size();j++) {
            bool t = canChange(sv[i], sv[j]);
            if(t) count++;
        }
    }
    cout<<count;
}