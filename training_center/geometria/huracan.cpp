#include <bits/stdc++.h> 
using namespace std;

int main() {
	int x, y;
	vector<int> eje_x[101];
	while(cin >> x >> y){
		eje_x[x].push_back(y);
	}
	for(int i = 0; i < 101; i++){
		if(eje_x[i].size() > 0){
			sort(eje_x[i].begin(), eje_x[i].end()); 
			for (auto aux : eje_x[i]) 
        		cout << i << " " << aux << "\n";;
		}
	}
	return 0;
}