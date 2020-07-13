#include <iostream>
using namespace std;
 
int main() {
	int t, a, b, c, d;
	cin >> t;
	while(t){
		cin >> a >> b;
		int adj[a][a];
		for(int i = 0; i < a; i++)
			for(int j = 0; j < a; j++)
				adj[i][j] = 0;
		while(b){
			cin >> c >> d;
			adj[c-1][d-1] = 1;
			adj[d-1][c-1] = 1;
			b--;
		}
		for(int i = 0; i < a; i++){
			for(int j = 0; j < a; j++){
				cout << adj[i][j];
			}
			cout << "\n";
		}
		t--;
	}
	return 0;
}