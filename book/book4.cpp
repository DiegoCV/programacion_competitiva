#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	long long xi, xh, sum = 0;
	cin>>n;
	cin>>xh;
	for(int i = 1; i < n; i = i + 1){
		cin>>xi;
		if(xi < xh)	sum = sum + (long long)(xh - xi);
		else xh = xi;	
	}
	cout<<sum;
	return 0;
}