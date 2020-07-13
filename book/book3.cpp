#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	string dna;
	int max = 1, act = 1;
	getline(cin,dna);
	for(int i = 1; i < dna.size(); i = i + 1){
		if(dna.at(i) == dna.at(i-1)) act = act + 1;
		else act = 1;
		if(act > max) max = act;
	}
	cout<<max;
	return 0;
}