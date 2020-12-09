#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int n, m, a, b;
	cin >> n >> m;
	vector<int> adj[n + 1];
	while(m){
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
		m--;
	}
	bool impossible = false;
	bool visited[n+1]={false};
	int teams[n+1]; for(int i = 1; i < n + 1; i++) teams[i] = -1;
	queue<int> q;
	int t;
	for(int i=1; i <= n; i++){
		if(!visited[i]){
			q.push(i);
			visited[i] = true;
			t = 1;
			while(!q.empty()){
				int s = q.front(); q.pop();
				if(teams[s] == -1) teams[s] = t;
				else t = teams[s];
				if(t == 1) t = 2;
				else t = 1;
				for(auto u: adj[s]){
					if(visited[u]){
						if(visited[u] && teams[s] == teams[u]){
							impossible = true;
							break;
						}else{
					 		continue;
						}
					}
					visited[u] = true;
					teams[u] = t;
					q.push(u);
				}
				t = 1;
				if(impossible) break;
			}
			if(impossible) break;
		}
	}
	if(impossible){
		cout << "IMPOSSIBLE";
	}else{
		for(int i = 1; i < n + 1; i++)
			cout << teams[i] << " ";
	}
	
	return 0;
}