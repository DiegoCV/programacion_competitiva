#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, aux, aux_2;
	string cad_1, cad_2;
	cin>>N;
	while(N){
		cin>>cad_1;
		cin>>cad_2;
		aux = cad_2.size();
		aux_2 = 0;
		for(int i = 0; i < cad_1.size(); i = i + 1){
			if(aux > 0){
				cout<<cad_1.at(i)<<cad_2.at(i);
			}else{
				cout<<cad_1.at(i);
			}
			aux = aux - 1;
			aux_2 = aux_2 + 1;
		}
		if(aux > 0){
			cout<<cad_2.substr(aux_2,cad_2.size()-1);
		}
		cout<<"\n";
		N = N - 1;
	}
	return 0;
}