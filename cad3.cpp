#include <iostream>
#include <list>
using namespace std;

int main() {
	int t,n;
	cin>>t;
	while(t){
		cin>>n;
		list<int> lista_b;
		for(int i = 0; i < n; i = i + 1){
			lista_b.push_back(i+1);
		}
		bool flag = false;
		while(!lista_b.empty()){
			if(flag){
				int aux_int = lista_b.front();
				lista_b.pop_front();
				lista_b.push_back(aux_int);
			}else{
				cout<<lista_b.front()<<endl;
				lista_b.pop_front();
			}
			flag = !flag;
		}
		cout<<'-'<<endl;
		t = t - 1;
	}
	return 0;
}