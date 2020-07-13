#include <bits/stdc++.h> 

using namespace std;

int main() {
	int n, m, a, b, i, cant_islas = 0;
	cin >> n >> m;
	vector<int> adj[n+1];				
	while(m){
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
		m--;
	}
	bool visited[n+1]; memset(visited, false, n+1);
	queue<int> q;
	vector<int> islas;
	for(i = 1; i <= n; i++){
		if(!visited[i]){
			q.push(i);
			islas.push_back(i);
			cant_islas++;
			while(!q.empty()){
				int s = q.front(); q.pop();
				for(auto u: adj[s]){
					if(visited[u]) continue;
					visited[u] = true;
					q.push(u);
				}
			}
		}
	}
	cant_islas--;
	cout << cant_islas << "\n";	
	if(cant_islas > 0){
		for(i = 0; i <= cant_islas-1; i++){
			cout << islas[i] << " " << islas[i + 1] << "\n";						
		}
	}	
	return 0;
}
