#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	long long y, x;
	cin >> t;
	while(t){
		cin >> y >> x;
		if( y >= x){
			if( y & 1 ){ //odd
				y = y - 1;
				y = (y * y) + 1;
				y = y + x - 1;
			}else{ //even
				y = y * y;
				y = y - x + 1;
			}
			cout << y << "\n";
		}else{
			if( x & 1 ){ //odd
				x = x * x;
				x = x - y + 1;
			}else{//even
				x = x - 1;
				x = (x * x) + 1;
				x = x + y - 1;
			}
			cout << x << "\n";
		}
		t = t - 1;
	}
	return 0;
}








