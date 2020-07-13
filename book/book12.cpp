#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	string p, paux;
	char aux;
	int c[26], u;
	for(int i = 0; i < 26; i = i + 1){
		c[i] = 0;		
	}
	getline(cin,p);
	int r = p.size();
	for(int i = 0; i < r; i = i + 1){
		aux = p.at(i);
		c[aux - 97] += 1;
	}
	vector<string> cad;
	p = "";
	for(int i = 0; i < 26; i = i + 1){
		if( c[i] > 0){
			aux = i + 97;
			while(c[i]){
				p = p + aux;
				c[i] -= 1; 
			}
			cad.push_back(p);
			r = i;
			i = 28;
		}
	}

	for(int i = r + 1; i < 26; i = i + 1){
		if( c[i] > 1){
			aux = i + 97;
			r = cad.size();
			u = cad[0].size() + 1;
			vector<string> cadaux;
			string pp = "";
			while(c[i]){
				for(int j = 0; j < r; j = j + 1){
					paux = cad[j];
					for(int k = 0; k < u; k = k + 1){
						p = paux;
						p.insert(k,1,aux);
						int gg = cadaux.size();
						bool flag = true;
						for(int w = 0; w < gg; w = w + 1){
							if(cadaux[w]==p){
								flag = false;
								w = gg + 5;
							}
						}
						if(flag)cadaux.push_back(p);
					}
				}
				cad.clear();
				cad = cadaux;
				pp = "";
				cadaux.clear();
				r = cad.size();
				u = cad[0].size() + 1;
				c[i] -= 1;
			}
			
		}else if ( c[i] > 0){
			aux = i + 97;
			r = cad.size();
			vector<string> cadaux;
			//while(r){
				u = cad[0].size() + 1;
				for(int j = 0; j < r; j = j + 1){
					paux = cad[j];
					for(int k = 0; k < u; k = k + 1){
						p = paux;
						p.insert(k,1,aux);
						cadaux.push_back(p);
					}
				}
			//	r = r - 1;
			//}
			cad = cadaux;
		}
	}
	sort(cad.begin(), cad.end());
	r = cad.size();
	cout << r << "\n";
	for(int i = 0; i < r; i = i + 1){
		cout << cad[i] << "\n";
	}
	return 0;
}
