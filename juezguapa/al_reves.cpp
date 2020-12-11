#include <iostream>
using namespace std;

int revertir(int x){
	int aux = 0;
	while(x > 0){
		aux = aux * 10 + (x % 10);
		x = x / 10;
	}	
	return aux;
}

bool is_palindromo(int x){	
	return x == revertir(x);
}

int main() {
	int n, a, b, i, aux, limit = 1e6 + 2;
	int dp[limit];
	dp[0] = 0;
	dp[1] = 1;
	for(i = 2; i < limit; i++){
		dp[i] = dp[i-1];
		if (is_palindromo(i))
			dp[i] += 1;		
	}
	cin >> n;
	while(n){		
		cin >> a >> b;
		aux = dp[b] - dp[a];
		if(is_palindromo(a))
			aux++;
		cout << aux << endl;
		n--;
	}	
	return 0;
}