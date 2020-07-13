#include <iostream>
#include <limits>
 
using namespace std;
 
int main() {
	int n, m, q, a, b, c, i, j;
	cin >> n >> m >> q;
	long long int dist[n + 1][n + 1], INF = numeric_limits<long long int>::max();
	for( i = 0; i <= n; i++){
		for(j = 0; j <= n; j++){
			if(i == j) dist[i][j] = 0;
			else dist[i][j] = INF;
		}
	}
	while(m){
		cin >> a >> b >> c;
		if(c < dist[a][b]){ 
			dist[a][b] = c;
			dist[b][a] = c;		
		}
		m--;
	}	
	for(int k = 1; k <= n; k++){
		for( i = 1; i <= n; i++){
			for(j = 1; j <= n; j++){
					if(dist[i][k] + dist[k][j] >= 0) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
					else dist[i][j] = min(dist[i][j], INF);
			}
		}
	}
	while(q){
		cin >> a >> b;		
		if(dist[a][b] == INF) cout << -1 << endl;
		else cout << dist[a][b] << endl;
		q--;
	}
	return 0;
}