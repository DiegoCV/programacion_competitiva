#include <bits/stdc++.h>
using namespace std;

int main() {
	int MAX = 1e9 + 2;
	int dp[MAX];
	int N, Q, ai, i, j, ini, fin;
	while(cin>>N>>Q){
		memset(dp, 0, MAX);
		for(i = 1; i <= N; i = i + 1){
			cin>>ai;
			dp[ai]++;
		}
		for(i = 1; i <= Q; i = i + 1){
			cin>>ini>>fin;
			N=0;
			for(j = ini; ini <= fin; ini++){
				N+=dp[ini]; 
			}
			cout<<N<<"\n";
		}
	}
	return 0;
}