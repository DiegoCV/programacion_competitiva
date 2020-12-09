#include <iostream>
using namespace std;

int main() {
	int n, x, i, j, left;
	cin >> n >> x;
	int h[n], s[n], dp[n+1][x + 1];
	for(i = 0; i < n; i++){
		cin >> h[i];
		dp[i][0] = 0;
	}
	for(i = 0; i < n; i++)
		cin >> s[i];
	for(j = 0; j <= x; j++){
		dp[0][j] = 0;
	}
	for(i = 1; i <= n; i++){
		for(j = 0; j <= x; j++){
			dp[i][j] = dp[i-1][j];
    		left = j-h[i-1];
    		if (left >= 0) {
				dp[i][j] = max(dp[i][j], dp[i-1][left]+s[i-1]);
			}
		}
	}
		cout << dp[n][x];
	return 0;
}
