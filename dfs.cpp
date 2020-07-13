#include <bits/stdc++.h>
using namespace std;

const int N = 10; 
vector<int> g[N];
bool vis[N];

void dfs(int u){
	vis[u] = true;
	cout<<u<<" -> ";
	for(int &v: g[u]){
		if(!vis[v]){
			dfs(v);
		}
	}
	
}

void dfs_iterativo(int u){
	stack<int> stack;
	stack.push(u);
	while(!stack.empty()){
		u = stack.top(); 
        stack.pop();
        if(!vis[u]){
        	vis[u] = true;
        	cout<<u<<" -> ";
        	for (int &v : g[u]){
        		if (!vis[v]){
        			stack.push(v);		
        		} 
        	} 
        }
	}
}

int main() {
	int n, a;
	cin>>n>>a;
	for(int i = 0; i < n; i = i + 1){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(0);
	dfs_iterativo(0);
	
	
	/*for(int u = 0; u < n; u = u + 1){
		cout<<u<<" -> ";
		for(int &v : g[u]){
			cout<<v<<" ";
		}
		cout<<endl;
	}*/
	return 0;
}