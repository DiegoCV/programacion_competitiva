#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <bits/stdc++.h> 

using namespace std;

int const MAX_N = 100 + 1;
vector<pair< int, int>> adj[MAX_N];
bool visited[MAX_N];

int dfs(int i, int j, int h){
	if(visited[i]) return -1;
	if (i == j) return h;
	visited[i] = true;
	vector<int> m;	
	for(auto u: adj[i]){
		if(visited[u.first])continue;
		m.push_back(max(dfs(u.first, j, u.second), h));		
	}
	sort(m.begin(), m.end());	
	return m[0];
}

int main() {
	int n, m, i, j, h, k, mayor, x = 1;
	while(cin >> n >> m){			
		while(m){
			cin >> i >> j >> h;
			adj[i].push_back(make_pair(j,h));
			adj[j].push_back(make_pair(i,h));
			m--;
		}
		cin >> k;
		cout << "Instancia " << x << "\n";
		while(k){
			cin >> i >> j;
			memset(visited, false, n); 		
			cout << dfs(i, j) << "\n";
			k--;
		}
		x++;
	}
	
	return 0;
}











