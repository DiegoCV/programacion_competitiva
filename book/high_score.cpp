#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int main() {
	int n, m, a, b, x, i, inf = -1e9;
	cin >> n >> m;
	vector<tuple<int, int, int>> edges;
	while(m){
		cin >> a >> b >> x;
		edges.push_back({a, b, x});
		m--;
	}
	int distance[n+1];
	for(i = 1; i <= n; i++) distance[i] = inf;
	distance[1] = 0;
	for(i = 1; i < n; i++){
		for(auto u: edges){
			tie(a, b, x) = u;
			distance[b] = max(distance[b], distance[a]+x);			
		}
	}
	cout << distance[n];
	return 0;
}