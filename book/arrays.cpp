#include <iostream>
using namespace std;

int main() {
	int n, m, i, j;
	cin >> n >> m;
	int x[n], dp[n][m + 1];
	for(i = 0; i < n; i++){
		cin >> x[i];
		dp[i][0] = 0;
	}
	if(x[0] == 0){
		for(j = 1; j <= m; j++){
			if(abs(x[1] - j) <= 1) dp[0][j] = 1 + dp[0][j-1];
			else dp[0][j] = dp[0][j-1];
		}		
	}else{		
		for(j = 1; j <= m; j++) dp[0][j] = 0;
	}
	for(i = 1; i < n; i++){
		for(j = 1; j <= m; j++){
			if(x[i] == 0){
				dp[i][j] = 0;
				if(abs(x[i-1] - j) <= 1 ){					
					dp[i][j] = 1 + dp[i-1][j] + dp[i][j-1];	
				}else{
					dp[i][j] = dp[i-1][j] + dp[i][j-1];	
				}				
			}else{				
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	cout << dp[n-1][m];
	return 0;
}













