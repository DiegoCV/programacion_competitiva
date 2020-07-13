#include <iostream>
using namespace std;

int const MAX = 1e6 + 1;
int const MOD = 1e9 + 7;
int dp[MAX];

int f(int i){
	if(i <= 0) return 0;
	if(i == 1) return 1;
	if(dp[i] != -1) return dp[i];
	dp[i] = (2%MOD * (f(i - 1)%MOD))%MOD;
	return dp[i];
}

int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n + 1; i++){
		dp[i] = -1;
	}
	dp[0] = 0;
	dp[1] = 1;
	cout << f(n);
	return 0;
}