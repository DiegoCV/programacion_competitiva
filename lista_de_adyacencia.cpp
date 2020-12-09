#include <bits/stdc++.h> 
using namespace std;
 
int main() {
	int t, a, b, c, d;
	cin >> t;
	while(t){
		cin >> a >> b;
		vector<int> adj[a];
		while(b){
			cin >> c >> d;
			adj[c-1].push_back(d-1);
			adj[d-1].push_back(c-1);
			b--;
		}
		for(int i = 0; i < a; i++){
			 cout << i+1 << " ";
			 sort(adj[i].begin(), adj[i].end()); 
			for(int j = 0; j < adj[i].size(); j++){
				cout << adj[i][j] + 1;
			}
			cout << "\n";
		}
		t--;
	}
	return 0;
}