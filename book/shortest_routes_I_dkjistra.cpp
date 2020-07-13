#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits>
 
using namespace std;
 
int main() {
	int n, m, a, b, i;
	long long int w, INF = numeric_limits<long long int>::max();
	cin >> n >> m;
	vector<pair<int, long long int>> adj[n + 1];	
	while(m){
		cin >> a >> b >> w;
		adj[a].push_back(pair<int, long long int>(b, w));		
		m--;
	}
	priority_queue <pair<long long int, int>> q;
	long long int distance[n + 1];
	bool processed[n + 1];
	for(i = 2; i <= n; i++){
		distance[i] = INF;
		processed[i] = false;
	}
	distance[1] = 0;
	processed[1] = false;
	q.push({0,1});
	while(!q.empty()){
		a = q.top().second; q.pop();
		if(processed[a]) continue;
		processed[a] = true;
		for(auto u: adj[a]){
			b = u.first; w = u.second;
			if(distance[a]+w < distance[b]){
				distance[b] = distance[a]+w;
				q.push({-distance[b], b});
			}
		}
	}
	for(i = 1; i <= n; i++){
		cout << distance[i] << " ";
	}
	return 0;
}







