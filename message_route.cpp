#include <bits/stdc++.h> 

using namespace std;

int main() {
	int n, m, a, b, i;
	cin >> n >> m;
	vector<int> adj[n + 1];
	while(m){
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
		m--;
	}
	bool impossible = false;
	int islas = 0;
	bool visited[n+1]; memset(visited, false, n+1);
	int distance[n+1]; distance[1] = 0;
	int ancestor[n+1]; ancestor[1] = -1;
	queue<int> q; 
	for(i = 1; i <= n; i++){
		if(!visited[i]){
			q.push(i);
			islas++;
			while(!q.empty()){
				int s = q.front(); q.pop();
				if(s == n){
					if(islas > 1) impossible = true;
					break;
				}
				for(auto u: adj[s]){
					if(visited[u]) continue;
					visited[u] = true;
					distance[u] = distance[s] + 1;
					ancestor[u] = s;
					q.push(u);
				}
			}
		}				
	}
	
	if(impossible){
		cout << "IMPOSSIBLE";
	}else{
		cout << distance[n] + 1 << "\n";
		list<int> indices;
		i = n;
		while(i > 1){
			indices.push_front(i);
			i = ancestor[i];
		}
		indices.push_front(1);
		for (list<int>::iterator it=indices.begin(); it!=indices.end(); ++it)
    		cout << *it << ' ';
	}
	
	return 0;
}
