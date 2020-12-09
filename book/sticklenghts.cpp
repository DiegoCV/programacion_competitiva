#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

bool sortByVal(const pair<ll, ll> &a, const pair<ll, ll> &b) { 
    return (a.second < b.second); 
} 

int main() {
	int n, i;
	ll pi, aux, ii=0;
	cin >> n;
	map<ll, ll> mp;
	map<ll, ll>::iterator it;
	for(i = 0; i < n; i++){
		cin >> pi;
		it = mp.find(pi);
		if(it == mp.end()){
			mp.insert( pair<ll, ll>(pi, 1));
		}else{
			pi = it->second;
			it->second = pi + 1;
		}			
	}
	vector<pair<ll, ll>> vec;
	for (it = mp.begin(); it != mp.end(); it++) {
    	vec.push_back(make_pair(it->first, it->second));
	}
	sort(vec.begin(), vec.end(), sortByVal); 
	if(vec[vec.size()-1].second == 1){
		sort(vec.begin(), vec.end());
		pi = vec[(vec.size()/2) - 1].first;
	}else{
		pi = vec[vec.size()-1].first;
	}
	for (it = mp.begin(); it != mp.end(); it++) {
	   	aux = abs(pi - it->first) * it->second;
		ii = ii + aux;
	}
	cout << ii;
	return 0;
}