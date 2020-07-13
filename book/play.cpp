#include <iostream>
#include <map>
#include <vector>
 
using namespace std;
 
int main() {
	int n, i, j, ki, max_songs = 0, max_here = 0;
	cin >> n;
	map<int, int> mp;
	map<int, int>::iterator it;
	vector<int> er;
	for(i = 0; i < n; i++){
		cin >> ki;
		it = mp.find(ki);
		if(it == mp.end()){
			mp.insert( pair<int, int>(ki, i));
			max_here += 1;
			er.push_back(ki);
		}else{
			if(max_here > max_songs) max_songs = max_here;
			max_here = i - it->second;
			for(j = 0; j < er.size(); j++){
				if(er[j] == ki){
					mp.erase(er[j]);
					break;
				}else{
					mp.erase(er[j]);
				}					
			}			
			er.erase(er.begin(), er.begin()+j+1);
			mp.insert( pair<int, int>(ki, i));
			er.push_back(ki);
		}
	}
	if(max_songs == 0 || max_here > max_songs ) max_songs = max_here;
	cout << max_songs;
	return 0;
}