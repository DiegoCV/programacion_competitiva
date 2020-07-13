#include <iostream>
using namespace std;

int main() {
	int t,n,k,ti,fin;
	cin>>t;
	while(t){
		cin>>n>>k;
		fin = -1;
		for(int i = 0; i < n; i = i + 1){
			cin>>ti;
			if(ti <= fin){
				if(i == n-1){
					cout<<fin - ti + 1;
				}else{
					cout<<fin - ti + 1<<" ";
				}
				fin = fin + k;
			}else{
				if(i == n-1){
					cout<<0;
				}else{
					cout<<0<<" ";
				}
				fin = ti + k - 1;
			}
			//cout<<"--"<<fin<<"--";
		}
		cout<<endl;
		t = t - 1;
	}
	return 0;
}