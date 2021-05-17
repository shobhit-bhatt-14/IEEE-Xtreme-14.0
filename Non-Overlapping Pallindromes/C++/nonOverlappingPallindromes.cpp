#include <bits/stdc++.h> 
using namespace std; 
#define N 10000 

void pre_process(bool ren[N][N], string s) 
{ 
	int n = s.size(); 

	for (int i = 0; i < n; i++) { 
		for (int j = 0; j < n; j++) 
			ren[i][j] = false; 
	} 

	for (int j = 1; j <= n; j++) { 

		for (int i = 0; i <= n - j; i++) { 

			if (j <= 2) { 

				if (s[i] == s[i + j - 1]) 
					ren[i][i + j - 1] = true; 
			} 

			else if (s[i] == s[i + j - 1]) 
				ren[i][i + j - 1] = ren[i + 1][i + j - 2]; 
		} 
	} 
} 

int countPairs(string s) 
{ 
	bool ren[N][N]; 
	pre_process(ren, s); 
	int n = s.length(); 

	int left[n]; 
	memset(left, 0, sizeof left); 

	int right[n]; 
	memset(right, 0, sizeof right); 

	left[0] = 1; 

	for (int i = 0; i < n; i++) { 

		left[i] = 1;
		for (int j = 0; j <= i; j++) { 

			if (ren[j][i] == 1 && i-j+1>left[i]) 
				left[i] = i-j+1;
		} 
	} 

	right[n - 1] = 0; 

	for (int i = n - 2; i >= 0; i--) { 

		right[i] = right[i+1];

		for (int j = n - 1; j > i; j--) { 

			if (ren[i+1][j] == 1 && j-i > right[i]) 
				right[i] = j-i; 
		} 
	} 

	int ans = 0; 

	for (int i = 0; i < n ; i++) 
	{
		if(left[i] + right[i] > ans && left[i]!=0 && right[i]!=0)
		ans = left[i] + right[i];
	}

	return ans; 
} 

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    cout << countPairs(s)<<"\n"; 
	}
	return 0; 
}
