#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n, aux;
	long long sum = 0;
	cin>>n;
	for(int i = 0; i < n-1; i = i + 1){
		cin>>aux;
		sum = sum + aux;
	}
	cout<<((n*(n+1))/2)-sum;
	return 0;
}