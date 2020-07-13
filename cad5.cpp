#include <iostream>
#include <list>
using namespace std;

int main() {
	int t, n, aux_int;
	list<int> nums;
	cin>>t;
	while(t){
		cin>>n;
		while(n){
			cin>>aux_int;
			nums.push_back(aux_int);
			nums.sort();
			nums.unique();
			n = n - 1;
		}
		while(!nums.empty()){
			cout<<nums.front()<<endl;
			nums.pop_front();
		}
		cout<<'-'<<endl;
		t = t - 1;
	}
	// your code goes here
	return 0;
}