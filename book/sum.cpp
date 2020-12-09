#include <iostream>
#include <map>
#include <utility>
using namespace std;

int main() {
	int n, x, ai, aux;
	bool flag = true; 
	cin >> n >> x;
	map<int, int> mp;
	map<int, int>::iterator it;
	for(int i = 1; i <= n; i++){
		cin >> ai;
		aux = x - ai;
		it = mp.find(aux);
		if (it != mp.end()){
			cout << it->second << " " << i;
			flag = false;
			break;
		}else if (aux >= 0){
			mp.insert (pair<int, int>(ai, i));
		}
	}
	if(flag)
		cout << "IMPOSSIBLE";
	return 0;
}