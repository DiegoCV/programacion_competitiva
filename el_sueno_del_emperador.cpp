#include <bits/stdc++.h> 

using namespace std;

int const MAX_N = 30 + 1;
vector<int> adj[MAX_N];
bool visited[MAX_N];

void dfs(int s){
	if(visited[s]) return;
	visited[s] = true;
	for(auto u: adj[s]) dfs(u);		
}

int main() {
	int t, n, m, a, b, cant_islas;	
	cin >> t;
	while(t){			
		cant_islas = 0;
		cin >> n >> m;
		for(int i = 0; i <= n; i++)adj[i].clear();		
		while(m){
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
			m--;
		}
		memset(visited, false, MAX_N);
		for(int i = 1; i <= n; i++){
			if(!visited[i]){
				cant_islas++;			
				dfs(i);			
			}
		}	
		cout << "El sueno del emperador se ha roto en " << cant_islas << " partes" << "\n";
		t--;
	}	
	return 0;
}
