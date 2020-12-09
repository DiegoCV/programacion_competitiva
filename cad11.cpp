#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int t, n, k, h, res, aux_int, aux_int_2;
	cin>>t;
	while(t){
		cin>>n;
		aux_int = n;
		res = 0;
		while(n > 0){
			k = log2(n);
			h = pow(2,k);
			aux_int_2 = n / h;
			res = res + aux_int_2;
			n = n - (h * aux_int_2);
		}
		cin>>k>>h;
		cout<<(aux_int*k)+(h*res)<<endl;
		t = t - 1;
	}
	return 0;
}