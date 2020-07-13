#include <iostream>
#include <string>
#include <list>
using namespace std;

int main() {
	int t, n;
	string word;
	list<string> words;
	cin>>t;
	while(t){
		cin>>n;
		cin.ignore();
		while(n){
			getline(cin, word);
			words.push_back(word);
			words.sort();
			n = n - 1;
		}
		while(!words.empty()){
			cout<<words.front()<<endl;
			words.pop_front();
		}
		cout<<'-'<<endl;
		t = t - 1;
	}
	// your code goes here
	return 0;
}