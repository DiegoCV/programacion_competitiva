#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int main() {
	int n, m, a, b, c, i, INF = 1e9 + 1;
	cin >> n >> m;
	vector<tuple<int, int, int>> edges;
	while(m){
		cin >> a >> b >> c;
		edges.push_back({a, b, c});
		m--;
	}
	int distance[n + 1];
	for(i = 2; i <= n; i++){
		distance[i] = INF;
	}
	distance[1] = 0;
	int flag = 0;
	for(i = 1; i < n; i++){
		flag = 0;
		for(auto e: edges){
			tie(a, b, c) = e;
			distance[b] = min(distance[b], distance[a] + c);
			if(distance[b] == INF) flag++;
		}
		if(flag == 0) break;
	}
	for(i = 1; i <= n; i++){
		cout << distance[i] << " ";
	}
	return 0;
}