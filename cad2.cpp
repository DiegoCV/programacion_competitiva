#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	string b = "CORRECTO";
	string m = "INCORRECTO";
	int n, t;
	cin>>n;
	//cin.ignore();
	while(n){
		cin>>t;
		char parentesis[t];
		for(int i = 0; i < t; i = i + 1){
			cin>>parentesis[i];
		}
		stack<char> p;
		int l = sizeof(parentesis)/sizeof(*parentesis);
		bool flag = false;
		for(int i = 0; i < l; i = i + 1){
			char aux_char = parentesis[i];
			if(aux_char == '1'){
				p.push(aux_char);	
			}else{
				if(p.empty()){
					cout<<m<<endl;
					i = l + 2;
					flag = true;
				}else{
					p.pop();
				}
			}
		}
		if(!flag){
			if(p.empty()){
				cout<<b<<endl;
			}else{
				cout<<m<<endl;
			}
		}
		n = n - 1;
	}
	
	// your code goes here
	return 0;
}