#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	long long a, b;
	cin >> t;
	while(t){
		cin >> a >> b;
		if(a<b) swap(a,b);
		if(a > 2*b){
			cout<<"NO" << endl;		
		}else if( ( a + b ) % 3 == 0 ){
			cout << "YES" << "\n";
		} else {
			cout << "NO" << "\n";
		}
		t = t - 1;
	}
	return 0;
}