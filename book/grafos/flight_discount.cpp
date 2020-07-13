#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <limits>

using namespace std;

int main() {
	int n, m, a, b, c, i, inf = numeric_limits<int>::max();
	cin >> n >> m;
	vector<pair<int, int>> adj[n+1];
	while(m){
		cin >> a >> b >> c;
		adj[a].push_back({b, c});
		m--:
	}
	int distance[n+1], antecessor[n+1];
	bool visited[n+1];	
	priority_queue<pair<int, int>> pq;
	distance[0] = 0;
	distance[1] = 0;
	visited[1] = false;	
	for(i = 2; i <= n; i++){ distance[i] = inf; visited = false};
	pq.push({0,1});
	while(!pq.empty()){
		a = pq.top(); pq.pop();
		if(visited[a]) continue;
		visited[a] = true;
		for(auto u: adj[a]){
			b = u.first; c = u.second;
			if(distance[a] + c < distance[b]){
				distance[b] = distance[a]+c;
				antecessor[b] = a;
				pq.push({-distance[b], b});
			}
		}
	}
	i = n;
	a = n;
	m = 0;
	queue<int> q; 
	while(i > 1){
		if(distance[i] > m){
			m = distance[i];
			a = i;
		}
		q.push(i);
		i = antecessor[i];		
	}
	m = distance[a] - distance[a-1];
	distance[a] = distance[a-1] + m/2;
	b = 0;
	while(!q.empty()){
		m = q.front(); q.pop();
		if(m >= a){
		  b += distance[m];
		}
	}		
	cout << b;
	return 0;
}


































