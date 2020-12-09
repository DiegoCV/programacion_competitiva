#include <bits/stdc++.h>
using namespace std;

string f(int i, char a, string h){
	if(i == 1) return h + a;
	if(i & 1){
		string t = f(i/2, a, "");
		h = t + t + a;	
	}else{
		string t = f(i/2, a, "");
		h = t + t;
	}
	return h;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	string p;
	char aux;
	long long c[26], d = 0, e = -1;
	for(int i = 0; i < 26; i = i + 1){
		c[i] = 0;		
	}
	getline(cin,p);
	int r = p.size();
	for(int i = 0; i < r; i = i + 1){
		aux = p.at(i);
		c[aux - 65] += 1;
	}
	
	for(int i = 0; i < 26; i = i + 1){
		if(c[i] & 1) {
			d += 1;
			c[i] -= 1;
			e = i;
		}	
	}
	
	p = "";
	
	if(d == 1 && (r & 1)){
		aux = e + 65;
		p = p + aux;
			
	} else if(d > 1){
		cout << "NO SOLUTION" <<"\n";
		return 0;
	}
	
	for(int i = 0; i < 26; i = i + 1){
		if(c[i] > 0){
			aux = i + 65;	
			string h = f(c[i]/2, aux, "");
			p = h + p + h;
		}
	}
	 cout << p <<"\n";
	
	return 0;
}











