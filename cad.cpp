#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	string b = "CORRECTO";
	string m = "INCORRECTO";
	int n;
	cin>>n;
	cin.ignore();
	while(n){
		string parentesis;
		getline(cin, parentesis);
		stack<char> p;
		bool flag = false;
		for(int i = 0; i < parentesis.length(); i = i + 1){
			char aux_char = parentesis.at(i);
			if(aux_char == '('){
				p.push(aux_char);	
			}else{
				if(p.empty()){
					cout<<m<<endl;
					i = parentesis.length() + 2;
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